/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */

#include <string.h>
#include "cortex/cortex.h"
#include "cortex/profile.h"
#include <assert.h>
#include <libgen.h>

comm_info_t* cortex_lookup(cortex_dumpi_profile* profile, dumpi_comm prm_comm)
{
    int wrank = profile->rank; // world rank
    GHashTable* hash = profile->hash_tables[wrank];
	int key = prm_comm;
    comm_info_t* comm = (comm_info_t*)g_hash_table_lookup(hash, GINT_TO_POINTER(key));
    assert(comm);
	// printf("\n comm.id: %d", comm->id);
	// printf("\n comm.size: %d", comm->size);
    return comm;
}

void iterator(gpointer key, gpointer value, gpointer user_data) {
	printf("id: %d\n", key);
	comm_info_t* comm = (comm_info_t*)value;
	printf("comm.id: %d\n", comm->id);
	printf("comm.size: %d\n", comm->size);
	printf("comm.wtol:\n");
	for (int i=0; i<comm->size; i++) {
		printf("    %d -> %d\n", i, comm->wtol[i]);
	}
	printf("comm.ltow:\n");
	for (int i=0; i<comm->size; i++) {
		printf("    %d -> %d\n", i, comm->ltow[i]);
	}
	printf("\n");
}

cortex_dumpi_profile* cortex_undumpi_open(const char* fname, job_id_t job_id, size_t world_size, rank_t world_rank) {
	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)malloc(sizeof(cortex_dumpi_profile));
	printf("\n");
	printf("\n cortex_undumpi_open: %s", fname);

	if(fname) {
		profile->dumpi = undumpi_open(fname);
		if(profile->dumpi == NULL) {
			free(profile);
			return NULL;
		}
		profile->active = 1;
	} else {
		profile->dumpi = NULL;
		profile->active = 0;
	}

	profile->first_pending = NULL;
	profile->last_pending = NULL;
	profile->nprocs = world_size;
	profile->rank = world_rank;
	profile->job_id = job_id;
	profile->comms = NULL;
	profile->dtypes = NULL;

	// initializes the communicators
	cortex_comm_add(profile, 2, world_size);

	// initializes the datatypes
	if(profile->dumpi) {
		dumpi_sizeof datatype_sizes = undumpi_read_datatype_sizes(profile->dumpi);
		int i;
		for(i=0; i < datatype_sizes.count; i++) {
			cortex_datatype_add(profile, i, datatype_sizes.size[i]);
		}
		free(datatype_sizes.size);
	}

	// initialize the topology
	memset(&(profile->topology),0,sizeof((profile->topology)));

	// initialize the placement information
	profile->placement = (uint32_t*)malloc(sizeof(uint32_t)*(profile->nprocs));
	memset(profile->placement,0,sizeof(uint32_t)*(profile->nprocs));

	// initialize hash table
	profile->hash_tables = (GHashTable**)malloc(sizeof(GHashTable*)*world_size);
	for (int i=0; i<world_size; i++) {
		GHashTable* hash = g_hash_table_new(g_direct_hash, g_direct_equal);
		profile->hash_tables[i] = hash;
	}

	// populate hash table
	char *dirc, *dname, commfile[255];
	dirc = strdup(fname);
	dname = dirname(dirc);
	sprintf(commfile, "%s/dumpi_comms.dat", dname);
	FILE* fp = fopen(commfile, "r");
	if (fp==NULL) perror ("\n Error opening file: dumpi_comms.dat");

	char buf[1024];
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		int rank, key, global_id, size, i, wrank, pos, inc;
		sscanf(buf, "%d %d %d%n", &rank, &key, &size, &pos);
		//printf("rank, key, size= %d %d %d:", rank, key, size);

		comm_info_t *subcomm = malloc(sizeof(comm_info_t));
		subcomm->id = key;
		subcomm->size = size;

		// set local-to-world map first
		for (i=0; i<size; i++)
		{
			sscanf(buf+pos, "%d%n", &wrank, &inc);
			//printf(" %d", wrank);
			subcomm->ltow[i] = wrank;
			pos += inc;
		}
		sscanf(buf+pos, "%d%n", &global_id, &inc);
		subcomm->global_id = global_id;
		//printf("\n", wrank);

		// set world-to-local
		for (i=0; i<size; i++)
		{
			wrank = subcomm->ltow[i];
			subcomm->wtol[wrank] = i;
		}

		GHashTable* hash = profile->hash_tables[rank];
		g_hash_table_insert(hash, GINT_TO_POINTER(key), subcomm);
	}

	/*
	for (int i=0; i<world_size; i++) {
		GHashTable* hash = profile->hash_tables[i];
		g_hash_table_foreach(hash, (GHFunc)iterator, NULL);
	}
	*/

	return profile;
}

void cortex_undumpi_close(cortex_dumpi_profile* profile) {
	if(profile->dumpi)
		undumpi_close(profile->dumpi);
	cortex_comm_delete_all(profile);
	free(profile->placement);
	free(profile);
}

int cortex_dumpi_start_stream_read(cortex_dumpi_profile *profile) {
	if(profile->dumpi) {
		return dumpi_start_stream_read(profile->dumpi);
	} else {
		return 0;
	}
}

dumpi_header* cortex_undumpi_read_header(cortex_dumpi_profile* profile) {
	if(profile->dumpi)
		return undumpi_read_header(profile->dumpi);
	else
		return NULL;
}
 
int cortex_undumpi_read_single_call(cortex_dumpi_profile *profile,
			       struct libundumpi_cbpair *callarr,
			       struct libundumpi_cbpair *translations,
			       void *userarg,
			       int *mpi_finalized) {
	if(cortex_has_operation(profile)) {
		cortex_exec(profile, callarr, userarg, mpi_finalized);
	} else {
		if(profile->active) {
			int dummy = 0;
			profile->active = undumpi_read_single_call(profile->dumpi, translations, (void*)profile, &dummy);
			if(cortex_has_operation(profile)) {
				cortex_exec(profile, callarr, userarg, mpi_finalized);
			}
		}
	}
	return profile->active || cortex_has_operation(profile);
}

int cortex_undumpi_read_stream_full(cortex_dumpi_profile* profile,
                          const libundumpi_callbacks *callback,
			  const libundumpi_callbacks *translations,
                          void *userarg,
                          bool print_progress, // TODO not supported yet
                          double percent_terminate) // TODO not supported yet
{
	libundumpi_cbpair user_callarr[DUMPI_END_OF_STREAM];
	memset(&user_callarr, 0, sizeof(libundumpi_cbpair) * DUMPI_END_OF_STREAM);
	libundumpi_populate_callbacks(callback, user_callarr);

	libundumpi_cbpair translation_callarr[DUMPI_END_OF_STREAM];
	memset(&translation_callarr, 0, sizeof(libundumpi_cbpair) * DUMPI_END_OF_STREAM);
	libundumpi_populate_callbacks(translations, translation_callarr);

	int mpi_finalized = 0;
	int active = 1;
	while(active) {
		active = cortex_undumpi_read_single_call(profile, user_callarr, translation_callarr, (void*)profile, &mpi_finalized);
		while(cortex_has_operation(profile)) {
			cortex_exec(profile, user_callarr, userarg, &mpi_finalized);
		}
	}
	return 1;
}

int cortex_undumpi_read_stream(cortex_dumpi_profile* profile,
                          const libundumpi_callbacks *callback,
			  const libundumpi_callbacks *translations,
                          void *userarg) 
{
	return cortex_undumpi_read_stream_full(profile,callback,translations,userarg,false,-1);
}

dumpi_keyval_record* cortex_undumpi_read_keyval_record(cortex_dumpi_profile* profile)
{
	if(profile->dumpi)
		return undumpi_read_keyval_record(profile->dumpi);
	else
		return NULL;
}

dumpi_footer* cortex_undumpi_read_footer(cortex_dumpi_profile* profile)
{
	if(profile->dumpi)
		return undumpi_read_footer(profile->dumpi);
	else
		return NULL;
}

dumpi_sizeof cortex_undumpi_read_datatype_sizes(cortex_dumpi_profile *profile)
{
	if(profile->dumpi)
		return undumpi_read_datatype_sizes(profile->dumpi);
	else {
		dumpi_sizeof s = { .count = 0, .size = NULL };
		return s;
	}
}


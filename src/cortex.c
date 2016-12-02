/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */

#include <string.h>
#include "cortex/cortex.h"
#include "cortex/profile.h"

cortex_dumpi_profile* cortex_undumpi_open(const char* fname, job_id_t job_id, size_t world_size, rank_t world_rank) {
	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)malloc(sizeof(cortex_dumpi_profile));

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

	cortex_comm_add(profile, 2, world_size);

	return profile;
}

void cortex_undumpi_close(cortex_dumpi_profile* profile) {
	if(profile->dumpi)
		undumpi_close(profile->dumpi);
	cortex_comm_delete_all(profile);
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


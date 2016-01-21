/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */

#include <string.h>
#include "cortex/cortex.h"

cortex_dumpi_profile* cortex_undumpi_open(const char* fname) {
	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)malloc(sizeof(cortex_dumpi_profile));
	profile->dumpi = undumpi_open(fname);
	if(profile->dumpi == NULL) {
		free(profile);
		return NULL;
	}
	libundumpi_callbacks cbacks;
	memset(&cbacks,0,sizeof(cbacks));
	cortex_set_callbacks(&cbacks);
	libundumpi_populate_callbacks(&cbacks, profile->callarr);
	return profile;
}

void cortex_undumpi_close(cortex_dumpi_profile* profile) {
	undumpi_close(profile->dumpi);
	free(profile);
}

int cortex_dumpi_start_stream_read(cortex_dumpi_profile *profile) {
	return dumpi_start_stream_read(profile->dumpi);
}

dumpi_header* cortex_undumpi_read_header(cortex_dumpi_profile* profile) {
	return undumpi_read_header(profile->dumpi);
}
 
int cortex_undumpi_read_single_call(cortex_dumpi_profile *profile,
			       struct libundumpi_cbpair *callarr,
			       void *userarg,
			       int *mpi_finalized) {
	if(cortex_has_operation(profile)) {
		cortex_exec(profile, callarr, userarg, mpi_finalized);
	} else {
		profile->active = undumpi_read_single_call(profile->dumpi, profile->callarr, (void*)profile, mpi_finalized);
		if(cortex_has_operation(profile)) {
			cortex_exec(profile, callarr, userarg, mpi_finalized);
		}
	}
	return profile->active || cortex_has_operation(profile);
}

int cortex_undumpi_read_stream_full(cortex_dumpi_profile* profile,
                          const libundumpi_callbacks *callback,
                          void *userarg,
                          bool print_progress, // TODO non-supported yet
                          double percent_terminate) // TODO non-supported yet
{
	libundumpi_cbpair user_callarr[DUMPI_END_OF_STREAM];
	memset(&user_callarr, 0, sizeof(libundumpi_cbpair) * DUMPI_END_OF_STREAM);
	libundumpi_populate_callbacks(callback, user_callarr);

	int mpi_finalized = 0;
	int active = 1;
	while(active) {
		active = cortex_undumpi_read_single_call(profile, user_callarr, (void*)profile, &mpi_finalized);
		while(cortex_has_operation(profile)) {
			cortex_exec(profile, user_callarr, userarg, &mpi_finalized);
		}
	}
	return 1;
}

int cortex_undumpi_read_stream(cortex_dumpi_profile* profile,
                          const libundumpi_callbacks *callback,
                          void *userarg) 
{
	return cortex_undumpi_read_stream_full(profile,callback,userarg,false,-1);
}

dumpi_keyval_record* cortex_undumpi_read_keyval_record(cortex_dumpi_profile* profile)
{
	return undumpi_read_keyval_record(profile->dumpi);
}

dumpi_footer* cortex_undumpi_read_footer(cortex_dumpi_profile* profile)
{
	return undumpi_read_footer(profile->dumpi);
}

dumpi_sizeof cortex_undumpi_read_datatype_sizes(cortex_dumpi_profile *profile)
{
	return undumpi_read_datatype_sizes(profile->dumpi);
}


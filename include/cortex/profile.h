/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef CORTEX_PROFILE_H
#define CORTEX_PROFILE_H

#include <dumpi/libundumpi/bindings.h>
#include <dumpi/libundumpi/libundumpi.h>
#include <cortex/operation.h>
//#include <cortex/dragonfly.h>

#ifdef __cplusplus
extern "C" {
#endif

struct cortex_operation; // forward declaration
struct cortex_comm; // forward declaration
struct cortex_datatype; // forward declaration

typedef int16_t job_id_t;
typedef int32_t  rank_t;

typedef struct cortex_dumpi_profile {
	dumpi_profile* dumpi; /* internal dumpi profile */
//	libundumpi_cbpair callarr[DUMPI_END_OF_STREAM]; /* same callbacks in the form of an array */
	int active; /* stores the result of the last call to cortex_undumpi_read_single_call */

	struct cortex_operation* first_pending;
	struct cortex_operation* last_pending;

	job_id_t job_id; /* job id */
	size_t nprocs; /* size of MPI_COMM_WORLD */
	rank_t rank; /* rank of this process in MPI_COMM_WORLD */

	struct cortex_comm* comms; /* hash table for the communicators */
	struct cortex_datatype* dtypes; /* hash table for the datatypes */
} cortex_dumpi_profile;

#ifdef __cplusplus
}
#endif

#endif

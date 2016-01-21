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

struct cortex_operation; // forward declaration

typedef struct cortex_dumpi_profile {
	dumpi_profile* dumpi; /* internal dumpi profile */
	libundumpi_cbpair callarr[DUMPI_END_OF_STREAM]; /* same callbacks in the form of an array */
	int active; /* stores the result of the last call to cortex_undumpi_read_single_call */

	struct cortex_operation* first_pending;
	struct cortex_operation* last_pending;
} cortex_dumpi_profile;

#endif

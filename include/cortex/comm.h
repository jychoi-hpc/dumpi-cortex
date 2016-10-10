/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef CORTEX_COMM_H
#define CORTEX_COMM_H

#include <dumpi/libundumpi/bindings.h>
#include <dumpi/libundumpi/libundumpi.h>
#include <cortex/cortex.h>
#include <uthash/uthash.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cortex_comm {
	dumpi_comm handle;
	unsigned int size;
	UT_hash_handle hh;
} cortex_comm;

int cortex_comm_add(cortex_dumpi_profile* profile, dumpi_comm comm, int size);

cortex_comm* cortex_comm_find(cortex_dumpi_profile* profile, dumpi_comm comm);

void cortex_comm_delete(cortex_dumpi_profile* profile, dumpi_comm comm);

void cortex_comm_delete_all(cortex_dumpi_profile* profile);

int cortex_comm_get_size(cortex_dumpi_profile* profile, dumpi_comm, int* size);

int cortex_comm_dup(cortex_dumpi_profile* profile, dumpi_comm oldc, dumpi_comm newc);

#ifdef __cplusplus
}
#endif

#endif

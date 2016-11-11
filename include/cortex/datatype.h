/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef CORTEX_DATATYPE_H
#define CORTEX_DATATYPE_H

#include <dumpi/common/types.h>
#include <dumpi/common/constants.h>
#include <cortex/cortex.h>
#include <uthash/uthash.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cortex_datatype {
	dumpi_datatype handle;
	unsigned int size;
	UT_hash_handle hh;
} cortex_datatype;

int cortex_datatype_add(cortex_dumpi_profile* profile, dumpi_datatype dt, int size);

cortex_datatype* cortex_datatype_find(cortex_dumpi_profile* profile, dumpi_datatype dt);

void cortex_datatype_delete(cortex_dumpi_profile* profile, dumpi_datatype dt);

void cortex_datatype_delete_all(cortex_dumpi_profile* profile);

int cortex_datatype_get_size(cortex_dumpi_profile* profile, dumpi_datatype dt);

int cortex_datatype_dup(cortex_dumpi_profile* profile, dumpi_datatype olddt, dumpi_datatype newdt);

#ifdef __cplusplus
}
#endif

#endif

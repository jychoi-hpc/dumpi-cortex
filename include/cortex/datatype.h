/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef CORTEX_DATATYPE_H
#define CORTEX_DATATYPE_H

#include <dumpi/common/types.h>
#include <dumpi/common/constants.h>

#ifdef __cplusplus
extern "C" {
#endif

struct cortex_datatype; // forward declaration
struct cortex_dumpi_profile; // forward declaration

int cortex_datatype_add(struct cortex_dumpi_profile* profile, dumpi_datatype dt, int size);

struct cortex_datatype* cortex_datatype_find(struct cortex_dumpi_profile* profile, dumpi_datatype dt);

void cortex_datatype_delete(struct cortex_dumpi_profile* profile, dumpi_datatype dt);

void cortex_datatype_delete_all(struct cortex_dumpi_profile* profile);

int cortex_datatype_get_size(struct cortex_dumpi_profile* profile, dumpi_datatype dt);

int cortex_datatype_dup(struct cortex_dumpi_profile* profile, dumpi_datatype olddt, dumpi_datatype newdt);

#ifdef __cplusplus
}
#endif

#endif

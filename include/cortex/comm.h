/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef CORTEX_COMM_H
#define CORTEX_COMM_H

#include <dumpi/libundumpi/bindings.h>
#include <dumpi/libundumpi/libundumpi.h>

#ifdef __cplusplus
extern "C" {
#endif

struct cortex_comm;
struct cortex_dumpi_profile; // forward declaration

int cortex_comm_add(struct cortex_dumpi_profile* profile, dumpi_comm comm, int size);

struct cortex_comm* cortex_comm_find(struct cortex_dumpi_profile* profile, dumpi_comm comm);

void cortex_comm_delete(struct cortex_dumpi_profile* profile, dumpi_comm comm);

void cortex_comm_delete_all(struct cortex_dumpi_profile* profile);

int cortex_comm_get_size(struct cortex_dumpi_profile* profile, dumpi_comm, int* size);

int cortex_comm_dup(struct cortex_dumpi_profile* profile, dumpi_comm oldc, dumpi_comm newc);

#ifdef __cplusplus
}
#endif

#endif

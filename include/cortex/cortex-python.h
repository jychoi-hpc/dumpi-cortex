/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef DUMPI_CORTEX_PYTHON_H
#define DUMPI_CORTEX_PYTHON_H

#include <dumpi/libundumpi/libundumpi.h>

#ifdef __cplusplus
extern "C" {
#endif

int cortex_python_set_module(const char* module, const char* class_name);

extern const libundumpi_callbacks* CORTEX_PYTHON_TRANSLATION;

#ifdef __cplusplus
}
#endif

#endif

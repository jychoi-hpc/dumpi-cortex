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

typedef struct cortex_dumpi_profile cortex_dumpi_profile;

int cortex_python_set_module(const char* module, const char* class_name);

int cortex_python_call_generator(cortex_dumpi_profile* profile, const char* fun_name);

extern const libundumpi_callbacks* CORTEX_PYTHON_TRANSLATION;

#ifdef __cplusplus
}
#endif

#endif

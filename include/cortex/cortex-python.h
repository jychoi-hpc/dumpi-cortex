/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef DUMPI_CORTEX_PYTHON_H
#define DUMPI_CORTEX_PYTHON_H

#include <dumpi/libundumpi/libundumpi.h>
#include <cortex/python-callbacks.h>

#ifdef __cplusplus
extern "C" {
#endif

int cortex_python_set_module(const char* module, const char* class_name);

#ifdef __cplusplus
}
#endif

#endif

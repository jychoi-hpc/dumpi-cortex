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

int cortex_datatype_get_size(dumpi_datatype dt);

#ifdef __cplusplus
}
#endif

#endif

/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef CORTEX_PLACEMENT_H
#define CORTEX_PLACEMENT_H

#include <cortex/profile.h>

#ifdef __cplusplus
extern "C" {
#endif

int cortex_placement_set(cortex_dumpi_profile* profile, uint32_t rank, uint32_t cn_id);

int cortex_placement_get(const cortex_dumpi_profile* profile, uint32_t rank, uint32_t* cn_id);

#ifdef __cplusplus
}
#endif

#endif

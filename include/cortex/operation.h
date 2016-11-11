/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef DUMPI_CORTEX_OPERATION_H
#define DUMPI_CORTEX_OPERATION_H

#include <dumpi/common/funclabels.h>
#include <dumpi/libundumpi/libundumpi.h>

#ifdef __cplusplus
extern "C" {
#endif

struct cortex_dumpi_profile; // forward declaration

int cortex_has_operation(struct cortex_dumpi_profile* profile);

int cortex_post(struct cortex_dumpi_profile* profile,
		dumpi_function type, 
		const void *prm, 
		uint16_t thread, 
		const dumpi_time *cpu, 
		const dumpi_time *wall, 
		const dumpi_perfinfo *perf);

int cortex_exec(struct cortex_dumpi_profile* profile, struct libundumpi_cbpair* callarr, void* uargs, int* mpi_finalized);

#ifdef __cplusplus
}
#endif

#endif

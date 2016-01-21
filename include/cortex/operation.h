/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef DUMPI_CORTEX_OPERATION_H
#define DUMPI_CORTEX_OPERATION_H

#include <dumpi/common/funclabels.h>
#include <cortex/cortex.h>

struct cortex_dumpi_profile; // forward declaration
struct cortex_operation;

typedef struct cortex_operation {
	dumpi_function type;
	void* args;
	uint16_t thread;
	dumpi_time cpu;
	dumpi_time wall;
	dumpi_perfinfo perf;

	struct cortex_operation* next;
	struct cortex_operation* prev;

} cortex_operation;

int cortex_has_operation(struct cortex_dumpi_profile* profile);

int cortex_post(struct cortex_dumpi_profile* profile,
		dumpi_function type, 
		const void *prm, 
		uint16_t thread, 
		const dumpi_time *cpu, 
		const dumpi_time *wall, 
		const dumpi_perfinfo *perf);

int cortex_exec(struct cortex_dumpi_profile* profile, libundumpi_cbpair* callarr, void* uargs, int* mpi_finalized);

#endif

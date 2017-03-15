/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef CORTEX_TOPOLOGY_H
#define CORTEX_TOPOLOGY_H

#include <cortex/profile.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cortex_topology_s* cortex_topology;

typedef double (*bandwidth_fn)(cortex_topology,int,int);
typedef int    (*neighbor_fn)(cortex_topology,int,int);
typedef void   (*free_internal_fn)(cortex_topology);

struct cortex_topology_s {
	void* internal; // Internal representation of the topology
	// This function returns the link bandwidth between 2 routers, or 0 if they are not connected
	bandwidth_fn get_link_bandwidth;
	// This function returns the id of the n-th router connected to the given router
	neighbor_fn get_neighbor;
	// This function is used to free the internal representation of the topology
	free_internal_fn free_internal;
	// Bandwidth from a terminal to its router
	double cn_bw;
	// Network size (number of routers and number of terminals per router)
	uint32_t num_routers;
	uint32_t cn_per_router;
};

int cortex_topology_create(cortex_topology*, 
			void* internal, bandwidth_fn bfn, 
			neighbor_fn nfn, 
			free_internal_fn fint,
			double cn_bw, int routers, int cn_per_router);

int cortex_topology_free(cortex_topology topology);

int cortex_topology_set(cortex_dumpi_profile* profile, cortex_topology topology);

#ifdef __cplusplus
}
#endif

#endif

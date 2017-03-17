/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */
#ifndef CORTEX_TOPOLOGY_H
#define CORTEX_TOPOLOGY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cortex_dumpi_profile cortex_dumpi_profile;

typedef struct cortex_topology cortex_topology;

typedef int router_id_t;
typedef int cn_id_t;

typedef double (*rr_bandwidth_fn)(void*,router_id_t,router_id_t);
typedef double (*cn_bandwidth_fn)(void*,cn_id_t);
typedef int    (*rr_neighbor_count_fn)(void*,router_id_t);
typedef void   (*rr_neighbor_list_fn)(void*,router_id_t,router_id_t*);
typedef int    (*rr_location_fn)(void*,router_id_t,int32_t*,int);
typedef int    (*cn_location_fn)(void*,cn_id_t,int32_t*,int);
typedef router_id_t (*cn_router_fn)(void*,cn_id_t);
typedef int    (*rr_compute_node_count_fn)(void*,router_id_t);
typedef void   (*rr_compute_node_list_fn)(void*,router_id_t,cn_id_t*);

struct cortex_topology {
	void* internal; // Internal representation of the topology
	rr_bandwidth_fn 		get_router_link_bandwidth;
	cn_bandwidth_fn 		get_compute_node_bandwidth;
	rr_neighbor_count_fn 		get_router_neighbor_count;
	rr_neighbor_list_fn		get_router_neighbor_list;
	rr_location_fn			get_router_location;
	cn_location_fn			get_compute_node_location;
	cn_router_fn			get_router_from_compute_node;
	rr_compute_node_count_fn	get_router_compute_node_count;
	rr_compute_node_list_fn		get_router_compute_node_list;
};

int cortex_topology_set(cortex_dumpi_profile* profile, cortex_topology* topology);

#ifdef __cplusplus
}
#endif

#endif

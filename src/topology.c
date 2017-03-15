#include <string.h>
#include "cortex/profile.h"
#include "cortex/topology.h"

int cortex_topology_create(cortex_topology* topo, 
	void* internal,
	bandwidth_fn bfn, neighbor_fn nfn, 
	free_internal_fn fint,
	double cn_bw, int routers, int cn_per_router)
{
	*topo = (cortex_topology)malloc(sizeof(struct cortex_topology_s));
	(*topo)->internal = internal;
	(*topo)->get_link_bandwidth = bfn;
	(*topo)->get_neighbor = nfn;
	(*topo)->free_internal = fint;
	(*topo)->cn_bw = cn_bw;
	(*topo)->num_routers = routers;
	(*topo)->cn_per_router = cn_per_router;

	return 0;
}

int cortex_topology_set(cortex_dumpi_profile* profile, cortex_topology topology)
{
	profile->topology = topology;
	return 0;
}

int cortex_topology_free(cortex_topology topology) 
{
	if(topology->internal
	&& topology->free_internal) topology->free_internal(topology->internal);

	free(topology);
	return 0;
}

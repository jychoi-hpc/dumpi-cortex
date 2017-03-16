#include <string.h>
#include "cortex/profile.h"
#include "cortex/topology.h"

int cortex_topology_set(cortex_dumpi_profile* profile, cortex_topology* topology)
{
	profile->topology = *topology;
	return 0;
}

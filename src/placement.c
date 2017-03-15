#include "cortex/profile.h"

int cortex_placement_set(cortex_dumpi_profile* profile, uint32_t rank, uint32_t cn_id) 
{
	if(rank >= profile->nprocs) {
		return -1;
	}

	profile->placement[rank] = cn_id;
	return 0;
}

int cortex_placement_get(const cortex_dumpi_profile* profile, uint32_t rank, uint32_t* cn_id)
{
	if(rank >= profile->nprocs) {
		return -1;
	}

	*cn_id = profile->placement[rank];
	return 0;
}

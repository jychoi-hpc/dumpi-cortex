#include "cortex/cortex.h"
#include "cortex/comm.h"
#include "cortex/profile.h"
#include <glib.h>
#include <assert.h>

/**
 * Translation of MPI_Comm_split.
 * TODO: right now this translates into an MPI_Comm_dup because
 * we don't know about the colors and keys used by other processes.
 * We should find a way to change that...
 */
void iterator(gpointer key, gpointer value, gpointer user_data);
int cortex_mpich_translate_MPI_Comm_split(const dumpi_comm_split *prm, 
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {
    printf ("\n %s", __FUNCTION__);

	dumpi_comm oldcomm, newcomm;
	oldcomm = prm->oldcomm;
	newcomm = prm->newcomm;

	printf("\n cortex_mpich_translate_MPI_Comm_split: oldcomm=%d newcomm=%d", prm->oldcomm, prm->newcomm);
	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
	comm_info_t* comm = cortex_lookup(profile, newcomm);

	//cortex_comm_dup(uarg, oldcomm, newcomm);
	cortex_comm_add(uarg, newcomm, comm->size);
	return 0;
}

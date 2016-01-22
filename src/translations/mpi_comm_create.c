#include "cortex/cortex.h"
#include "cortex/comm.h"

/**
 * Translation of MPI_Comm_create.
 * TODO: Right now this translates into an MPI_Comm_dup because
 * we don't have information on the groups. We should support 
 * groups if we want to appropriatly handle this...
 */
int cortex_translate_MPI_Comm_create(const dumpi_comm_create *prm, 
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {

	dumpi_comm oldcomm, newcomm;
	oldcomm = prm->oldcomm;
	newcomm = prm->newcomm;
	cortex_comm_dup(uarg, oldcomm, newcomm);
	return 0;
}

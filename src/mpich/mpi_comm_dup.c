#include "cortex/cortex.h"
#include "cortex/comm.h"

/**
 * Translation of MPI_Comm_dup.
 */
int cortex_mpich_translate_MPI_Comm_dup(const dumpi_comm_dup *prm, 
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

#include "cortex/cortex.h"
#include "cortex/comm.h"

/**
 * Translation of MPI_Comm_split.
 * TODO: right now this translates into an MPI_Comm_dup because
 * we don't know about the colors and keys used by other processes.
 * We should find a way to change that...
 */
int cortex_mpich_translate_MPI_Comm_split(const dumpi_comm_split *prm, 
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

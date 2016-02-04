#include "cortex/cortex.h"

/**
 * Translation of MPI_Allreduce into point to point communications.
 * TODO:  here we use a simple reduce followed by a bcast; other
 * algorithms may be used by MPI in most cases, we should implement them.
 */
int cortex_translate_MPI_Allreduce(const dumpi_allreduce *prm, 
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {

	dumpi_reduce reduce_prm;
		reduce_prm.count 	= prm->count;
		reduce_prm.datatype	= prm->datatype;
		reduce_prm.op		= prm->op;
		reduce_prm.root		= 0;
		reduce_prm.comm		= prm->comm;

	dumpi_bcast bcast_prm;
		bcast_prm.count		= prm->count;
		bcast_prm.datatype	= prm->datatype;
		bcast_prm.root		= 0;
		bcast_prm.comm		= prm->comm;

	cortex_translate_MPI_Reduce(&reduce_prm, thread, cpu, wall, perf, uarg);
	cortex_translate_MPI_Bcast(&bcast_prm, thread, cpu, wall, perf, uarg);

	return 0;
}

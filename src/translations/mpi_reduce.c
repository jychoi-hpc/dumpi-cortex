#include "cortex/cortex.h"


static int reduce_binomial(const dumpi_reduce* prm,
			int rank,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg);

/**
 * Translation of MPI_Reduce into point to point communications.
 * TODO: so far we use the binomial algorithm all the time;
 * we should implement also Rabenseifner's reduce algorithm.
 */
int cortex_translate_MPI_Reduce(const dumpi_reduce *prm, 
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {

	return reduce_binomial(prm,thread,cpu,wall,perf,uarg);
}

/**
 * This is the implementation of MPI_Reduce based on a binomial tree,
 * it can be found in the Mpich implementation in
 * mpich-3.1.4/src/mpi/coll/reduce.c line 79.
 *
 * TODO: here we have assume op is commutative.
 * TODO: here we have assume datatype is contiguous.
 */
static int reduce_binomial(const dumpi_reduce* prm,
			int rank,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg)
{
	int comm_size, root, mask, relrank, source, lroot;

	cortex_comm_get_size(uarg, prm->comm, &comm_size);
	root = prm->root;

	mask = 0x1;
	lroot = 0;
	relrank = (rank - lroot+comm_size) % comm_size;

	dumpi_recv recv_prm;
		recv_prm.count		= prm->count;
		recv_prm.datatype	= prm->datatype;
		recv_prm.tag		= 1234;
		recv_prm.comm		= prm->comm;

	dumpi_send send_prm;
		send_prm.count		= prm->count;
		send_prm.datatype	= prm->datatype;
		send_prm.tag		= 1234;
		send_prm.comm		= prm->comm;

	while(mask < comm_size) {
		if ((mask & relrank) == 0) {
			source = (relrank | mask);
			recv_prm.source = source;
			cortex_post_MPI_Recv(&recv_prm,rank,cpu,wall,perf,uarg);
		} else {
			source = ((relrank & (~ mask)) + lroot) % comm_size;
			send_prm.dest = source;
			cortex_post_MPI_Send(&send_prm,rank,cpu,wall,perf,uarg);
			break;
		}
		mask <<= 1;
	}
	return 0;
}

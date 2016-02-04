#include "cortex/cortex.h"


static int bcast_binomial(const dumpi_bcast* prm,
			int rank,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg);

/**
 * Translation of MPI_Bcast into point to point communications.
 * TODO: right now a binomial implementation is used;
 * we should also implement scatter_doubling_allgather (line 481
 * in bcast.c in Mpich).
 * TODO: we should also implement Bcast_scatter_ring_allgather
 * (line 791 in bcast.c)
 */
int cortex_translate_MPI_Bcast(const dumpi_bcast *prm, 
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {

	return bcast_binomial(prm,thread,cpu,wall,perf,uarg);
}

/**
 * This is the implementation of MPI_Bcast based on a binomial tree,
 * it can be found in the Mpich implementation in
 * mpich-3.1.4/src/mpi/coll/bcast.c line 124.
 *
 * TODO: If the type is not contiguous, this function should pack
 * the data and send bytes instead of directly sending the datatype.
 * TODO: If the architecture is heterogeneous, this function whould
 * always pack the data instead of directly sending the datatype.
 */
static int bcast_binomial(const dumpi_bcast* prm,
			int rank,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg)
{
	int comm_size, src, dst, relative_rank, mask, bnytes, root;
	cortex_comm_get_size(uarg, prm->comm, &comm_size);
	root = prm->root;
	relative_rank = (rank >= root) ? rank - root : rank - root + comm_size;

	dumpi_recv recv_prm;
		recv_prm.count 		= prm->count;
		recv_prm.datatype 	= prm->datatype;
		recv_prm.tag 		= 1234;
		recv_prm.comm 		= prm->comm;
	dumpi_send send_prm;
		send_prm.count 		= prm->count;
		send_prm.datatype 	= prm->datatype;
		send_prm.tag 		= 1234;
		send_prm.comm 		= prm->comm;

	mask = 0x1;
	while(mask < comm_size)
	{
		if(relative_rank & mask)
		{
			src = rank - mask;
			if(src < 0) src += comm_size;
			recv_prm.source = src;
			cortex_post_MPI_Recv(&recv_prm,rank,cpu,wall,perf,uarg);
			break;
		}
		mask <<= 1;
	}

	mask >>=1;
	while(mask > 0)
	{
		if(relative_rank + mask < comm_size)
		{
			dst = rank + mask;
			if(dst >= comm_size) dst -= comm_size;
			send_prm.dest = dst;
			cortex_post_MPI_Send(&send_prm,rank,cpu,wall,perf,uarg);
		}
		mask >>= 1;
	}
}

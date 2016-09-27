#include "cortex/cortex.h"
#include "cortex/constants.h"
#include "cortex/debug.h"

#define MPICH_BCAST_TAG -1234

/**
 * Bcast based on a binomial tree across all processes of prm->comm.
 * Root is prm->root.
 */
static int bcast_binomial(const dumpi_bcast* prm,
			int rank,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg);

/**
 * Bcast based on a binomial tree across ranks specified in comm_ranks
 * (of size comm_size).
 * The root is comm_ranks[0].
 */
static int partial_bcast_binomial(const dumpi_bcast* prm,
			int rank,
			int16_t* comm_ranks, size_t comm_size,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg);

/**
 * Bcast on a Dragonfly network, using Router/Group/Terminal order.
 */
static int dfly_bcast_rgt(const dumpi_bcast* prm,
			int rank,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg);
			
/**
 * Bcast based on Scatter and doubling Allgather.
 */
static int bcast_scatter_doubling_allgather(const dumpi_bcast* prm,
			int rank,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg);

/**
 * Bcased based on scatter and ring allgather.
 */
static int bcast_scatter_ring_allgather(const dumpi_bcast* prm,
			int rank,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg);

/**
 * Translation of MPI_Bcast into point to point communications.
 */
int cortex_mpich_translate_MPI_Bcast(const dumpi_bcast *prm, 
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {

	int type_size = cortex_datatype_get_size(prm->datatype);
	int comm_size;
	cortex_comm_get_size(uarg, prm->comm, &comm_size);
	int nbytes = prm->count * type_size;
	if((nbytes < CORTEX_BCAST_SHORT_MSG_SIZE) || (comm_size < CORTEX_BCAST_MIN_PROCS)) {
		INFO("Bcast for %d bytes and %d processes, use binomial algorithm\n",nbytes,comm_size);
		return bcast_binomial(prm,thread,cpu,wall,perf,uarg);
	} else if((nbytes < CORTEX_BCAST_LONG_MSG_SIZE) && !(comm_size & (comm_size - 1))) {
		INFO("Bcast for %d bytes and %d processes, use scatter followed by recursive doubling allgather\n",nbytes,comm_size);
		return bcast_scatter_doubling_allgather(prm,thread,cpu,wall,perf,uarg);
	} else {
		INFO("Bcast for %d bytes and %d processes, use scatter followed by ring allgather\n",nbytes,comm_size);
		return bcast_scatter_ring_allgather(prm,thread,cpu,wall,perf,uarg);
	}
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
		recv_prm.tag 		= MPICH_BCAST_TAG;
		recv_prm.comm 		= prm->comm;
	dumpi_send send_prm;
		send_prm.count 		= prm->count;
		send_prm.datatype 	= prm->datatype;
		send_prm.tag 		= MPICH_BCAST_TAG;
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

#define MIN(a,b) ((a) < (b)) ? (a) : (b)

static int bcast_scatter_doubling_allgather(const dumpi_bcast* prm,
					int rank,
					const dumpi_time *cpu,
					const dumpi_time *wall,
					const dumpi_perfinfo *perf,
					void *uarg)
{
	int comm_size, dst, relative_rank, mask, scatter_size, curr_size, recv_size = 0;
	int j, k, i, tmp_mask;
	int type_size, nbytes = 0;
	int relative_dst, dst_tree_root, my_tree_root, send_offset, recv_offset;
	
	type_size = cortex_datatype_get_size(prm->datatype);
	cortex_comm_get_size(uarg, prm->comm, &comm_size);

	relative_rank = (rank >= prm->root) ? rank - prm->root : rank - prm->root + comm_size;
	
	if(comm_size == 1) return 0;

	nbytes = type_size * prm->count;
	if(nbytes == 0) return 0;

	scatter_size = (nbytes + comm_size - 1)/comm_size; /* ceiling division */
	curr_size = MIN(scatter_size, (nbytes - (relative_rank * scatter_size)));

	if (curr_size < 0) curr_size = 0;

	mask = 0x1;
	i = 0;

	while(mask < comm_size) {
		relative_dst = relative_rank ^ mask;
		dst = (relative_dst + prm->root) % comm_size;

		dst_tree_root = relative_dst >> i;
		dst_tree_root <<= i;

		my_tree_root = relative_rank >> i;
		my_tree_root <<= i;
	
		send_offset = my_tree_root * scatter_size;
		recv_offset = dst_tree_root * scatter_size;

		if(relative_dst < comm_size)
		{
			dumpi_sendrecv sr_prm;
				sr_prm.sendcount = curr_size;
				sr_prm.sendtype = DUMPI_BYTE;
				sr_prm.dest = dst;
				sr_prm.sendtag = MPICH_BCAST_TAG;
				sr_prm.recvcount = (nbytes-recv_offset < 0 ? 0 : nbytes-recv_offset);
				sr_prm.recvtype = DUMPI_BYTE;
				sr_prm.source = dst;
				sr_prm.recvtag = MPICH_BCAST_TAG;
			cortex_post_MPI_Sendrecv(&sr_prm,rank,cpu,wall,perf,uarg);

			curr_size += recv_size;
		}

		mask <<= 1;
		i++;
	}

	return 0;
}

static int bcast_scatter_ring_allgather(const dumpi_bcast* prm,
					int rank,
					const dumpi_time *cpu,
					const dumpi_time *wall,
					const dumpi_perfinfo *perf,
					void *uarg)
{
	int comm_size, scatter_size, j, i, nbytes, type_size;
	int left, right, jnext, curr_size = 0;
	int recvd_size;

	type_size = cortex_datatype_get_size(prm->datatype);
	cortex_comm_get_size(uarg, prm->comm, &comm_size);

	if(comm_size == 1) return 0;

	nbytes = type_size * prm->count;
	if (nbytes == 0) return 0;

	scatter_size = (nbytes + comm_size - 1)/comm_size; /* ceiling division */

	curr_size = MIN(scatter_size,  nbytes - ((rank - prm->root + comm_size) % comm_size) * scatter_size);
	if(curr_size < 0) curr_size = 0;

	left  = (comm_size + rank - 1) % comm_size;
	right = (rank + 1) % comm_size;
	j = rank;
	jnext = left;

	for (i=1; i<comm_size; i++)
	{
		int left_count, right_count, left_disp, right_disp, rel_j, rel_jnext;
		rel_j     = (j     - prm->root + comm_size) % comm_size;
		rel_jnext = (jnext - prm->root + comm_size) % comm_size;
		left_count = MIN(scatter_size, (nbytes - rel_jnext * scatter_size));
		if(left_count < 0) left_count = 0;
		left_disp = rel_jnext * scatter_size;
		right_count = MIN(scatter_size, (nbytes - rel_j * scatter_size));
		if(right_count < 0) right_count = 0;
		right_disp = rel_j * scatter_size;

		dumpi_sendrecv sr_prm;
			sr_prm.sendcount = right_count;
			sr_prm.sendtype = DUMPI_BYTE;
			sr_prm.dest = right;
			sr_prm.sendtag = MPICH_BCAST_TAG;
			sr_prm.recvcount = left_count;
			sr_prm.recvtype = DUMPI_BYTE;
			sr_prm.source = left;
			sr_prm.recvtag = MPICH_BCAST_TAG;
			sr_prm.comm = prm->comm;
		cortex_post_MPI_Sendrecv(&sr_prm,rank,cpu,wall,perf,uarg);		

		curr_size += recvd_size;
		j = jnext;
		jnext = (comm_size + jnext - 1) % comm_size;
	}

	return 0;
}

static int partial_bcast_binomial(
			const dumpi_bcast* prm,
                        int rank,
			int16_t* comm_ranks, size_t comm_size,
                        const dumpi_time *cpu,
                        const dumpi_time *wall,
                        const dumpi_perfinfo *perf,
                        void *uarg)
{
	// find the index of this rank in the array
	int my_index = 0;
	int src, dst;
	while(my_index < comm_size && comm_ranks[my_index] != rank) my_index++;

	if(my_index == comm_size) return -1;

	int mask = 0x1;
	while(mask < comm_size) {
		if(my_index & mask) {
			src = my_index - mask;
			dumpi_recv recv_prm;
				recv_prm.count = prm->count;
				recv_prm.datatype = prm->datatype;
				recv_prm.source = comm_ranks[src];
				recv_prm.tag = MPICH_BCAST_TAG;
				recv_prm.comm = prm->comm;
				recv_prm.status = NULL;
			cortex_post_MPI_Recv(&recv_prm,rank,cpu,wall,perf,uarg);
			break;
		}
		mask <<= 1;
	}

	mask >>= 1;
	while(mask > 0) {
		if(my_index + mask < comm_size) {
			dst = my_index + mask;
			dumpi_send send_prm;
				send_prm.count = prm->count;
				send_prm.datatype = prm->datatype;
				send_prm.dest = comm_ranks[dst];
				send_prm.tag = MPICH_BCAST_TAG;
				send_prm.comm = prm->comm;
			cortex_post_MPI_Send(&send_prm,rank,cpu,wall,perf,uarg);
		}
		mask >>= 1;
	}
	return 0;
}

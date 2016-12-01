#include "cortex/cortex.h"
#include "cortex/mpich-constants.h"
#include "cortex/datatype.h"
#include "cortex/debug.h"
#include "cortex/profile.h"

/**
 * This translates MPI_Allgather calls into a series of
 * point to point calls. The following
 * algorithm was found in the Mpich implementation.
 */
int cortex_mpich_translate_MPI_Allgather(const dumpi_allgather *prm,
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {

	int rank, comm_size;
	rank = ((cortex_dumpi_profile*)uarg)->rank;
	cortex_comm_get_size(uarg, prm->comm, &comm_size);

	int j, i, pof2, src, rem, jnext;
	int curr_cnt, dst;
	int mask, dst_tree_root, my_tree_root,
	    last_recv_cnt = 0;
	int type_size, tot_bytes;
	int left, right;

	if(prm->sendcount == 0) return 0;

	type_size = cortex_datatype_get_size(uarg,prm->recvtype);

	dumpi_sendrecv sendrecv_prm;
		sendrecv_prm.comm 	= prm->comm;
		sendrecv_prm.sendcount 	= 1;
		sendrecv_prm.sendtype 	= prm->recvtype;
		sendrecv_prm.sendtag	= CORTEX_ALLGATHER_TAG;
		sendrecv_prm.recvcount	= 1;
		sendrecv_prm.recvtype	= prm->recvtype;
		sendrecv_prm.recvtag	= CORTEX_ALLGATHER_TAG;
		sendrecv_prm.status	= NULL;

	tot_bytes = prm->recvcount * comm_size * type_size;
	if(tot_bytes < CORTEX_ALLGATHER_LONG_MSG_SIZE && !(comm_size & (comm_size - 1))) {

		INFO("Allgather for %d bytes across %d processes, use recursive doubling algorithm\n",tot_bytes,comm_size);

		mask = 0x1;
		curr_cnt = prm->recvcount;

		/* Power-of-two no. of processes, use recursive doubling algo */
		while(mask < comm_size) {
			dst = rank ^ mask;

			if(dst < comm_size) {

				sendrecv_prm.sendcount = curr_cnt;
				sendrecv_prm.dest = dst;
				sendrecv_prm.recvcount = curr_cnt;
				sendrecv_prm.source = dst;
				cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);
				curr_cnt *= 2;
			}

			mask <<= 1;
		}

	} else if(tot_bytes < CORTEX_ALLGATHER_SHORT_MSG_SIZE) {
		/* Non-power-of-two no. of processes but small messages, use Bruck algorithm. */
		/* do the first \floor(\lg p) steps */

		INFO("Allgather for %d bytes across %d processes, use Bruck algorithm\n",tot_bytes,comm_size);

		curr_cnt = prm->recvcount;
		pof2 = 1;
		while (pof2 <= comm_size/2) {
			src = (rank + pof2) % comm_size;
			dst = (rank - pof2 + comm_size) % comm_size;
			
			sendrecv_prm.sendcount = curr_cnt;
			sendrecv_prm.dest = dst;
			sendrecv_prm.recvcount = curr_cnt;
			sendrecv_prm.source = src;
			cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);

			curr_cnt *= 2;
			pof2 *= 2;
		}
		/* do the rest */
		rem = comm_size - pof2;
		if (rem) {
			src = (rank + pof2) % comm_size;
			dst = (rank - pof2 + comm_size) % comm_size;
			
			sendrecv_prm.sendcount = rem*(prm->recvcount);
			sendrecv_prm.dest = dst;
			sendrecv_prm.recvcount = rem*(prm->recvcount);
			sendrecv_prm.source = src;
			cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);
		}
	} else {
		/* For long messages, Ring algo should be used... (allgather.c line 585) */

		INFO("Allgather for %d bytes across %d processes, use ring algorithm\n",tot_bytes,comm_size);

		left = (comm_size + rank - 1) % comm_size;
		right = (rank + 1) % comm_size;

		j = rank;
		jnext = left;
		for(i=1; i<comm_size; i++) {
			
			sendrecv_prm.sendcount = prm->recvcount;
			sendrecv_prm.dest = right;
			sendrecv_prm.recvcount = prm->recvcount;
			sendrecv_prm.source = left;
			
			cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);

			j = jnext;
			jnext = (comm_size + jnext - 1) % comm_size;
		}
	}

	return 0;
}

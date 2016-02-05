#include "cortex/cortex.h"

/**
 * This translates MPI_Allgatherv calls into a series of
 * point to point calls. The following
 * algorithm was found in the Mpich implementation.
 */
int cortex_translate_MPI_Allgatherv(const dumpi_allgatherv *prm,
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {

	int rank, comm_size;
	rank = thread;
	cortex_comm_get_size(uarg, prm->comm, &comm_size);

	int j, i, pof2, src, rem;
	int curr_cnt, dst, total_count, recv_offset, send_cnt;
	int mask, dst_tree_root, my_tree_root,
	    last_recv_cnt = 0;

	dumpi_sendrecv sendrecv_prm;
		sendrecv_prm.comm 	= prm->comm;
		sendrecv_prm.sendtype 	= prm->recvtype;
		sendrecv_prm.sendtag	= 1234;
		sendrecv_prm.recvtype	= prm->recvtype;
		sendrecv_prm.recvtag	= 1234;
		sendrecv_prm.status	= NULL;

	total_count = 0;
	for (i=0; i<comm_size; i++)
		total_count += prm->recvcounts[i];

	if (total_count == 0) return 0;

	if(!(comm_size & (comm_size - 1))) {
		/* Power-of-two no. of processes, use recursive doubling algo */
		i = 0;
		mask = 0x1;
		curr_cnt = prm->recvcounts[rank];

		while(mask < comm_size) {
			dst = rank ^ mask;

			dst_tree_root = dst >> i;
			dst_tree_root <<= i;
			
			my_tree_root = rank >> i;
			my_tree_root <<= i;

			if(dst < comm_size) {

				recv_offset = 0;
				for (j=0; j<dst_tree_root; j++)
					recv_offset += prm->recvcounts[j];

				sendrecv_prm.sendcount = curr_cnt;
				sendrecv_prm.dest = dst;
				last_recv_cnt = total_count - recv_offset;
				sendrecv_prm.recvcount = last_recv_cnt;
				sendrecv_prm.source = dst;
				cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);

				curr_cnt += last_recv_cnt;
			}

			mask <<= 1;
			i++;
		}

	} else {
		/* Non-power-of-two no. of processes, use Bruck algorithm. */
		/* do the first \floor(\lg p) steps */
		curr_cnt = prm->recvcounts[rank];
		pof2 = 1;
		while (pof2 <= comm_size/2) {
			src = (rank + pof2) % comm_size;
			dst = (rank - pof2 + comm_size) % comm_size;
			
			sendrecv_prm.sendcount = curr_cnt;
			sendrecv_prm.dest = dst;
			sendrecv_prm.recvcount = total_count - curr_cnt;
			sendrecv_prm.source = src;
			cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);

			curr_cnt += total_count - curr_cnt;
			pof2 *= 2;
		}
		/* do the rest */
		rem = comm_size - pof2;
		if (rem) {
			src = (rank + pof2) % comm_size;
			dst = (rank - pof2 + comm_size) % comm_size;
			
			send_cnt = 0;
			for (i=0; i<rem; i++)
				send_cnt += prm->recvcounts[(rank+i)%comm_size];

			sendrecv_prm.sendcount = send_cnt;
			sendrecv_prm.dest = dst;
			sendrecv_prm.recvcount = total_count - curr_cnt;
			sendrecv_prm.source = src;
			cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);
		}
	} // TODO for long messages, Ring algo should be used... (allgatherv.c line 643)

	return 0;
}

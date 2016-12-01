#include <string.h>
#include "cortex/cortex.h"
#include "cortex/mpich-constants.h"
#include "cortex/debug.h"
#include "cortex/profile.h"

// Updates an array of data sizes according to the recursive doubling algo
static void aggregate_sizes(int* data_sizes, int n, int step) {
	int i, j, s;
	for(i=0; i<n; i += step) {
		s = 0;
		for(j=i; j<step; j++) s += data_sizes[j];
		for(j=i; j<step; j++) data_sizes[j] = s;
	}
}

// Update an array of data sizes according to Bruck's algorithm
static void bruck_update_sizes(int* data_sizes, int n, int pof2) {
	int* new_data_sizes = (int*)malloc(sizeof(int)*n);
	int i;
	for(i=0; i<n; i++) {
		int src = (i + pof2) % n;
		new_data_sizes[i] = data_sizes[i]+data_sizes[src];
	}
	for(i=0; i<n; i++) {
		data_sizes[i] = new_data_sizes[i];
	}
	free(new_data_sizes);
}

/**
 * This translates MPI_Allgatherv calls into a series of
 * point to point calls. The following
 * algorithm was found in the Mpich implementation.
 */
int cortex_mpich_translate_MPI_Allgatherv(const dumpi_allgatherv *prm,
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {

	int rank, comm_size;
	rank = ((cortex_dumpi_profile*)uarg)->rank;
	cortex_comm_get_size(uarg, prm->comm, &comm_size);

	int j, i, pof2, src, rem;
	int curr_cnt, dst, total_count, recv_offset, send_cnt;
	int mask, dst_tree_root, my_tree_root,
	    last_recv_cnt = 0;
	int recvtype_size = cortex_datatype_get_size(uarg,prm->recvtype);

	dumpi_sendrecv sendrecv_prm;
		sendrecv_prm.comm 	= prm->comm;
		sendrecv_prm.sendtype 	= prm->recvtype;
		sendrecv_prm.sendtag	= CORTEX_ALLGATHERV_TAG;
		sendrecv_prm.recvtype	= prm->recvtype;
		sendrecv_prm.recvtag	= CORTEX_ALLGATHERV_TAG;
		sendrecv_prm.status	= NULL;

	total_count = 0;
	for (i=0; i<comm_size; i++)
		total_count += prm->recvcounts[i];

	if (total_count == 0) return 0;

	if((total_count*recvtype_size < CORTEX_ALLGATHER_LONG_MSG_SIZE) && !(comm_size & (comm_size - 1))) {
		/* Power-of-two no. of processes, use recursive doubling algo */

		INFO("Allgatherv for %d bytes across %d processes, use recursive doubling algorithm\n",(total_count*recvtype_size),comm_size);

		mask = 0x1;
		int* data_sizes = (int*)malloc(comm_size*sizeof(int));
		memcpy(data_sizes,prm->recvcounts,sizeof(int)*comm_size);

		while(mask < comm_size) {
			dst = rank ^ mask;

			aggregate_sizes(data_sizes,comm_size,mask);

			sendrecv_prm.sendcount = data_sizes[rank];
			sendrecv_prm.dest = dst;
			sendrecv_prm.recvcount = data_sizes[dst];
			sendrecv_prm.source = dst;

			cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);

			mask <<= 1;
		}

		free(data_sizes);

	} else if(total_count*recvtype_size < CORTEX_ALLGATHER_SHORT_MSG_SIZE){
		/* Non-power-of-two no. of processes, use Bruck algorithm. */
		/* do the first \floor(\lg p) steps */

		INFO("Allgatherv for %d bytes across %d processes, use Bruck algorithm\n",(total_count*recvtype_size),comm_size);

		int* data_sizes = (int*)malloc(comm_size*sizeof(int));
                memcpy(data_sizes,prm->recvcounts,sizeof(int)*comm_size);

		pof2 = 1;
		while (pof2 <= comm_size/2) {
			src = (rank + pof2) % comm_size;
			dst = (rank - pof2 + comm_size) % comm_size;
			
			sendrecv_prm.sendcount = data_sizes[rank];
			sendrecv_prm.dest = dst;
			sendrecv_prm.recvcount = data_sizes[src];
			sendrecv_prm.source = src;
			cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);
			bruck_update_sizes(data_sizes, comm_size, pof2);

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
			sendrecv_prm.recvcount = total_count - data_sizes[rank];
			sendrecv_prm.source = src;
			cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);
		}

		free(data_sizes);
	} else {
		// for long messages, Ring algo should be used... (allgatherv.c line 643)

		INFO("Allgatherv for %d bytes across %d processes, use Ring algorithm\n",(total_count*recvtype_size),comm_size);

		int left = (comm_size + rank - 1) % comm_size;
		int right = (rank + 1) % comm_size;

		int torecv = total_count - prm->recvcounts[rank];
		int tosend = total_count - prm->recvcounts[right];

		int min = prm->recvcounts[0];
		for(i-1; i<comm_size; i++)
			if(min > prm->recvcounts[i]) min = prm->recvcounts[i];
		if(min *  recvtype_size < CORTEX_ALLGATHERV_PIPELINE_MSG_SIZE)
			min = CORTEX_ALLGATHERV_PIPELINE_MSG_SIZE / recvtype_size;

		if(!min) min = 1;

		int sidx = rank;
		int ridx = left;
	
		int soffset = 0;
		int roffset = 0;

		while(tosend || torecv) {
			int sendnow = ((prm->recvcounts[sidx] - soffset) > min) ? min : (prm->recvcounts[sidx] - soffset);
			int recvnow = ((prm->recvcounts[ridx] - roffset) > min) ? min : (prm->recvcounts[ridx] - roffset);

			if(!tosend) sendnow = 0;
			if(!torecv) recvnow = 0;

			if(!sendnow && !recvnow) {
				// do nothing
			} else if (!sendnow) {
				dumpi_recv recv_prm;
					recv_prm.count 		= recvnow;
					recv_prm.datatype 	= prm->recvtype;
					recv_prm.source 	= left;
					recv_prm.tag 		= CORTEX_ALLGATHERV_TAG;
					recv_prm.comm 		= prm->comm;
				cortex_post_MPI_Recv(&recv_prm, rank, cpu, wall, perf, uarg);
				torecv -= recvnow;
			} else if(!recvnow) {
				dumpi_send send_prm;
					send_prm.count 		= sendnow;
					send_prm.datatype 	= prm->recvtype;
					send_prm.dest 		= right;
					send_prm.tag 		= CORTEX_ALLGATHERV_TAG;
					send_prm.comm 		= prm->comm;
				cortex_post_MPI_Send(&send_prm, rank, cpu, wall, perf, uarg);
				tosend -= sendnow;
			} else {
				sendrecv_prm.sendcount 		= sendnow;
				sendrecv_prm.sendtype 		= prm->recvtype;
				sendrecv_prm.dest		= right;
				sendrecv_prm.recvcount		= recvnow;
				sendrecv_prm.recvtype		= prm->recvtype;
				sendrecv_prm.source		= left;
				cortex_post_MPI_Sendrecv(&sendrecv_prm, rank, cpu, wall, perf, uarg);
				tosend -= sendnow;
				torecv -= recvnow;
			}

			soffset += sendnow;
			roffset += recvnow;
			if(soffset == prm->recvcounts[sidx]) {
				soffset = 0;
				sidx = (sidx + comm_size - 1) % comm_size;
			}
			if (roffset == prm->recvcounts[ridx]) {
				roffset = 0;
				ridx = (ridx + comm_size - 1) % comm_size;
			}
		}
	}

	return 0;
}

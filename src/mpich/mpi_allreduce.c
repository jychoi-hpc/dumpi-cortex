#include "cortex/cortex.h"
#include "cortex/mpich-constants.h"
#include "cortex/debug.h"
#include "cortex/profile.h"

/**
 * Translation of MPI_Allreduce into point to point communications.
 */
int cortex_mpich_translate_MPI_Allreduce(const dumpi_allreduce *prm, 
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {
    printf ("\n %s", __FUNCTION__);

	INFO("Allreduce using Mpich's algorithm\n");

#ifdef MPICH_FORWARD
    cortex_post_MPI_Allreduce(prm, thread, cpu, wall, perf, uarg);
#endif

	printf("\n cortex_mpich_translate_MPI_Allreduce: comm=%d", prm->comm);
	thread = ((cortex_dumpi_profile*)uarg)->rank;
	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
	comm_info_t* comm = cortex_lookup(profile, prm->comm);

	int comm_size, i, send_idx, recv_idx, last_idx, send_cnt, recv_cnt;
	int pof2, mask, rem, newrank, newdst, dst, *cnts, *disps;
	cortex_comm_get_size(uarg, prm->comm, &comm_size);
	// int rank = ((cortex_dumpi_profile*)uarg)->rank;
	int rank = comm->wtol[thread];
	int type_size = cortex_datatype_get_size(uarg,prm->datatype);

	cnts = disps = NULL;
	
	pof2 = 1;
	while (pof2 <= comm_size) pof2 <<= 1;
	pof2 >>=1;

	rem = comm_size - pof2;

	/* In the non-power-of-two case, all even-numbered
	   processes of rank < 2*rem send their data to
	   (rank+1). These even-numbered processes no longer
	   participate in the algorithm until the very end. The
	   remaining processes form a nice power-of-two. */
	if (rank < 2*rem) {
		if (rank % 2 == 0) { /* even */
			dumpi_send send_prm;
				send_prm.count = prm->count;
				send_prm.datatype = prm->datatype;
				send_prm.dest = rank+1;
				send_prm.tag = CORTEX_ALLREDUCE_TAG;
				send_prm.comm = prm->comm;
			cortex_post_MPI_Send(&send_prm,rank,cpu,wall,perf,uarg);
			newrank = -1;
		} else { /* odd */
			dumpi_recv recv_prm;
				recv_prm.count = prm->count;
				recv_prm.datatype = prm->datatype;
				recv_prm.source = rank-1;
				recv_prm.tag = CORTEX_ALLREDUCE_TAG;
				recv_prm.comm = prm->comm;
			cortex_post_MPI_Recv(&recv_prm,rank,cpu,wall,perf,uarg);
			newrank = rank / 2;
		}
	} else {
		newrank = rank - rem;
	}

	/* If op is user-defined or count is less than pof2, use
	   recursive doubling algorithm. Otherwise do a reduce-scatter
	   followed by allgather. (If op is user-defined,
	   derived datatypes are allowed and the user could pass basic
	   datatypes on one process and derived on another as long as
	   the type maps are the same. Breaking up derived
	   datatypes to do the reduce-scatter is tricky, therefore
	   using recursive doubling in that case.) */
	if (newrank != -1) { 
		if ((prm->count*type_size <= CORTEX_ALLREDUCE_SHORT_MSG_SIZE) || (prm->count < pof2)) {

			mask = 0x1;
			while (mask < pof2) {
				newdst = newrank ^ mask;
				dst = (newdst < rem) ? newdst*2 + 1 : newdst + rem;

				dumpi_sendrecv sr_prm;
					sr_prm.sendcount = prm->count;
					sr_prm.sendtype = prm->datatype;
					sr_prm.dest = dst;
					sr_prm.sendtag = CORTEX_ALLREDUCE_TAG;
					sr_prm.recvcount = prm->count;
					sr_prm.recvtype = prm->datatype;
					sr_prm.source = dst;
					sr_prm.recvtag = CORTEX_ALLREDUCE_TAG;
					sr_prm.comm = prm->comm;
				cortex_post_MPI_Sendrecv(&sr_prm,rank,cpu,wall,perf,uarg);

				mask <<= 1;
			}
		} else {
			/* do a reduce-scatter followed by allgather */
			/* for the reduce-scatter, calculate the count that
			each process receives and the displacement within
			the buffer */

			cnts = (int*)malloc(pof2*sizeof(int));
			disps = (int*)malloc(pof2*sizeof(int));
			
			for (i=0; i<(pof2-1); i++)
				cnts[i] = prm->count/pof2;
			cnts[pof2-1] = prm->count - (prm->count/pof2)*(pof2-1);
			
			disps[0] = 0;
			for (i=1; i<pof2; i++)
				disps[i] = disps[i-1] + cnts[i-1];

			mask = 0x1;
			send_idx = recv_idx = 0;
			last_idx = pof2;
			while (mask < pof2) {
				newdst = newrank ^ mask;
				dst = (newdst < rem) ? newdst*2 + 1 : newdst + rem;
				send_cnt = recv_cnt = 0;
				if (newrank < newdst) {
					send_idx = recv_idx + pof2/(mask*2);
					for (i=send_idx; i<last_idx; i++)
						send_cnt += cnts[i];
					for (i=recv_idx; i<send_idx; i++)
						recv_cnt += cnts[i];
				} else {
					recv_idx = send_idx + pof2/(mask*2);
					for (i=send_idx; i<recv_idx; i++)
						send_cnt += cnts[i];
					for (i=recv_idx; i<last_idx; i++)
						recv_cnt += cnts[i];
				}

				dumpi_sendrecv sr_prm;
					sr_prm.sendcount = send_cnt;
					sr_prm.sendtype = prm->datatype;
					sr_prm.dest = dst;
					sr_prm.sendtag = CORTEX_ALLREDUCE_TAG;
					sr_prm.recvcount = recv_cnt;
					sr_prm.recvtype = prm->datatype;
					sr_prm.source = dst;
					sr_prm.recvtag = CORTEX_ALLREDUCE_TAG;
					sr_prm.comm = prm->comm;
				cortex_post_MPI_Sendrecv(&sr_prm,rank,cpu,wall,perf,uarg);

				send_idx = recv_idx;
				mask <<= 1;
	
				if(mask < pof2)
					last_idx = recv_idx + pof2/mask;
			}
		
			/* now do the allgather */
			mask >>= 1;
			while (mask > 0) {
				newdst = newrank ^ mask;
				/* find real rank of dest */
				dst = (newdst < rem) ? newdst*2 + 1 : newdst + rem;

				send_cnt = recv_cnt = 0;
				if (newrank < newdst) {
					if (mask != pof2/2)
						last_idx = last_idx + pof2/(mask*2);
				
					recv_idx = send_idx + pof2/(mask*2);
					for (i=send_idx; i<recv_idx; i++)
						send_cnt += cnts[i];
					for (i=recv_idx; i<last_idx; i++)
						recv_cnt += cnts[i];
				} else {
					recv_idx = send_idx - pof2/(mask*2);
					for (i=send_idx; i<last_idx; i++)
						send_cnt += cnts[i];
					for (i=recv_idx; i<send_idx; i++)
						recv_cnt += cnts[i];
				}

				dumpi_sendrecv sr_prm;
					sr_prm.sendcount = send_cnt;
					sr_prm.sendtype = prm->datatype;
					sr_prm.dest = dst;
					sr_prm.sendtag = CORTEX_ALLREDUCE_TAG;
					sr_prm.recvcount = recv_cnt;
					sr_prm.recvtype = prm->datatype;
					sr_prm.source = dst;
					sr_prm.recvtag = CORTEX_ALLREDUCE_TAG;
					sr_prm.comm = prm->comm;
				cortex_post_MPI_Sendrecv(&sr_prm,rank,cpu,wall,perf,uarg);

				if (newrank > newdst) send_idx = recv_idx;
				
				mask >>= 1;
			}
		}
	} 

	if(rank < 2*rem) {
		if(rank % 2) {/* odd */
			dumpi_send send_prm;
				send_prm.count = prm->count;
				send_prm.datatype = prm->datatype;
				send_prm.dest = rank-1;
				send_prm.tag = CORTEX_ALLREDUCE_TAG;
				send_prm.comm = prm->comm;
			cortex_post_MPI_Send(&send_prm,rank,cpu,wall,perf,uarg);
		} else {
			dumpi_recv recv_prm;
				recv_prm.count = prm->count;
				recv_prm.datatype = prm->datatype;
				recv_prm.source = rank+1;
				recv_prm.tag = CORTEX_ALLREDUCE_TAG;
				recv_prm.comm = prm->comm;
			cortex_post_MPI_Recv(&recv_prm,rank,cpu,wall,perf,uarg);
		}
	}

	if(cnts) free(cnts);
	if(disps) free(disps);

#ifdef MPICH_FORWARD
    cortex_post_MPI_Allreduce(prm, thread, cpu, wall, perf, uarg);
#endif

	return 0;
}

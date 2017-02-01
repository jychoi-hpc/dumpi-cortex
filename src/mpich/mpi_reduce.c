#include "cortex/cortex.h"
#include "cortex/mpich-constants.h"
#include "cortex/debug.h"
#include "cortex/profile.h"

static int reduce_binomial(const dumpi_reduce* prm,
			int rank,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg);

static int reduce_redscat_gather(const dumpi_reduce* prm,
			int rank,
			const dumpi_time *cpu,
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg);

/**
 * Translation of MPI_Reduce into point to point communications.
 */
int cortex_mpich_translate_MPI_Reduce(const dumpi_reduce *prm, 
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {

	thread = ((cortex_dumpi_profile*)uarg)->rank;

	int comm_size, type_size;
	type_size = cortex_datatype_get_size(uarg,prm->datatype);
	cortex_comm_get_size(uarg, prm->comm, &comm_size);
	int pof2 = 1;
	while (pof2 <= comm_size) pof2 <<= 1;
	pof2 >>=1;

	if((prm->count*type_size > CORTEX_REDUCE_SHORT_MSG_SIZE) && (prm->count >= pof2)) {
		INFO("Reduce for %d bytes and %d processes, use redcast-gather algorithm\n",(prm->count*type_size),comm_size);
		return reduce_redscat_gather(prm,thread,cpu,wall,perf,uarg);
	} else {
		INFO("Reduce for %d bytes and %d processes, use binomial algorithm\n",(prm->count*type_size),comm_size);
		return reduce_binomial(prm,thread,cpu,wall,perf,uarg);
	}

	return 0;
}

/**
 * This is the implementation of MPI_Reduce based on a binomial tree,
 * it can be found in the Mpich implementation in
 * mpich-3.1.4/src/mpi/coll/reduce.c line 79.
 *
 * TODO: here we assume op is commutative.
 * TODO: here we assume datatype is contiguous.
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
		recv_prm.tag		= MPICH_REDUCE_TAG;
		recv_prm.comm		= prm->comm;

	dumpi_send send_prm;
		send_prm.count		= prm->count;
		send_prm.datatype	= prm->datatype;
		send_prm.tag		= MPICH_REDUCE_TAG;
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

static int reduce_redscat_gather(const dumpi_reduce* prm,
				int rank,
				const dumpi_time *cpu,
				const dumpi_time *wall,
				const dumpi_perfinfo *perf,
				void *uarg)
{
	int comm_size, type_size, pof2, rem, newrank, mask;
	int recv_idx, last_idx=0, newdst, i, j, send_idx;
	int dst, send_cnt, recv_cnt, newroot, newdst_tree_root, newroot_tree_root;
	int *cnts, *disps;
	cnts = NULL;
	disps = NULL;

	cortex_comm_get_size(uarg, prm->comm, &comm_size);
	type_size = cortex_datatype_get_size(uarg,prm->datatype);
	
	pof2 = 1;
	while (pof2 <= comm_size) pof2 <<= 1;
	pof2 >>=1;
	
	rem = comm_size - pof2;

	if (rank < 2*rem) {
		if (rank % 2 != 0) { /* odd */

			dumpi_send send_prm;
				send_prm.count = prm->count;
				send_prm.datatype = prm->datatype;
				send_prm.dest = rank-1;
				send_prm.tag = MPICH_REDUCE_TAG;
				send_prm.comm = prm->comm;
			cortex_post_MPI_Send(&send_prm,cpu,wall,perf,uarg);

			newrank = -1;
		} else { /* even */
			dumpi_recv recv_prm;
				recv_prm.count = prm->count;
				recv_prm.datatype = prm->datatype;
				recv_prm.source = rank+1;
				recv_prm.tag = MPICH_REDUCE_TAG;
				recv_prm.comm = prm->comm;
			cortex_post_MPI_Recv(&recv_prm,cpu,wall,perf,uarg);

			newrank = rank / 2;
		}
	} else {
		newrank = rank - rem;
	}
	
	cnts = (int*)malloc(sizeof(int)*pof2);
	disps = (int*)malloc(sizeof(int)*pof2);

	if(newrank != -1) {
		for (i=0; i<(pof2-1); i++)
			cnts[i] = prm->count/pof2;
		cnts[pof2-1] = prm->count - (prm->count/pof2)*(pof2-1);

		disps[0] = 0;
		for (i=1; i<pof2; i++)
			disps[i] = disps[i-1] + cnts[i-1];

		mask = 0x1;
		send_idx = recv_idx = 0;
		last_idx = pof2;
		while(mask < pof2) {
			newdst = newrank ^ mask;

			dst = (newdst < rem) ? newdst*2 : newdst + rem;

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
				sr_prm.sendtag = CORTEX_REDUCE_TAG;
				sr_prm.recvcount = recv_cnt;
				sr_prm.recvtype = prm->datatype;
				sr_prm.source = dst,
				sr_prm.recvtag = CORTEX_REDUCE_TAG;
				sr_prm.comm = prm->comm;
			cortex_post_MPI_Sendrecv(&sr_prm,cpu,wall,perf,uarg);

			send_idx = recv_idx;
			mask <<= 1;

			if (mask < pof2)
				last_idx = recv_idx + pof2/mask;
		}
	}

	/* now do the gather to root */
	if (prm->root < 2*rem) {
		if (prm->root % 2 != 0) {
			if (rank == prm->root) {    /* recv */
				for (i=0; i<(pof2-1); i++)
					cnts[i] = prm->count/pof2;
				cnts[pof2-1] = prm->count - (prm->count/pof2)*(pof2-1);
				
				disps[0] = 0;
				for (i=1; i<pof2; i++)
					disps[i] = disps[i-1] + cnts[i-1];
				
				dumpi_recv recv_prm;
					recv_prm.count = cnts[0];
					recv_prm.datatype = prm->datatype;
					recv_prm.source = 0;
					recv_prm.tag = CORTEX_REDUCE_TAG;
					recv_prm.comm = prm->comm;
				cortex_post_MPI_Recv(&recv_prm,cpu,wall,perf,uarg);

				newrank = 0;
				send_idx = 0;
				last_idx = 2;
			} else if (newrank == 0) {  /* send */

				dumpi_send send_prm;
					send_prm.count = cnts[0];
					send_prm.datatype = prm->datatype;
					send_prm.dest = prm->root;
					send_prm.tag = CORTEX_REDUCE_TAG;
					send_prm.comm = prm->comm;
				cortex_post_MPI_Send(&send_prm,cpu,wall,perf,uarg);
			
				newrank = -1;
			}
			newroot = 0;
		} else newroot = prm->root / 2;
	}
	else
		newroot = prm->root - rem;

	if(newrank != -1) {
		j = 0;
		mask = 0x1;
		while (mask < pof2) {
			mask <<= 1;
			j++;
		}
		mask >>= 1;
		j--;
		while (mask > 0) {
			newdst = newrank ^ mask;

			dst = (newdst < rem) ? newdst*2 : newdst + rem;

			if ((newdst == 0) && (prm->root < 2*rem) && (prm->root % 2 != 0))
				dst = prm->root;

			newdst_tree_root = newdst >> j;
			newdst_tree_root <<= j;
	
			newroot_tree_root = newroot >> j;
			newroot_tree_root <<= j;

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

			if (newdst_tree_root == newroot_tree_root) {
				dumpi_send send_prm;
					send_prm.count = send_cnt;
					send_prm.datatype = prm->datatype;
					send_prm.dest = dst;
					send_prm.tag = CORTEX_REDUCE_TAG;
					send_prm.comm = prm->comm;
				cortex_post_MPI_Send(&send_prm,cpu,wall,perf,uarg);
				break;
			} else {
				dumpi_recv recv_prm;
					recv_prm.count = recv_cnt;
					recv_prm.datatype = prm->datatype;
					recv_prm.source = dst;
					recv_prm.tag = CORTEX_REDUCE_TAG;
					recv_prm.comm = prm->comm;
				cortex_post_MPI_Recv(&recv_prm,cpu,wall,perf,uarg);
			}

			if (newrank > newdst) send_idx = recv_idx;

			mask >>= 1;
			j--;
		}
	}
	
	if(cnts) free(cnts);
	if(disps) free(disps);

	return 0;
}

#include "cortex/cortex.h"
#include "cortex/mpich-constants.h"
#include "cortex/debug.h"
#include "cortex/profile.h"

/**
 * This translates MPI_Alltoallv calls into a series of
 * point to point calls. The following
 * algorithm was found in the Mpich implementation.
 */
int cortex_mpich_translate_MPI_Alltoallv(const dumpi_alltoallv *prm, 
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {
    printf ("\n %s", __FUNCTION__);
	thread = ((cortex_dumpi_profile*)uarg)->rank;

#ifdef MPICH_FORWARD
    cortex_post_MPI_Alltoallv(prm, thread, cpu, wall, perf, uarg);
#endif

	printf("\n cortex_mpich_translate_MPI_Alltoallv: comm=%d", prm->comm);
	thread = ((cortex_dumpi_profile*)uarg)->rank;
	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
	comm_info_t* comm = cortex_lookup(profile, prm->comm);

	int comm_size, i, j;
	int dst, rank, req_cnt, req_num = 1;
	int ii, ss, bblock;
	int type_size;

	INFO("Alltoallv using Mpich's algorithm with isend/irecv\n");

	dumpi_request* reqarray;
	dumpi_status* starray;

	dumpi_irecv irecv_param;
	dumpi_isend isend_param;
	dumpi_waitall waitall_param;

	cortex_comm_get_size(uarg, prm->comm, &comm_size);
	// rank = thread;
	rank = comm->wtol[thread];

	bblock = CORTEX_ALLTOALL_THROTTLE;

	starray = (dumpi_status*)malloc(2*bblock*sizeof(dumpi_status));
	reqarray = (dumpi_request*)malloc(2*bblock*sizeof(dumpi_request));
	
	for(ii=0; ii<comm_size; ii+=bblock) {

		req_cnt = 0;
		ss = comm_size-ii < bblock ? comm_size-ii : bblock;

		for ( i=0; i<ss; i++ ) {
			dst = (rank+i+ii) % comm_size;
			if (prm->recvcounts[dst]) {
				
					irecv_param.count	= prm->recvcounts[dst];
					irecv_param.datatype	= prm->recvtype;
					irecv_param.source	= dst;
					irecv_param.tag		= CORTEX_ALLTOALLV_TAG;
					irecv_param.comm	= prm->comm;
					irecv_param.request	= req_num++; // hopefuly the program is not doing other requests at the same time...
					reqarray[req_cnt] = irecv_param.request;
					// cortex_post_MPI_Irecv(&irecv_param, thread, cpu, wall, perf, uarg);
					cortex_post_MPI_Irecv(&irecv_param, rank, cpu, wall, perf, uarg);

					req_cnt++;
			}
		}

		for ( i=0; i<ss; i++ ) {
			dst = (rank-i-ii+comm_size) % comm_size;
			if (prm->sendcounts[dst]) {

					isend_param.count	= prm->sendcounts[dst];
					isend_param.datatype	= prm->sendtype;
					isend_param.dest 	= dst;
					isend_param.tag		= CORTEX_ALLTOALLV_TAG;
					isend_param.comm	= prm->comm;
					isend_param.request	= req_num++;

					reqarray[req_cnt] = isend_param.request;
					// cortex_post_MPI_Isend(&isend_param, thread, cpu, wall, perf, uarg);
					cortex_post_MPI_Isend(&isend_param, rank, cpu, wall, perf, uarg);

					req_cnt++;
			}
		}

		waitall_param.count = req_cnt;
		waitall_param.requests = reqarray;
		waitall_param.statuses = starray;

		// cortex_post_MPI_Waitall(&waitall_param, thread, cpu, wall, perf, uarg);
		cortex_post_MPI_Waitall(&waitall_param, rank, cpu, wall, perf, uarg);
	}

	free(starray);
	free(reqarray);

#ifdef MPICH_FORWARD
    cortex_post_MPI_Alltoallv(prm, thread, cpu, wall, perf, uarg);
#endif

	return 0;
}

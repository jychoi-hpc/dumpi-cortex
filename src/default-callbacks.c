/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */

#include <dumpi/libundumpi/callbacks.h>
#include <dumpi/common/argtypes.h>
#include <dumpi/common/constants.h>
#include "cortex/profile.h"
#include "cortex/operation.h"

#define CORTEX_FORWARD(fun,prm,thread,cpu,wall,perf) 			\
	struct cortex_dumpi_profile* profile = (struct cortex_dumpi_profile*)uarg; 	\
	cortex_post(profile, DU ## fun,prm,profile->rank,cpu,wall,perf);	\
	return 1

int  cortex_default_translate_MPI_Send(const dumpi_send *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Send, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Recv(const dumpi_recv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Recv, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Get_count(const dumpi_get_count *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get_count, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Bsend(const dumpi_bsend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Bsend, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Ssend(const dumpi_ssend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Ssend, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Rsend(const dumpi_rsend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Rsend, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Buffer_attach(const dumpi_buffer_attach *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Buffer_attach, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Buffer_detach(const dumpi_buffer_detach *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Buffer_detach, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Isend(const dumpi_isend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Isend, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Ibsend(const dumpi_ibsend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Ibsend, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Issend(const dumpi_issend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Issend, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Irsend(const dumpi_irsend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Irsend, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Irecv(const dumpi_irecv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Irecv, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Wait(const dumpi_wait *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Wait, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Test(const dumpi_test *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Test, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Request_free(const dumpi_request_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Request_free, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Waitany(const dumpi_waitany *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Waitany, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Testany(const dumpi_testany *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Testany, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Waitall(const dumpi_waitall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Waitall, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Testall(const dumpi_testall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Testall, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Waitsome(const dumpi_waitsome *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Waitsome, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Testsome(const dumpi_testsome *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Testsome, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Iprobe(const dumpi_iprobe *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Iprobe, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Probe(const dumpi_probe *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Probe, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Cancel(const dumpi_cancel *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cancel, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Test_cancelled(const dumpi_test_cancelled *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Test_cancelled, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Send_init(const dumpi_send_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Send_init, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Bsend_init(const dumpi_bsend_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Bsend_init, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Ssend_init(const dumpi_ssend_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Ssend_init, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Rsend_init(const dumpi_rsend_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Rsend_init, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Recv_init(const dumpi_recv_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Recv_init, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Start(const dumpi_start *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Start, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Startall(const dumpi_startall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Startall, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Sendrecv(const dumpi_sendrecv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Sendrecv, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Sendrecv_replace(const dumpi_sendrecv_replace *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Sendrecv_replace, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_contiguous(const dumpi_type_contiguous *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int size = cortex_datatype_get_size(uarg, prm->oldtype);
  size *= prm->count;
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_contiguous, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_vector(const dumpi_type_vector *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int size = cortex_datatype_get_size(uarg, prm->oldtype);
  size *= (prm->count * prm->blocklength);
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_vector, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_hvector(const dumpi_type_hvector *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int size = cortex_datatype_get_size(uarg, prm->oldtype);
  size *= (prm->count * prm->blocklength);
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_hvector, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_indexed(const dumpi_type_indexed *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int elem_size = cortex_datatype_get_size(uarg, prm->oldtype);
  int size = 0;
  int i;
  for(i=0; i < prm->count; i++) {
    size += prm->lengths[i];
  }
  size *= elem_size;
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_indexed, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_hindexed(const dumpi_type_hindexed *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int elem_size = cortex_datatype_get_size(uarg, prm->oldtype);
  int size = 0;
  int i;
  for(i=0; i < prm->count; i++) {
    size += prm->lengths[i];
  }
  size *= elem_size;
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_hindexed, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_struct(const dumpi_type_struct *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int size = 0;
  int i;
  for(i=0; i < prm->count; i++) {
    size += cortex_datatype_get_size(uarg, prm->oldtypes[i])*(prm->lengths[i]);
  }
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_struct, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Address(const dumpi_address *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Address, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_extent(const dumpi_type_extent *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_extent, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_size(const dumpi_type_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_size, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_lb(const dumpi_type_lb *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_lb, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_ub(const dumpi_type_ub *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_ub, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_commit(const dumpi_type_commit *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_commit, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_free(const dumpi_type_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_free, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Get_elements(const dumpi_get_elements *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get_elements, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Pack(const dumpi_pack *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Pack, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Unpack(const dumpi_unpack *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Unpack, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Pack_size(const dumpi_pack_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Pack_size, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Barrier(const dumpi_barrier *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Barrier, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Bcast(const dumpi_bcast *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Bcast, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Gather(const dumpi_gather *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Gather, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Gatherv(const dumpi_gatherv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Gatherv, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Scatter(const dumpi_scatter *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Scatter, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Scatterv(const dumpi_scatterv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Scatterv, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Allgather(const dumpi_allgather *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Allgather, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Allgatherv(const dumpi_allgatherv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Allgatherv, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Alltoall(const dumpi_alltoall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Alltoall, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Alltoallv(const dumpi_alltoallv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Alltoallv, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Reduce(const dumpi_reduce *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Reduce, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Op_create(const dumpi_op_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Op_create, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Op_free(const dumpi_op_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Op_free, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Allreduce(const dumpi_allreduce *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Allreduce, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Reduce_scatter(const dumpi_reduce_scatter *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Reduce_scatter, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Scan(const dumpi_scan *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Scan, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_size(const dumpi_group_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_size, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_rank(const dumpi_group_rank *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_rank, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_translate_ranks(const dumpi_group_translate_ranks *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_translate_ranks, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_compare(const dumpi_group_compare *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_compare, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_group(const dumpi_comm_group *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_group, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_union(const dumpi_group_union *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_union, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_intersection(const dumpi_group_intersection *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_intersection, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_difference(const dumpi_group_difference *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_difference, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_incl(const dumpi_group_incl *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_incl, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_excl(const dumpi_group_excl *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_excl, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_range_incl(const dumpi_group_range_incl *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_range_incl, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_range_excl(const dumpi_group_range_excl *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_range_excl, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Group_free(const dumpi_group_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_free, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_size(const dumpi_comm_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_size, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_rank(const dumpi_comm_rank *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_rank, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_compare(const dumpi_comm_compare *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_compare, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_dup(const dumpi_comm_dup *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_dup, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_create(const dumpi_comm_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_create, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_split(const dumpi_comm_split *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_split, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_free(const dumpi_comm_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_free, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_test_inter(const dumpi_comm_test_inter *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_test_inter, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_remote_size(const dumpi_comm_remote_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_remote_size, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_remote_group(const dumpi_comm_remote_group *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_remote_group, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Intercomm_create(const dumpi_intercomm_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Intercomm_create, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Intercomm_merge(const dumpi_intercomm_merge *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Intercomm_merge, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Keyval_create(const dumpi_keyval_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Keyval_create, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Keyval_free(const dumpi_keyval_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Keyval_free, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Attr_put(const dumpi_attr_put *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Attr_put, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Attr_get(const dumpi_attr_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Attr_get, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Attr_delete(const dumpi_attr_delete *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Attr_delete, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Topo_test(const dumpi_topo_test *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Topo_test, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Cart_create(const dumpi_cart_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_create, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Dims_create(const dumpi_dims_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Dims_create, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Graph_create(const dumpi_graph_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graph_create, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Graphdims_get(const dumpi_graphdims_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graphdims_get, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Graph_get(const dumpi_graph_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graph_get, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Cartdim_get(const dumpi_cartdim_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cartdim_get, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Cart_get(const dumpi_cart_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_get, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Cart_rank(const dumpi_cart_rank *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_rank, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Cart_coords(const dumpi_cart_coords *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_coords, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Graph_neighbors_count(const dumpi_graph_neighbors_count *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graph_neighbors_count, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Graph_neighbors(const dumpi_graph_neighbors *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graph_neighbors, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Cart_shift(const dumpi_cart_shift *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_shift, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Cart_sub(const dumpi_cart_sub *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_sub, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Cart_map(const dumpi_cart_map *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_map, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Graph_map(const dumpi_graph_map *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graph_map, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Get_processor_name(const dumpi_get_processor_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get_processor_name, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Get_version(const dumpi_get_version *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get_version, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Errhandler_create(const dumpi_errhandler_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Errhandler_create, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Errhandler_set(const dumpi_errhandler_set *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Errhandler_set, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Errhandler_get(const dumpi_errhandler_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Errhandler_get, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Errhandler_free(const dumpi_errhandler_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Errhandler_free, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Error_string(const dumpi_error_string *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Error_string, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Error_class(const dumpi_error_class *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Error_class, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Wtime(const dumpi_wtime *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Wtime, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Wtick(const dumpi_wtick *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Wtick, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Init(const dumpi_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Init, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Finalize(const dumpi_finalize *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Finalize, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Initialized(const dumpi_initialized *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Initialized, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Abort(const dumpi_abort *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Abort, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Close_port(const dumpi_close_port *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Close_port, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_accept(const dumpi_comm_accept *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_accept, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_connect(const dumpi_comm_connect *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_connect, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_disconnect(const dumpi_comm_disconnect *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_disconnect, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_get_parent(const dumpi_comm_get_parent *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_get_parent, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_join(const dumpi_comm_join *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_join, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_spawn(const dumpi_comm_spawn *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_spawn, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_spawn_multiple(const dumpi_comm_spawn_multiple *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_spawn_multiple, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Lookup_name(const dumpi_lookup_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Lookup_name, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Open_port(const dumpi_open_port *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Open_port, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Publish_name(const dumpi_publish_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Publish_name, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Unpublish_name(const dumpi_unpublish_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Unpublish_name, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Accumulate(const dumpi_accumulate *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Accumulate, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Get(const dumpi_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Put(const dumpi_put *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Put, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_complete(const dumpi_win_complete *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_complete, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_create(const dumpi_win_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_create, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_fence(const dumpi_win_fence *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_fence, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_free(const dumpi_win_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_free, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_get_group(const dumpi_win_get_group *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_get_group, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_lock(const dumpi_win_lock *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_lock, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_post(const dumpi_win_post *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_post, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_start(const dumpi_win_start *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_start, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_test(const dumpi_win_test *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_test, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_unlock(const dumpi_win_unlock *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_unlock, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_wait(const dumpi_win_wait *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_wait, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Alltoallw(const dumpi_alltoallw *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Alltoallw, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Exscan(const dumpi_exscan *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Exscan, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Add_error_class(const dumpi_add_error_class *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Add_error_class, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Add_error_code(const dumpi_add_error_code *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Add_error_code, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Add_error_string(const dumpi_add_error_string *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Add_error_string, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_call_errhandler(const dumpi_comm_call_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_call_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_create_keyval(const dumpi_comm_create_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_create_keyval, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_delete_attr(const dumpi_comm_delete_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_delete_attr, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_free_keyval(const dumpi_comm_free_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_free_keyval, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_get_attr(const dumpi_comm_get_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_get_attr, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_get_name(const dumpi_comm_get_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_get_name, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_set_attr(const dumpi_comm_set_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_set_attr, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_set_name(const dumpi_comm_set_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_set_name, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_call_errhandler(const dumpi_file_call_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_call_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Grequest_complete(const dumpi_grequest_complete *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Grequest_complete, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Grequest_start(const dumpi_grequest_start *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Grequest_start, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Init_thread(const dumpi_init_thread *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Init_thread, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Is_thread_main(const dumpi_is_thread_main *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Is_thread_main, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Query_thread(const dumpi_query_thread *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Query_thread, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Status_set_cancelled(const dumpi_status_set_cancelled *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Status_set_cancelled, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Status_set_elements(const dumpi_status_set_elements *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Status_set_elements, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_create_keyval(const dumpi_type_create_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_create_keyval, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_delete_attr(const dumpi_type_delete_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_delete_attr, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_dup(const dumpi_type_dup *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  cortex_datatype_dup(uarg,prm->oldtype,prm->newtype);
  CORTEX_FORWARD(MPI_Type_dup, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_free_keyval(const dumpi_type_free_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_free_keyval, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_get_attr(const dumpi_type_get_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_attr, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_get_contents(const dumpi_type_get_contents *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_contents, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_get_envelope(const dumpi_type_get_envelope *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_envelope, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_get_name(const dumpi_type_get_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_name, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_set_attr(const dumpi_type_set_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_set_attr, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_set_name(const dumpi_type_set_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_set_name, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_match_size(const dumpi_type_match_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_match_size, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_call_errhandler(const dumpi_win_call_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_call_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_create_keyval(const dumpi_win_create_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_create_keyval, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_delete_attr(const dumpi_win_delete_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_delete_attr, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_free_keyval(const dumpi_win_free_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_free_keyval, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_get_attr(const dumpi_win_get_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_get_attr, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_get_name(const dumpi_win_get_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_get_name, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_set_attr(const dumpi_win_set_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_set_attr, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_set_name(const dumpi_win_set_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_set_name, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Alloc_mem(const dumpi_alloc_mem *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Alloc_mem, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_create_errhandler(const dumpi_comm_create_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_create_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_get_errhandler(const dumpi_comm_get_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_get_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Comm_set_errhandler(const dumpi_comm_set_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_set_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_create_errhandler(const dumpi_file_create_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_create_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_errhandler(const dumpi_file_get_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_set_errhandler(const dumpi_file_set_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_set_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Finalized(const dumpi_finalized *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Finalized, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Free_mem(const dumpi_free_mem *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Free_mem, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Get_address(const dumpi_get_address *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get_address, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Info_create(const dumpi_info_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_create, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Info_delete(const dumpi_info_delete *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_delete, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Info_dup(const dumpi_info_dup *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_dup, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Info_free(const dumpi_info_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_free, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Info_get(const dumpi_info_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_get, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Info_get_nkeys(const dumpi_info_get_nkeys *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_get_nkeys, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Info_get_nthkey(const dumpi_info_get_nthkey *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_get_nthkey, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Info_get_valuelen(const dumpi_info_get_valuelen *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_get_valuelen, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Info_set(const dumpi_info_set *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_set, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Pack_external(const dumpi_pack_external *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Pack_external, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Pack_external_size(const dumpi_pack_external_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Pack_external_size, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Request_get_status(const dumpi_request_get_status *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Request_get_status, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_create_darray(const dumpi_type_create_darray *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  // TODO
  CORTEX_FORWARD(MPI_Type_create_darray, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_create_hindexed(const dumpi_type_create_hindexed *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int elem_size = cortex_datatype_get_size(uarg,prm->oldtype);
  int i;
  int size = 0;
  for(i=0; i< prm->count; i++) {
    size += prm->blocklengths[i];
  }
  size *= elem_size;
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_create_hindexed, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_create_hvector(const dumpi_type_create_hvector *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int elem_size = cortex_datatype_get_size(uarg,prm->oldtype);
  int size = elem_size * prm->count * prm->blocklength;
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_create_hvector, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_create_indexed_block(const dumpi_type_create_indexed_block *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int elem_size = cortex_datatype_get_size(uarg,prm->oldtype);
  int size = elem_size * prm->count * prm->blocklength;
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_create_indexed_block, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_create_resized(const dumpi_type_create_resized *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int size = cortex_datatype_get_size(uarg,prm->oldtype);
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_create_resized, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_create_struct(const dumpi_type_create_struct *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int size = 0;
  int i;
  for(i=0; i< prm->count; i++) {
    int elem_size = cortex_datatype_get_size(uarg,prm->oldtypes[i]);
    size += elem_size * prm->blocklengths[i];
  }
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_create_struct, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_create_subarray(const dumpi_type_create_subarray *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  int elem_size = cortex_datatype_get_size(uarg,prm->oldtype);
  int i;
  int size = elem_size;
  for(i=0; i < prm->ndims; i++) {
    size *= prm->subsizes[i];
  }
  cortex_datatype_add(uarg,prm->newtype,size);
  CORTEX_FORWARD(MPI_Type_create_subarray, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_get_extent(const dumpi_type_get_extent *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_extent, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Type_get_true_extent(const dumpi_type_get_true_extent *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_true_extent, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Unpack_external(const dumpi_unpack_external *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Unpack_external, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_create_errhandler(const dumpi_win_create_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_create_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_get_errhandler(const dumpi_win_get_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_get_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Win_set_errhandler(const dumpi_win_set_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_set_errhandler, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_open(const dumpi_file_open *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_open, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_close(const dumpi_file_close *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_close, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_delete(const dumpi_file_delete *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_delete, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_set_size(const dumpi_file_set_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_set_size, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_preallocate(const dumpi_file_preallocate *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_preallocate, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_size(const dumpi_file_get_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_size, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_group(const dumpi_file_get_group *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_group, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_amode(const dumpi_file_get_amode *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_amode, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_set_info(const dumpi_file_set_info *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_set_info, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_info(const dumpi_file_get_info *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_info, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_set_view(const dumpi_file_set_view *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_set_view, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_view(const dumpi_file_get_view *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_view, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_at(const dumpi_file_read_at *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_at, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_at_all(const dumpi_file_read_at_all *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_at_all, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_at(const dumpi_file_write_at *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_at, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_at_all(const dumpi_file_write_at_all *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_at_all, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_iread_at(const dumpi_file_iread_at *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iread_at, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_iwrite_at(const dumpi_file_iwrite_at *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iwrite_at, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read(const dumpi_file_read *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_all(const dumpi_file_read_all *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_all, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write(const dumpi_file_write *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_all(const dumpi_file_write_all *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_all, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_iread(const dumpi_file_iread *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iread, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_iwrite(const dumpi_file_iwrite *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iwrite, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_seek(const dumpi_file_seek *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_seek, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_position(const dumpi_file_get_position *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_position, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_byte_offset(const dumpi_file_get_byte_offset *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_byte_offset, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_shared(const dumpi_file_read_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_shared, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_shared(const dumpi_file_write_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_shared, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_iread_shared(const dumpi_file_iread_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iread_shared, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_iwrite_shared(const dumpi_file_iwrite_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iwrite_shared, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_ordered(const dumpi_file_read_ordered *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_ordered, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_ordered(const dumpi_file_write_ordered *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_ordered, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_seek_shared(const dumpi_file_seek_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_seek_shared, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_position_shared(const dumpi_file_get_position_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_position_shared, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_at_all_begin(const dumpi_file_read_at_all_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_at_all_begin, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_at_all_end(const dumpi_file_read_at_all_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_at_all_end, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_at_all_begin(const dumpi_file_write_at_all_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_at_all_begin, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_at_all_end(const dumpi_file_write_at_all_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_at_all_end, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_all_begin(const dumpi_file_read_all_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_all_begin, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_all_end(const dumpi_file_read_all_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_all_end, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_all_begin(const dumpi_file_write_all_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_all_begin, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_all_end(const dumpi_file_write_all_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_all_end, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_ordered_begin(const dumpi_file_read_ordered_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_ordered_begin, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_read_ordered_end(const dumpi_file_read_ordered_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_ordered_end, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_ordered_begin(const dumpi_file_write_ordered_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_ordered_begin, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_write_ordered_end(const dumpi_file_write_ordered_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_ordered_end, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_type_extent(const dumpi_file_get_type_extent *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_type_extent, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_Register_datarep(const dumpi_register_datarep *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Register_datarep, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_set_atomicity(const dumpi_file_set_atomicity *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_set_atomicity, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_get_atomicity(const dumpi_file_get_atomicity *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_atomicity, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPI_File_sync(const dumpi_file_sync *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_sync, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPIO_Test(const dumpio_test *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Test, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPIO_Wait(const dumpio_wait *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Wait, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPIO_Testall(const dumpio_testall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Testall, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPIO_Waitall(const dumpio_waitall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Waitall, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPIO_Testany(const dumpio_testany *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Testany, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPIO_Waitany(const dumpio_waitany *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Waitany, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPIO_Waitsome(const dumpio_waitsome *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Waitsome, prm, thread, cpu, wall, perf);
}

int  cortex_default_translate_MPIO_Testsome(const dumpio_testsome *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Testsome, prm, thread, cpu, wall, perf);
}

int  cortex_Function_enter(const dumpi_func_call *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  return 1;
}

int  cortex_Function_exit(const dumpi_func_call *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  return 1;
}

static libundumpi_callbacks cortex_no_translation = {
  .on_send                      =  cortex_default_translate_MPI_Send                     ,
  .on_recv                      =  cortex_default_translate_MPI_Recv                     ,
  .on_get_count                 =  cortex_default_translate_MPI_Get_count                ,
  .on_bsend                     =  cortex_default_translate_MPI_Bsend                    ,
  .on_ssend                     =  cortex_default_translate_MPI_Ssend                    ,
  .on_rsend                     =  cortex_default_translate_MPI_Rsend                    ,
  .on_buffer_attach             =  cortex_default_translate_MPI_Buffer_attach            ,
  .on_buffer_detach             =  cortex_default_translate_MPI_Buffer_detach            ,
  .on_isend                     =  cortex_default_translate_MPI_Isend                    ,
  .on_ibsend                    =  cortex_default_translate_MPI_Ibsend                   ,
  .on_issend                    =  cortex_default_translate_MPI_Issend                   ,
  .on_irsend                    =  cortex_default_translate_MPI_Irsend                   ,
  .on_irecv                     =  cortex_default_translate_MPI_Irecv                    ,
  .on_wait                      =  cortex_default_translate_MPI_Wait                     ,
  .on_test                      =  cortex_default_translate_MPI_Test                     ,
  .on_request_free              =  cortex_default_translate_MPI_Request_free             ,
  .on_waitany                   =  cortex_default_translate_MPI_Waitany                  ,
  .on_testany                   =  cortex_default_translate_MPI_Testany                  ,
  .on_waitall                   =  cortex_default_translate_MPI_Waitall                  ,
  .on_testall                   =  cortex_default_translate_MPI_Testall                  ,
  .on_waitsome                  =  cortex_default_translate_MPI_Waitsome                 ,
  .on_testsome                  =  cortex_default_translate_MPI_Testsome                 ,
  .on_iprobe                    =  cortex_default_translate_MPI_Iprobe                   ,
  .on_probe                     =  cortex_default_translate_MPI_Probe                    ,
  .on_cancel                    =  cortex_default_translate_MPI_Cancel                   ,
  .on_test_cancelled            =  cortex_default_translate_MPI_Test_cancelled           ,
  .on_send_init                 =  cortex_default_translate_MPI_Send_init                ,
  .on_bsend_init                =  cortex_default_translate_MPI_Bsend_init               ,
  .on_ssend_init                =  cortex_default_translate_MPI_Ssend_init               ,
  .on_rsend_init                =  cortex_default_translate_MPI_Rsend_init               ,
  .on_recv_init                 =  cortex_default_translate_MPI_Recv_init                ,
  .on_start                     =  cortex_default_translate_MPI_Start                    ,
  .on_startall                  =  cortex_default_translate_MPI_Startall                 ,
  .on_sendrecv                  =  cortex_default_translate_MPI_Sendrecv                 ,
  .on_sendrecv_replace          =  cortex_default_translate_MPI_Sendrecv_replace         ,
  .on_type_contiguous           =  cortex_default_translate_MPI_Type_contiguous          ,
  .on_type_vector               =  cortex_default_translate_MPI_Type_vector              ,
  .on_type_hvector              =  cortex_default_translate_MPI_Type_hvector             ,
  .on_type_indexed              =  cortex_default_translate_MPI_Type_indexed             ,
  .on_type_hindexed             =  cortex_default_translate_MPI_Type_hindexed            ,
  .on_type_struct               =  cortex_default_translate_MPI_Type_struct              ,
  .on_address                   =  cortex_default_translate_MPI_Address                  ,
  .on_type_extent               =  cortex_default_translate_MPI_Type_extent              ,
  .on_type_size                 =  cortex_default_translate_MPI_Type_size                ,
  .on_type_lb                   =  cortex_default_translate_MPI_Type_lb                  ,
  .on_type_ub                   =  cortex_default_translate_MPI_Type_ub                  ,
  .on_type_commit               =  cortex_default_translate_MPI_Type_commit              ,
  .on_type_free                 =  cortex_default_translate_MPI_Type_free                ,
  .on_get_elements              =  cortex_default_translate_MPI_Get_elements             ,
  .on_pack                      =  cortex_default_translate_MPI_Pack                     ,
  .on_unpack                    =  cortex_default_translate_MPI_Unpack                   ,
  .on_pack_size                 =  cortex_default_translate_MPI_Pack_size                ,
  .on_barrier                   =  cortex_default_translate_MPI_Barrier                  ,
  .on_bcast                     =  cortex_default_translate_MPI_Bcast                    ,
  .on_gather                    =  cortex_default_translate_MPI_Gather                   ,
  .on_gatherv                   =  cortex_default_translate_MPI_Gatherv                  ,
  .on_scatter                   =  cortex_default_translate_MPI_Scatter                  ,
  .on_scatterv                  =  cortex_default_translate_MPI_Scatterv                 ,
  .on_allgather                 =  cortex_default_translate_MPI_Allgather                ,
  .on_allgatherv                =  cortex_default_translate_MPI_Allgatherv               ,
  .on_alltoall                  =  cortex_default_translate_MPI_Alltoall                 ,
  .on_alltoallv                 =  cortex_default_translate_MPI_Alltoallv                ,
  .on_reduce                    =  cortex_default_translate_MPI_Reduce                   ,
  .on_op_create                 =  cortex_default_translate_MPI_Op_create                ,
  .on_op_free                   =  cortex_default_translate_MPI_Op_free                  ,
  .on_allreduce                 =  cortex_default_translate_MPI_Allreduce                ,
  .on_reduce_scatter            =  cortex_default_translate_MPI_Reduce_scatter           ,
  .on_scan                      =  cortex_default_translate_MPI_Scan                     ,
  .on_group_size                =  cortex_default_translate_MPI_Group_size               ,
  .on_group_rank                =  cortex_default_translate_MPI_Group_rank               ,
  .on_group_translate_ranks     =  cortex_default_translate_MPI_Group_translate_ranks    ,
  .on_group_compare             =  cortex_default_translate_MPI_Group_compare            ,
  .on_comm_group                =  cortex_default_translate_MPI_Comm_group               ,
  .on_group_union               =  cortex_default_translate_MPI_Group_union              ,
  .on_group_intersection        =  cortex_default_translate_MPI_Group_intersection       ,
  .on_group_difference          =  cortex_default_translate_MPI_Group_difference         ,
  .on_group_incl                =  cortex_default_translate_MPI_Group_incl               ,
  .on_group_excl                =  cortex_default_translate_MPI_Group_excl               ,
  .on_group_range_incl          =  cortex_default_translate_MPI_Group_range_incl         ,
  .on_group_range_excl          =  cortex_default_translate_MPI_Group_range_excl         ,
  .on_group_free                =  cortex_default_translate_MPI_Group_free               ,
  .on_comm_size                 =  cortex_default_translate_MPI_Comm_size                ,
  .on_comm_rank                 =  cortex_default_translate_MPI_Comm_rank                ,
  .on_comm_compare              =  cortex_default_translate_MPI_Comm_compare             ,
  .on_comm_dup                  =  cortex_default_translate_MPI_Comm_dup                 ,
  .on_comm_create               =  cortex_default_translate_MPI_Comm_create              ,
  .on_comm_split                =  cortex_default_translate_MPI_Comm_split               ,
  .on_comm_free                 =  cortex_default_translate_MPI_Comm_free                ,
  .on_comm_test_inter           =  cortex_default_translate_MPI_Comm_test_inter          ,
  .on_comm_remote_size          =  cortex_default_translate_MPI_Comm_remote_size         ,
  .on_comm_remote_group         =  cortex_default_translate_MPI_Comm_remote_group        ,
  .on_intercomm_create          =  cortex_default_translate_MPI_Intercomm_create         ,
  .on_intercomm_merge           =  cortex_default_translate_MPI_Intercomm_merge          ,
  .on_keyval_create             =  cortex_default_translate_MPI_Keyval_create            ,
  .on_keyval_free               =  cortex_default_translate_MPI_Keyval_free              ,
  .on_attr_put                  =  cortex_default_translate_MPI_Attr_put                 ,
  .on_attr_get                  =  cortex_default_translate_MPI_Attr_get                 ,
  .on_attr_delete               =  cortex_default_translate_MPI_Attr_delete              ,
  .on_topo_test                 =  cortex_default_translate_MPI_Topo_test                ,
  .on_cart_create               =  cortex_default_translate_MPI_Cart_create              ,
  .on_dims_create               =  cortex_default_translate_MPI_Dims_create              ,
  .on_graph_create              =  cortex_default_translate_MPI_Graph_create             ,
  .on_graphdims_get             =  cortex_default_translate_MPI_Graphdims_get            ,
  .on_graph_get                 =  cortex_default_translate_MPI_Graph_get                ,
  .on_cartdim_get               =  cortex_default_translate_MPI_Cartdim_get              ,
  .on_cart_get                  =  cortex_default_translate_MPI_Cart_get                 ,
  .on_cart_rank                 =  cortex_default_translate_MPI_Cart_rank                ,
  .on_cart_coords               =  cortex_default_translate_MPI_Cart_coords              ,
  .on_graph_neighbors_count     =  cortex_default_translate_MPI_Graph_neighbors_count    ,
  .on_graph_neighbors           =  cortex_default_translate_MPI_Graph_neighbors          ,
  .on_cart_shift                =  cortex_default_translate_MPI_Cart_shift               ,
  .on_cart_sub                  =  cortex_default_translate_MPI_Cart_sub                 ,
  .on_cart_map                  =  cortex_default_translate_MPI_Cart_map                 ,
  .on_graph_map                 =  cortex_default_translate_MPI_Graph_map                ,
  .on_get_processor_name        =  cortex_default_translate_MPI_Get_processor_name       ,
  .on_get_version               =  cortex_default_translate_MPI_Get_version              ,
  .on_errhandler_create         =  cortex_default_translate_MPI_Errhandler_create        ,
  .on_errhandler_set            =  cortex_default_translate_MPI_Errhandler_set           ,
  .on_errhandler_get            =  cortex_default_translate_MPI_Errhandler_get           ,
  .on_errhandler_free           =  cortex_default_translate_MPI_Errhandler_free          ,
  .on_error_string              =  cortex_default_translate_MPI_Error_string             ,
  .on_error_class               =  cortex_default_translate_MPI_Error_class              ,
  .on_wtime                     =  cortex_default_translate_MPI_Wtime                    ,
  .on_wtick                     =  cortex_default_translate_MPI_Wtick                    ,
  .on_init                      =  cortex_default_translate_MPI_Init                     ,
  .on_finalize                  =  cortex_default_translate_MPI_Finalize                 ,
  .on_initialized               =  cortex_default_translate_MPI_Initialized              ,
  .on_abort                     =  cortex_default_translate_MPI_Abort                    ,
  .on_close_port                =  cortex_default_translate_MPI_Close_port               ,
  .on_comm_accept               =  cortex_default_translate_MPI_Comm_accept              ,
  .on_comm_connect              =  cortex_default_translate_MPI_Comm_connect             ,
  .on_comm_disconnect           =  cortex_default_translate_MPI_Comm_disconnect          ,
  .on_comm_get_parent           =  cortex_default_translate_MPI_Comm_get_parent          ,
  .on_comm_join                 =  cortex_default_translate_MPI_Comm_join                ,
  .on_comm_spawn                =  cortex_default_translate_MPI_Comm_spawn               ,
  .on_comm_spawn_multiple       =  cortex_default_translate_MPI_Comm_spawn_multiple      ,
  .on_lookup_name               =  cortex_default_translate_MPI_Lookup_name              ,
  .on_open_port                 =  cortex_default_translate_MPI_Open_port                ,
  .on_publish_name              =  cortex_default_translate_MPI_Publish_name             ,
  .on_unpublish_name            =  cortex_default_translate_MPI_Unpublish_name           ,
  .on_accumulate                =  cortex_default_translate_MPI_Accumulate               ,
  .on_get                       =  cortex_default_translate_MPI_Get                      ,
  .on_put                       =  cortex_default_translate_MPI_Put                      ,
  .on_win_complete              =  cortex_default_translate_MPI_Win_complete             ,
  .on_win_create                =  cortex_default_translate_MPI_Win_create               ,
  .on_win_fence                 =  cortex_default_translate_MPI_Win_fence                ,
  .on_win_free                  =  cortex_default_translate_MPI_Win_free                 ,
  .on_win_get_group             =  cortex_default_translate_MPI_Win_get_group            ,
  .on_win_lock                  =  cortex_default_translate_MPI_Win_lock                 ,
  .on_win_post                  =  cortex_default_translate_MPI_Win_post                 ,
  .on_win_start                 =  cortex_default_translate_MPI_Win_start                ,
  .on_win_test                  =  cortex_default_translate_MPI_Win_test                 ,
  .on_win_unlock                =  cortex_default_translate_MPI_Win_unlock               ,
  .on_win_wait                  =  cortex_default_translate_MPI_Win_wait                 ,
  .on_alltoallw                 =  cortex_default_translate_MPI_Alltoallw                ,
  .on_exscan                    =  cortex_default_translate_MPI_Exscan                   ,
  .on_add_error_class           =  cortex_default_translate_MPI_Add_error_class          ,
  .on_add_error_code            =  cortex_default_translate_MPI_Add_error_code           ,
  .on_add_error_string          =  cortex_default_translate_MPI_Add_error_string         ,
  .on_comm_call_errhandler      =  cortex_default_translate_MPI_Comm_call_errhandler     ,
  .on_comm_create_keyval        =  cortex_default_translate_MPI_Comm_create_keyval       ,
  .on_comm_delete_attr          =  cortex_default_translate_MPI_Comm_delete_attr         ,
  .on_comm_free_keyval          =  cortex_default_translate_MPI_Comm_free_keyval         ,
  .on_comm_get_attr             =  cortex_default_translate_MPI_Comm_get_attr            ,
  .on_comm_get_name             =  cortex_default_translate_MPI_Comm_get_name            ,
  .on_comm_set_attr             =  cortex_default_translate_MPI_Comm_set_attr            ,
  .on_comm_set_name             =  cortex_default_translate_MPI_Comm_set_name            ,
  .on_file_call_errhandler      =  cortex_default_translate_MPI_File_call_errhandler     ,
  .on_grequest_complete         =  cortex_default_translate_MPI_Grequest_complete        ,
  .on_grequest_start            =  cortex_default_translate_MPI_Grequest_start           ,
  .on_init_thread               =  cortex_default_translate_MPI_Init_thread              ,
  .on_is_thread_main            =  cortex_default_translate_MPI_Is_thread_main           ,
  .on_query_thread              =  cortex_default_translate_MPI_Query_thread             ,
  .on_status_set_cancelled      =  cortex_default_translate_MPI_Status_set_cancelled     ,
  .on_status_set_elements       =  cortex_default_translate_MPI_Status_set_elements      ,
  .on_type_create_keyval        =  cortex_default_translate_MPI_Type_create_keyval       ,
  .on_type_delete_attr          =  cortex_default_translate_MPI_Type_delete_attr         ,
  .on_type_dup                  =  cortex_default_translate_MPI_Type_dup                 ,
  .on_type_free_keyval          =  cortex_default_translate_MPI_Type_free_keyval         ,
  .on_type_get_attr             =  cortex_default_translate_MPI_Type_get_attr            ,
  .on_type_get_contents         =  cortex_default_translate_MPI_Type_get_contents        ,
  .on_type_get_envelope         =  cortex_default_translate_MPI_Type_get_envelope        ,
  .on_type_get_name             =  cortex_default_translate_MPI_Type_get_name            ,
  .on_type_set_attr             =  cortex_default_translate_MPI_Type_set_attr            ,
  .on_type_set_name             =  cortex_default_translate_MPI_Type_set_name            ,
  .on_type_match_size           =  cortex_default_translate_MPI_Type_match_size          ,
  .on_win_call_errhandler       =  cortex_default_translate_MPI_Win_call_errhandler      ,
  .on_win_create_keyval         =  cortex_default_translate_MPI_Win_create_keyval        ,
  .on_win_delete_attr           =  cortex_default_translate_MPI_Win_delete_attr          ,
  .on_win_free_keyval           =  cortex_default_translate_MPI_Win_free_keyval          ,
  .on_win_get_attr              =  cortex_default_translate_MPI_Win_get_attr             ,
  .on_win_get_name              =  cortex_default_translate_MPI_Win_get_name             ,
  .on_win_set_attr              =  cortex_default_translate_MPI_Win_set_attr             ,
  .on_win_set_name              =  cortex_default_translate_MPI_Win_set_name             ,
  .on_alloc_mem                 =  cortex_default_translate_MPI_Alloc_mem                ,
  .on_comm_create_errhandler    =  cortex_default_translate_MPI_Comm_create_errhandler   ,
  .on_comm_get_errhandler       =  cortex_default_translate_MPI_Comm_get_errhandler      ,
  .on_comm_set_errhandler       =  cortex_default_translate_MPI_Comm_set_errhandler      ,
  .on_file_create_errhandler    =  cortex_default_translate_MPI_File_create_errhandler   ,
  .on_file_get_errhandler       =  cortex_default_translate_MPI_File_get_errhandler      ,
  .on_file_set_errhandler       =  cortex_default_translate_MPI_File_set_errhandler      ,
  .on_finalized                 =  cortex_default_translate_MPI_Finalized                ,
  .on_free_mem                  =  cortex_default_translate_MPI_Free_mem                 ,
  .on_get_address               =  cortex_default_translate_MPI_Get_address              ,
  .on_info_create               =  cortex_default_translate_MPI_Info_create              ,
  .on_info_delete               =  cortex_default_translate_MPI_Info_delete              ,
  .on_info_dup                  =  cortex_default_translate_MPI_Info_dup                 ,
  .on_info_free                 =  cortex_default_translate_MPI_Info_free                ,
  .on_info_get                  =  cortex_default_translate_MPI_Info_get                 ,
  .on_info_get_nkeys            =  cortex_default_translate_MPI_Info_get_nkeys           ,
  .on_info_get_nthkey           =  cortex_default_translate_MPI_Info_get_nthkey          ,
  .on_info_get_valuelen         =  cortex_default_translate_MPI_Info_get_valuelen        ,
  .on_info_set                  =  cortex_default_translate_MPI_Info_set                 ,
  .on_pack_external             =  cortex_default_translate_MPI_Pack_external            ,
  .on_pack_external_size        =  cortex_default_translate_MPI_Pack_external_size       ,
  .on_request_get_status        =  cortex_default_translate_MPI_Request_get_status       ,
  .on_type_create_darray        =  cortex_default_translate_MPI_Type_create_darray       ,
  .on_type_create_hindexed      =  cortex_default_translate_MPI_Type_create_hindexed     ,
  .on_type_create_hvector       =  cortex_default_translate_MPI_Type_create_hvector      ,
  .on_type_create_indexed_block =  cortex_default_translate_MPI_Type_create_indexed_block,
  .on_type_create_resized       =  cortex_default_translate_MPI_Type_create_resized      ,
  .on_type_create_struct        =  cortex_default_translate_MPI_Type_create_struct       ,
  .on_type_create_subarray      =  cortex_default_translate_MPI_Type_create_subarray     ,
  .on_type_get_extent           =  cortex_default_translate_MPI_Type_get_extent          ,
  .on_type_get_true_extent      =  cortex_default_translate_MPI_Type_get_true_extent     ,
  .on_unpack_external           =  cortex_default_translate_MPI_Unpack_external          ,
  .on_win_create_errhandler     =  cortex_default_translate_MPI_Win_create_errhandler    ,
  .on_win_get_errhandler        =  cortex_default_translate_MPI_Win_get_errhandler       ,
  .on_win_set_errhandler        =  cortex_default_translate_MPI_Win_set_errhandler       ,
  .on_file_open                 =  cortex_default_translate_MPI_File_open                ,
  .on_file_close                =  cortex_default_translate_MPI_File_close               ,
  .on_file_delete               =  cortex_default_translate_MPI_File_delete              ,
  .on_file_set_size             =  cortex_default_translate_MPI_File_set_size            ,
  .on_file_preallocate          =  cortex_default_translate_MPI_File_preallocate         ,
  .on_file_get_size             =  cortex_default_translate_MPI_File_get_size            ,
  .on_file_get_group            =  cortex_default_translate_MPI_File_get_group           ,
  .on_file_get_amode            =  cortex_default_translate_MPI_File_get_amode           ,
  .on_file_set_info             =  cortex_default_translate_MPI_File_set_info            ,
  .on_file_get_info             =  cortex_default_translate_MPI_File_get_info            ,
  .on_file_set_view             =  cortex_default_translate_MPI_File_set_view            ,
  .on_file_get_view             =  cortex_default_translate_MPI_File_get_view            ,
  .on_file_read_at              =  cortex_default_translate_MPI_File_read_at             ,
  .on_file_read_at_all          =  cortex_default_translate_MPI_File_read_at_all         ,
  .on_file_write_at             =  cortex_default_translate_MPI_File_write_at            ,
  .on_file_write_at_all         =  cortex_default_translate_MPI_File_write_at_all        ,
  .on_file_iread_at             =  cortex_default_translate_MPI_File_iread_at            ,
  .on_file_iwrite_at            =  cortex_default_translate_MPI_File_iwrite_at           ,
  .on_file_read                 =  cortex_default_translate_MPI_File_read                ,
  .on_file_read_all             =  cortex_default_translate_MPI_File_read_all            ,
  .on_file_write                =  cortex_default_translate_MPI_File_write               ,
  .on_file_write_all            =  cortex_default_translate_MPI_File_write_all           ,
  .on_file_iread                =  cortex_default_translate_MPI_File_iread               ,
  .on_file_iwrite               =  cortex_default_translate_MPI_File_iwrite              ,
  .on_file_seek                 =  cortex_default_translate_MPI_File_seek                ,
  .on_file_get_position         =  cortex_default_translate_MPI_File_get_position        ,
  .on_file_get_byte_offset      =  cortex_default_translate_MPI_File_get_byte_offset     ,
  .on_file_read_shared          =  cortex_default_translate_MPI_File_read_shared         ,
  .on_file_write_shared         =  cortex_default_translate_MPI_File_write_shared        ,
  .on_file_iread_shared         =  cortex_default_translate_MPI_File_iread_shared        ,
  .on_file_iwrite_shared        =  cortex_default_translate_MPI_File_iwrite_shared       ,
  .on_file_read_ordered         =  cortex_default_translate_MPI_File_read_ordered        ,
  .on_file_write_ordered        =  cortex_default_translate_MPI_File_write_ordered       ,
  .on_file_seek_shared          =  cortex_default_translate_MPI_File_seek_shared         ,
  .on_file_get_position_shared  =  cortex_default_translate_MPI_File_get_position_shared ,
  .on_file_read_at_all_begin    =  cortex_default_translate_MPI_File_read_at_all_begin   ,
  .on_file_read_at_all_end      =  cortex_default_translate_MPI_File_read_at_all_end     ,
  .on_file_write_at_all_begin   =  cortex_default_translate_MPI_File_write_at_all_begin  ,
  .on_file_write_at_all_end     =  cortex_default_translate_MPI_File_write_at_all_end    ,
  .on_file_read_all_begin       =  cortex_default_translate_MPI_File_read_all_begin      ,
  .on_file_read_all_end         =  cortex_default_translate_MPI_File_read_all_end        ,
  .on_file_write_all_begin      =  cortex_default_translate_MPI_File_write_all_begin     ,
  .on_file_write_all_end        =  cortex_default_translate_MPI_File_write_all_end       ,
  .on_file_read_ordered_begin   =  cortex_default_translate_MPI_File_read_ordered_begin  ,
  .on_file_read_ordered_end     =  cortex_default_translate_MPI_File_read_ordered_end    ,
  .on_file_write_ordered_begin  =  cortex_default_translate_MPI_File_write_ordered_begin ,
  .on_file_write_ordered_end    =  cortex_default_translate_MPI_File_write_ordered_end   ,
  .on_file_get_type_extent      =  cortex_default_translate_MPI_File_get_type_extent     ,
  .on_register_datarep          =  cortex_default_translate_MPI_Register_datarep         ,
  .on_file_set_atomicity        =  cortex_default_translate_MPI_File_set_atomicity       ,
  .on_file_get_atomicity        =  cortex_default_translate_MPI_File_get_atomicity       ,
  .on_file_sync                 =  cortex_default_translate_MPI_File_sync                ,
  .on_iotest                    =  cortex_default_translate_MPIO_Test                    ,
  .on_iowait                    =  cortex_default_translate_MPIO_Wait                    ,
  .on_iotestall                 =  cortex_default_translate_MPIO_Testall                 ,
  .on_iowaitall                 =  cortex_default_translate_MPIO_Waitall                 ,
  .on_iotestany                 =  cortex_default_translate_MPIO_Testany                 ,
  .on_iowaitany                 =  cortex_default_translate_MPIO_Waitany                 ,
  .on_iowaitsome                =  cortex_default_translate_MPIO_Waitsome                ,
  .on_iotestsome                =  cortex_default_translate_MPIO_Testsome                ,
  .on_function_enter            =  cortex_Function_enter                                 ,
  .on_function_exit             =  cortex_Function_exit                                  
};

const libundumpi_callbacks* CORTEX_NO_TRANSLATION = &cortex_no_translation;

#undef CORTEX_FORWARD

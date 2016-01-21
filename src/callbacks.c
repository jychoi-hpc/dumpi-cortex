#include "cortex/cortex.h"
#include "cortex/callbacks.h"
#include <dumpi/libundumpi/callbacks.h>
#include <dumpi/common/argtypes.h>
#include <dumpi/common/constants.h>
#include <assert.h>
#include <stdio.h>

#define CORTEX_FORWARD(fun,prm,thread,cpu,wall,perf) 			\
	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg; 	\
	cortex_post(profile, DU ## fun,prm,thread,cpu,wall,perf);	\
	return 1

int __attribute__((weak)) cortex_translate_MPI_Send(const dumpi_send *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Send, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Recv(const dumpi_recv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Recv, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Get_count(const dumpi_get_count *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get_count, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Bsend(const dumpi_bsend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Bsend, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Ssend(const dumpi_ssend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Ssend, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Rsend(const dumpi_rsend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Rsend, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Buffer_attach(const dumpi_buffer_attach *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Buffer_attach, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Buffer_detach(const dumpi_buffer_detach *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Buffer_detach, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Isend(const dumpi_isend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Isend, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Ibsend(const dumpi_ibsend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Ibsend, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Issend(const dumpi_issend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Issend, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Irsend(const dumpi_irsend *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Irsend, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Irecv(const dumpi_irecv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Irecv, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Wait(const dumpi_wait *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Wait, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Test(const dumpi_test *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Test, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Request_free(const dumpi_request_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Request_free, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Waitany(const dumpi_waitany *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Waitany, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Testany(const dumpi_testany *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Testany, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Waitall(const dumpi_waitall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Waitall, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Testall(const dumpi_testall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Testall, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Waitsome(const dumpi_waitsome *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Waitsome, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Testsome(const dumpi_testsome *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Testsome, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Iprobe(const dumpi_iprobe *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Iprobe, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Probe(const dumpi_probe *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Probe, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Cancel(const dumpi_cancel *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cancel, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Test_cancelled(const dumpi_test_cancelled *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Test_cancelled, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Send_init(const dumpi_send_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Send_init, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Bsend_init(const dumpi_bsend_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Bsend_init, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Ssend_init(const dumpi_ssend_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Ssend_init, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Rsend_init(const dumpi_rsend_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Rsend_init, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Recv_init(const dumpi_recv_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Recv_init, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Start(const dumpi_start *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Start, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Startall(const dumpi_startall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Startall, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Sendrecv(const dumpi_sendrecv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Sendrecv, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Sendrecv_replace(const dumpi_sendrecv_replace *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Sendrecv_replace, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_contiguous(const dumpi_type_contiguous *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_contiguous, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_vector(const dumpi_type_vector *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_vector, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_hvector(const dumpi_type_hvector *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_hvector, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_indexed(const dumpi_type_indexed *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_indexed, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_hindexed(const dumpi_type_hindexed *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_hindexed, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_struct(const dumpi_type_struct *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_struct, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Address(const dumpi_address *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Address, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_extent(const dumpi_type_extent *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_extent, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_size(const dumpi_type_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_size, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_lb(const dumpi_type_lb *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_lb, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_ub(const dumpi_type_ub *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_ub, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_commit(const dumpi_type_commit *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_commit, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_free(const dumpi_type_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_free, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Get_elements(const dumpi_get_elements *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get_elements, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Pack(const dumpi_pack *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Pack, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Unpack(const dumpi_unpack *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Unpack, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Pack_size(const dumpi_pack_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Pack_size, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Barrier(const dumpi_barrier *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Barrier, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Bcast(const dumpi_bcast *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Bcast, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Gather(const dumpi_gather *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Gather, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Gatherv(const dumpi_gatherv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Gatherv, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Scatter(const dumpi_scatter *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Scatter, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Scatterv(const dumpi_scatterv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Scatterv, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Allgather(const dumpi_allgather *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Allgather, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Allgatherv(const dumpi_allgatherv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Allgatherv, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Alltoall(const dumpi_alltoall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Alltoall, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Alltoallv(const dumpi_alltoallv *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Alltoallv, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Reduce(const dumpi_reduce *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Reduce, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Op_create(const dumpi_op_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Op_create, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Op_free(const dumpi_op_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Op_free, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Allreduce(const dumpi_allreduce *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Allreduce, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Reduce_scatter(const dumpi_reduce_scatter *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Reduce_scatter, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Scan(const dumpi_scan *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Scan, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_size(const dumpi_group_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_size, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_rank(const dumpi_group_rank *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_rank, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_translate_ranks(const dumpi_group_translate_ranks *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_translate_ranks, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_compare(const dumpi_group_compare *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_compare, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_group(const dumpi_comm_group *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_group, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_union(const dumpi_group_union *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_union, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_intersection(const dumpi_group_intersection *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_intersection, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_difference(const dumpi_group_difference *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_difference, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_incl(const dumpi_group_incl *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_incl, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_excl(const dumpi_group_excl *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_excl, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_range_incl(const dumpi_group_range_incl *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_range_incl, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_range_excl(const dumpi_group_range_excl *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_range_excl, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Group_free(const dumpi_group_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Group_free, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_size(const dumpi_comm_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_size, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_rank(const dumpi_comm_rank *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_rank, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_compare(const dumpi_comm_compare *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_compare, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_dup(const dumpi_comm_dup *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_dup, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_create(const dumpi_comm_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_create, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_split(const dumpi_comm_split *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_split, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_free(const dumpi_comm_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_free, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_test_inter(const dumpi_comm_test_inter *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_test_inter, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_remote_size(const dumpi_comm_remote_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_remote_size, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_remote_group(const dumpi_comm_remote_group *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_remote_group, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Intercomm_create(const dumpi_intercomm_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Intercomm_create, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Intercomm_merge(const dumpi_intercomm_merge *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Intercomm_merge, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Keyval_create(const dumpi_keyval_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Keyval_create, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Keyval_free(const dumpi_keyval_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Keyval_free, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Attr_put(const dumpi_attr_put *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Attr_put, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Attr_get(const dumpi_attr_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Attr_get, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Attr_delete(const dumpi_attr_delete *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Attr_delete, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Topo_test(const dumpi_topo_test *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Topo_test, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Cart_create(const dumpi_cart_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_create, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Dims_create(const dumpi_dims_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Dims_create, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Graph_create(const dumpi_graph_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graph_create, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Graphdims_get(const dumpi_graphdims_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graphdims_get, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Graph_get(const dumpi_graph_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graph_get, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Cartdim_get(const dumpi_cartdim_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cartdim_get, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Cart_get(const dumpi_cart_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_get, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Cart_rank(const dumpi_cart_rank *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_rank, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Cart_coords(const dumpi_cart_coords *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_coords, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Graph_neighbors_count(const dumpi_graph_neighbors_count *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graph_neighbors_count, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Graph_neighbors(const dumpi_graph_neighbors *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graph_neighbors, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Cart_shift(const dumpi_cart_shift *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_shift, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Cart_sub(const dumpi_cart_sub *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_sub, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Cart_map(const dumpi_cart_map *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Cart_map, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Graph_map(const dumpi_graph_map *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Graph_map, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Get_processor_name(const dumpi_get_processor_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get_processor_name, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Get_version(const dumpi_get_version *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get_version, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Errhandler_create(const dumpi_errhandler_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Errhandler_create, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Errhandler_set(const dumpi_errhandler_set *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Errhandler_set, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Errhandler_get(const dumpi_errhandler_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Errhandler_get, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Errhandler_free(const dumpi_errhandler_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Errhandler_free, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Error_string(const dumpi_error_string *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Error_string, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Error_class(const dumpi_error_class *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Error_class, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Wtime(const dumpi_wtime *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Wtime, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Wtick(const dumpi_wtick *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Wtick, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Init(const dumpi_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Init, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Finalize(const dumpi_finalize *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Finalize, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Initialized(const dumpi_initialized *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Initialized, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Abort(const dumpi_abort *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Abort, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Close_port(const dumpi_close_port *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Close_port, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_accept(const dumpi_comm_accept *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_accept, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_connect(const dumpi_comm_connect *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_connect, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_disconnect(const dumpi_comm_disconnect *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_disconnect, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_get_parent(const dumpi_comm_get_parent *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_get_parent, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_join(const dumpi_comm_join *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_join, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_spawn(const dumpi_comm_spawn *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_spawn, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_spawn_multiple(const dumpi_comm_spawn_multiple *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_spawn_multiple, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Lookup_name(const dumpi_lookup_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Lookup_name, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Open_port(const dumpi_open_port *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Open_port, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Publish_name(const dumpi_publish_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Publish_name, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Unpublish_name(const dumpi_unpublish_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Unpublish_name, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Accumulate(const dumpi_accumulate *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Accumulate, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Get(const dumpi_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Put(const dumpi_put *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Put, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_complete(const dumpi_win_complete *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_complete, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_create(const dumpi_win_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_create, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_fence(const dumpi_win_fence *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_fence, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_free(const dumpi_win_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_free, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_get_group(const dumpi_win_get_group *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_get_group, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_lock(const dumpi_win_lock *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_lock, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_post(const dumpi_win_post *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_post, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_start(const dumpi_win_start *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_start, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_test(const dumpi_win_test *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_test, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_unlock(const dumpi_win_unlock *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_unlock, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_wait(const dumpi_win_wait *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_wait, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Alltoallw(const dumpi_alltoallw *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Alltoallw, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Exscan(const dumpi_exscan *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Exscan, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Add_error_class(const dumpi_add_error_class *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Add_error_class, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Add_error_code(const dumpi_add_error_code *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Add_error_code, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Add_error_string(const dumpi_add_error_string *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Add_error_string, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_call_errhandler(const dumpi_comm_call_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_call_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_create_keyval(const dumpi_comm_create_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_create_keyval, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_delete_attr(const dumpi_comm_delete_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_delete_attr, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_free_keyval(const dumpi_comm_free_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_free_keyval, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_get_attr(const dumpi_comm_get_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_get_attr, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_get_name(const dumpi_comm_get_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_get_name, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_set_attr(const dumpi_comm_set_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_set_attr, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_set_name(const dumpi_comm_set_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_set_name, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_call_errhandler(const dumpi_file_call_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_call_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Grequest_complete(const dumpi_grequest_complete *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Grequest_complete, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Grequest_start(const dumpi_grequest_start *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Grequest_start, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Init_thread(const dumpi_init_thread *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Init_thread, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Is_thread_main(const dumpi_is_thread_main *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Is_thread_main, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Query_thread(const dumpi_query_thread *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Query_thread, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Status_set_cancelled(const dumpi_status_set_cancelled *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Status_set_cancelled, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Status_set_elements(const dumpi_status_set_elements *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Status_set_elements, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_create_keyval(const dumpi_type_create_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_create_keyval, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_delete_attr(const dumpi_type_delete_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_delete_attr, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_dup(const dumpi_type_dup *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_dup, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_free_keyval(const dumpi_type_free_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_free_keyval, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_get_attr(const dumpi_type_get_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_attr, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_get_contents(const dumpi_type_get_contents *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_contents, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_get_envelope(const dumpi_type_get_envelope *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_envelope, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_get_name(const dumpi_type_get_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_name, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_set_attr(const dumpi_type_set_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_set_attr, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_set_name(const dumpi_type_set_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_set_name, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_match_size(const dumpi_type_match_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_match_size, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_call_errhandler(const dumpi_win_call_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_call_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_create_keyval(const dumpi_win_create_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_create_keyval, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_delete_attr(const dumpi_win_delete_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_delete_attr, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_free_keyval(const dumpi_win_free_keyval *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_free_keyval, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_get_attr(const dumpi_win_get_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_get_attr, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_get_name(const dumpi_win_get_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_get_name, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_set_attr(const dumpi_win_set_attr *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_set_attr, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_set_name(const dumpi_win_set_name *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_set_name, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Alloc_mem(const dumpi_alloc_mem *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Alloc_mem, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_create_errhandler(const dumpi_comm_create_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_create_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_get_errhandler(const dumpi_comm_get_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_get_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Comm_set_errhandler(const dumpi_comm_set_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Comm_set_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_create_errhandler(const dumpi_file_create_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_create_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_errhandler(const dumpi_file_get_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_set_errhandler(const dumpi_file_set_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_set_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Finalized(const dumpi_finalized *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Finalized, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Free_mem(const dumpi_free_mem *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Free_mem, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Get_address(const dumpi_get_address *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Get_address, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Info_create(const dumpi_info_create *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_create, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Info_delete(const dumpi_info_delete *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_delete, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Info_dup(const dumpi_info_dup *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_dup, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Info_free(const dumpi_info_free *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_free, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Info_get(const dumpi_info_get *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_get, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Info_get_nkeys(const dumpi_info_get_nkeys *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_get_nkeys, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Info_get_nthkey(const dumpi_info_get_nthkey *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_get_nthkey, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Info_get_valuelen(const dumpi_info_get_valuelen *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_get_valuelen, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Info_set(const dumpi_info_set *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Info_set, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Pack_external(const dumpi_pack_external *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Pack_external, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Pack_external_size(const dumpi_pack_external_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Pack_external_size, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Request_get_status(const dumpi_request_get_status *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Request_get_status, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_create_darray(const dumpi_type_create_darray *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_create_darray, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_create_hindexed(const dumpi_type_create_hindexed *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_create_hindexed, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_create_hvector(const dumpi_type_create_hvector *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_create_hvector, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_create_indexed_block(const dumpi_type_create_indexed_block *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_create_indexed_block, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_create_resized(const dumpi_type_create_resized *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_create_resized, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_create_struct(const dumpi_type_create_struct *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_create_struct, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_create_subarray(const dumpi_type_create_subarray *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_create_subarray, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_get_extent(const dumpi_type_get_extent *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_extent, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Type_get_true_extent(const dumpi_type_get_true_extent *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Type_get_true_extent, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Unpack_external(const dumpi_unpack_external *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Unpack_external, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_create_errhandler(const dumpi_win_create_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_create_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_get_errhandler(const dumpi_win_get_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_get_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Win_set_errhandler(const dumpi_win_set_errhandler *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Win_set_errhandler, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_open(const dumpi_file_open *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_open, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_close(const dumpi_file_close *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_close, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_delete(const dumpi_file_delete *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_delete, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_set_size(const dumpi_file_set_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_set_size, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_preallocate(const dumpi_file_preallocate *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_preallocate, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_size(const dumpi_file_get_size *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_size, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_group(const dumpi_file_get_group *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_group, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_amode(const dumpi_file_get_amode *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_amode, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_set_info(const dumpi_file_set_info *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_set_info, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_info(const dumpi_file_get_info *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_info, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_set_view(const dumpi_file_set_view *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_set_view, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_view(const dumpi_file_get_view *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_view, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_at(const dumpi_file_read_at *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_at, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_at_all(const dumpi_file_read_at_all *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_at_all, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_at(const dumpi_file_write_at *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_at, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_at_all(const dumpi_file_write_at_all *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_at_all, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_iread_at(const dumpi_file_iread_at *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iread_at, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_iwrite_at(const dumpi_file_iwrite_at *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iwrite_at, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read(const dumpi_file_read *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_all(const dumpi_file_read_all *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_all, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write(const dumpi_file_write *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_all(const dumpi_file_write_all *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_all, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_iread(const dumpi_file_iread *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iread, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_iwrite(const dumpi_file_iwrite *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iwrite, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_seek(const dumpi_file_seek *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_seek, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_position(const dumpi_file_get_position *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_position, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_byte_offset(const dumpi_file_get_byte_offset *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_byte_offset, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_shared(const dumpi_file_read_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_shared, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_shared(const dumpi_file_write_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_shared, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_iread_shared(const dumpi_file_iread_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iread_shared, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_iwrite_shared(const dumpi_file_iwrite_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_iwrite_shared, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_ordered(const dumpi_file_read_ordered *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_ordered, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_ordered(const dumpi_file_write_ordered *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_ordered, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_seek_shared(const dumpi_file_seek_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_seek_shared, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_position_shared(const dumpi_file_get_position_shared *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_position_shared, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_at_all_begin(const dumpi_file_read_at_all_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_at_all_begin, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_at_all_end(const dumpi_file_read_at_all_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_at_all_end, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_at_all_begin(const dumpi_file_write_at_all_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_at_all_begin, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_at_all_end(const dumpi_file_write_at_all_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_at_all_end, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_all_begin(const dumpi_file_read_all_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_all_begin, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_all_end(const dumpi_file_read_all_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_all_end, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_all_begin(const dumpi_file_write_all_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_all_begin, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_all_end(const dumpi_file_write_all_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_all_end, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_ordered_begin(const dumpi_file_read_ordered_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_ordered_begin, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_read_ordered_end(const dumpi_file_read_ordered_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_read_ordered_end, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_ordered_begin(const dumpi_file_write_ordered_begin *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_ordered_begin, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_write_ordered_end(const dumpi_file_write_ordered_end *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_write_ordered_end, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_type_extent(const dumpi_file_get_type_extent *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_type_extent, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_Register_datarep(const dumpi_register_datarep *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_Register_datarep, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_set_atomicity(const dumpi_file_set_atomicity *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_set_atomicity, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_get_atomicity(const dumpi_file_get_atomicity *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_get_atomicity, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPI_File_sync(const dumpi_file_sync *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPI_File_sync, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPIO_Test(const dumpio_test *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Test, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPIO_Wait(const dumpio_wait *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Wait, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPIO_Testall(const dumpio_testall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Testall, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPIO_Waitall(const dumpio_waitall *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Waitall, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPIO_Testany(const dumpio_testany *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Testany, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPIO_Waitany(const dumpio_waitany *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Waitany, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPIO_Waitsome(const dumpio_waitsome *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Waitsome, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_translate_MPIO_Testsome(const dumpio_testsome *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  CORTEX_FORWARD(MPIO_Testsome, prm, thread, cpu, wall, perf);
}

int __attribute__((weak)) cortex_Function_enter(const dumpi_func_call *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  return 1;
}

int __attribute__((weak)) cortex_Function_exit(const dumpi_func_call *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
  return 1;
}

void cortex_set_callbacks(libundumpi_callbacks *cbacks) {
  assert(cbacks != NULL);
  cbacks->on_send                      = cortex_translate_MPI_Send                     ;
  cbacks->on_recv                      = cortex_translate_MPI_Recv                     ;
  cbacks->on_get_count                 = cortex_translate_MPI_Get_count                ;
  cbacks->on_bsend                     = cortex_translate_MPI_Bsend                    ;
  cbacks->on_ssend                     = cortex_translate_MPI_Ssend                    ;
  cbacks->on_rsend                     =  cortex_translate_MPI_Rsend                    ;
  cbacks->on_buffer_attach             =  cortex_translate_MPI_Buffer_attach            ;
  cbacks->on_buffer_detach             =  cortex_translate_MPI_Buffer_detach            ;
  cbacks->on_isend                     =  cortex_translate_MPI_Isend                    ;
  cbacks->on_ibsend                    =  cortex_translate_MPI_Ibsend                   ;
  cbacks->on_issend                    =  cortex_translate_MPI_Issend                   ;
  cbacks->on_irsend                    =  cortex_translate_MPI_Irsend                   ;
  cbacks->on_irecv                     =  cortex_translate_MPI_Irecv                    ;
  cbacks->on_wait                      =  cortex_translate_MPI_Wait                     ;
  cbacks->on_test                      =  cortex_translate_MPI_Test                     ;
  cbacks->on_request_free              =  cortex_translate_MPI_Request_free             ;
  cbacks->on_waitany                   =  cortex_translate_MPI_Waitany                  ;
  cbacks->on_testany                   =  cortex_translate_MPI_Testany                  ;
  cbacks->on_waitall                   =  cortex_translate_MPI_Waitall                  ;
  cbacks->on_testall                   =  cortex_translate_MPI_Testall                  ;
  cbacks->on_waitsome                  =  cortex_translate_MPI_Waitsome                 ;
  cbacks->on_testsome                  =  cortex_translate_MPI_Testsome                 ;
  cbacks->on_iprobe                    =  cortex_translate_MPI_Iprobe                   ;
  cbacks->on_probe                     =  cortex_translate_MPI_Probe                    ;
  cbacks->on_cancel                    =  cortex_translate_MPI_Cancel                   ;
  cbacks->on_test_cancelled            =  cortex_translate_MPI_Test_cancelled           ;
  cbacks->on_send_init                 =  cortex_translate_MPI_Send_init                ;
  cbacks->on_bsend_init                =  cortex_translate_MPI_Bsend_init               ;
  cbacks->on_ssend_init                =  cortex_translate_MPI_Ssend_init               ;
  cbacks->on_rsend_init                =  cortex_translate_MPI_Rsend_init               ;
  cbacks->on_recv_init                 =  cortex_translate_MPI_Recv_init                ;
  cbacks->on_start                     =  cortex_translate_MPI_Start                    ;
  cbacks->on_startall                  =  cortex_translate_MPI_Startall                 ;
  cbacks->on_sendrecv                  =  cortex_translate_MPI_Sendrecv                 ;
  cbacks->on_sendrecv_replace          =  cortex_translate_MPI_Sendrecv_replace         ;
  cbacks->on_type_contiguous           =  cortex_translate_MPI_Type_contiguous          ;
  cbacks->on_type_vector               =  cortex_translate_MPI_Type_vector              ;
  cbacks->on_type_hvector              =  cortex_translate_MPI_Type_hvector             ;
  cbacks->on_type_indexed              =  cortex_translate_MPI_Type_indexed             ;
  cbacks->on_type_hindexed             =  cortex_translate_MPI_Type_hindexed            ;
  cbacks->on_type_struct               =  cortex_translate_MPI_Type_struct              ;
  cbacks->on_address                   =  cortex_translate_MPI_Address                  ;
  cbacks->on_type_extent               =  cortex_translate_MPI_Type_extent              ;
  cbacks->on_type_size                 =  cortex_translate_MPI_Type_size                ;
  cbacks->on_type_lb                   =  cortex_translate_MPI_Type_lb                  ;
  cbacks->on_type_ub                   =  cortex_translate_MPI_Type_ub                  ;
  cbacks->on_type_commit               =  cortex_translate_MPI_Type_commit              ;
  cbacks->on_type_free                 =  cortex_translate_MPI_Type_free                ;
  cbacks->on_get_elements              =  cortex_translate_MPI_Get_elements             ;
  cbacks->on_pack                      =  cortex_translate_MPI_Pack                     ;
  cbacks->on_unpack                    =  cortex_translate_MPI_Unpack                   ;
  cbacks->on_pack_size                 =  cortex_translate_MPI_Pack_size                ;
  cbacks->on_barrier                   =  cortex_translate_MPI_Barrier                  ;
  cbacks->on_bcast                     =  cortex_translate_MPI_Bcast                    ;
  cbacks->on_gather                    =  cortex_translate_MPI_Gather                   ;
  cbacks->on_gatherv                   =  cortex_translate_MPI_Gatherv                  ;
  cbacks->on_scatter                   =  cortex_translate_MPI_Scatter                  ;
  cbacks->on_scatterv                  =  cortex_translate_MPI_Scatterv                 ;
  cbacks->on_allgather                 =  cortex_translate_MPI_Allgather                ;
  cbacks->on_allgatherv                =  cortex_translate_MPI_Allgatherv               ;
  cbacks->on_alltoall                  =  cortex_translate_MPI_Alltoall                 ;
  cbacks->on_alltoallv                 =  cortex_translate_MPI_Alltoallv                ;
  cbacks->on_reduce                    =  cortex_translate_MPI_Reduce                   ;
  cbacks->on_op_create                 =  cortex_translate_MPI_Op_create                ;
  cbacks->on_op_free                   =  cortex_translate_MPI_Op_free                  ;
  cbacks->on_allreduce                 =  cortex_translate_MPI_Allreduce                ;
  cbacks->on_reduce_scatter            =  cortex_translate_MPI_Reduce_scatter           ;
  cbacks->on_scan                      =  cortex_translate_MPI_Scan                     ;
  cbacks->on_group_size                =  cortex_translate_MPI_Group_size               ;
  cbacks->on_group_rank                =  cortex_translate_MPI_Group_rank               ;
  cbacks->on_group_translate_ranks     =  cortex_translate_MPI_Group_translate_ranks    ;
  cbacks->on_group_compare             =  cortex_translate_MPI_Group_compare            ;
  cbacks->on_comm_group                =  cortex_translate_MPI_Comm_group               ;
  cbacks->on_group_union               =  cortex_translate_MPI_Group_union              ;
  cbacks->on_group_intersection        =  cortex_translate_MPI_Group_intersection       ;
  cbacks->on_group_difference          =  cortex_translate_MPI_Group_difference         ;
  cbacks->on_group_incl                =  cortex_translate_MPI_Group_incl               ;
  cbacks->on_group_excl                =  cortex_translate_MPI_Group_excl               ;
  cbacks->on_group_range_incl          =  cortex_translate_MPI_Group_range_incl         ;
  cbacks->on_group_range_excl          =  cortex_translate_MPI_Group_range_excl         ;
  cbacks->on_group_free                =  cortex_translate_MPI_Group_free               ;
  cbacks->on_comm_size                 =  cortex_translate_MPI_Comm_size                ;
  cbacks->on_comm_rank                 =  cortex_translate_MPI_Comm_rank                ;
  cbacks->on_comm_compare              =  cortex_translate_MPI_Comm_compare             ;
  cbacks->on_comm_dup                  =  cortex_translate_MPI_Comm_dup                 ;
  cbacks->on_comm_create               =  cortex_translate_MPI_Comm_create              ;
  cbacks->on_comm_split                =  cortex_translate_MPI_Comm_split               ;
  cbacks->on_comm_free                 =  cortex_translate_MPI_Comm_free                ;
  cbacks->on_comm_test_inter           =  cortex_translate_MPI_Comm_test_inter          ;
  cbacks->on_comm_remote_size          =  cortex_translate_MPI_Comm_remote_size         ;
  cbacks->on_comm_remote_group         =  cortex_translate_MPI_Comm_remote_group        ;
  cbacks->on_intercomm_create          =  cortex_translate_MPI_Intercomm_create         ;
  cbacks->on_intercomm_merge           =  cortex_translate_MPI_Intercomm_merge          ;
  cbacks->on_keyval_create             =  cortex_translate_MPI_Keyval_create            ;
  cbacks->on_keyval_free               =  cortex_translate_MPI_Keyval_free              ;
  cbacks->on_attr_put                  =  cortex_translate_MPI_Attr_put                 ;
  cbacks->on_attr_get                  =  cortex_translate_MPI_Attr_get                 ;
  cbacks->on_attr_delete               =  cortex_translate_MPI_Attr_delete              ;
  cbacks->on_topo_test                 =  cortex_translate_MPI_Topo_test                ;
  cbacks->on_cart_create               =  cortex_translate_MPI_Cart_create              ;
  cbacks->on_dims_create               =  cortex_translate_MPI_Dims_create              ;
  cbacks->on_graph_create              =  cortex_translate_MPI_Graph_create             ;
  cbacks->on_graphdims_get             =  cortex_translate_MPI_Graphdims_get            ;
  cbacks->on_graph_get                 =  cortex_translate_MPI_Graph_get                ;
  cbacks->on_cartdim_get               =  cortex_translate_MPI_Cartdim_get              ;
  cbacks->on_cart_get                  =  cortex_translate_MPI_Cart_get                 ;
  cbacks->on_cart_rank                 =  cortex_translate_MPI_Cart_rank                ;
  cbacks->on_cart_coords               =  cortex_translate_MPI_Cart_coords              ;
  cbacks->on_graph_neighbors_count     =  cortex_translate_MPI_Graph_neighbors_count    ;
  cbacks->on_graph_neighbors           =  cortex_translate_MPI_Graph_neighbors          ;
  cbacks->on_cart_shift                =  cortex_translate_MPI_Cart_shift               ;
  cbacks->on_cart_sub                  =  cortex_translate_MPI_Cart_sub                 ;
  cbacks->on_cart_map                  =  cortex_translate_MPI_Cart_map                 ;
  cbacks->on_graph_map                 =  cortex_translate_MPI_Graph_map                ;
  cbacks->on_get_processor_name        =  cortex_translate_MPI_Get_processor_name       ;
  cbacks->on_get_version               =  cortex_translate_MPI_Get_version              ;
  cbacks->on_errhandler_create         =  cortex_translate_MPI_Errhandler_create        ;
  cbacks->on_errhandler_set            =  cortex_translate_MPI_Errhandler_set           ;
  cbacks->on_errhandler_get            =  cortex_translate_MPI_Errhandler_get           ;
  cbacks->on_errhandler_free           =  cortex_translate_MPI_Errhandler_free          ;
  cbacks->on_error_string              =  cortex_translate_MPI_Error_string             ;
  cbacks->on_error_class               =  cortex_translate_MPI_Error_class              ;
  cbacks->on_wtime                     =  cortex_translate_MPI_Wtime                    ;
  cbacks->on_wtick                     =  cortex_translate_MPI_Wtick                    ;
  cbacks->on_init                      =  cortex_translate_MPI_Init                     ;
  cbacks->on_finalize                  =  cortex_translate_MPI_Finalize                 ;
  cbacks->on_initialized               =  cortex_translate_MPI_Initialized              ;
  cbacks->on_abort                     =  cortex_translate_MPI_Abort                    ;
  cbacks->on_close_port                =  cortex_translate_MPI_Close_port               ;
  cbacks->on_comm_accept               =  cortex_translate_MPI_Comm_accept              ;
  cbacks->on_comm_connect              =  cortex_translate_MPI_Comm_connect             ;
  cbacks->on_comm_disconnect           =  cortex_translate_MPI_Comm_disconnect          ;
  cbacks->on_comm_get_parent           =  cortex_translate_MPI_Comm_get_parent          ;
  cbacks->on_comm_join                 =  cortex_translate_MPI_Comm_join                ;
  cbacks->on_comm_spawn                =  cortex_translate_MPI_Comm_spawn               ;
  cbacks->on_comm_spawn_multiple       =  cortex_translate_MPI_Comm_spawn_multiple      ;
  cbacks->on_lookup_name               =  cortex_translate_MPI_Lookup_name              ;
  cbacks->on_open_port                 =  cortex_translate_MPI_Open_port                ;
  cbacks->on_publish_name              =  cortex_translate_MPI_Publish_name             ;
  cbacks->on_unpublish_name            =  cortex_translate_MPI_Unpublish_name           ;
  cbacks->on_accumulate                =  cortex_translate_MPI_Accumulate               ;
  cbacks->on_get                       =  cortex_translate_MPI_Get                      ;
  cbacks->on_put                       =  cortex_translate_MPI_Put                      ;
  cbacks->on_win_complete              =  cortex_translate_MPI_Win_complete             ;
  cbacks->on_win_create                =  cortex_translate_MPI_Win_create               ;
  cbacks->on_win_fence                 =  cortex_translate_MPI_Win_fence                ;
  cbacks->on_win_free                  =  cortex_translate_MPI_Win_free                 ;
  cbacks->on_win_get_group             =  cortex_translate_MPI_Win_get_group            ;
  cbacks->on_win_lock                  =  cortex_translate_MPI_Win_lock                 ;
  cbacks->on_win_post                  =  cortex_translate_MPI_Win_post                 ;
  cbacks->on_win_start                 =  cortex_translate_MPI_Win_start                ;
  cbacks->on_win_test                  =  cortex_translate_MPI_Win_test                 ;
  cbacks->on_win_unlock                =  cortex_translate_MPI_Win_unlock               ;
  cbacks->on_win_wait                  =  cortex_translate_MPI_Win_wait                 ;
  cbacks->on_alltoallw                 =  cortex_translate_MPI_Alltoallw                ;
  cbacks->on_exscan                    =  cortex_translate_MPI_Exscan                   ;
  cbacks->on_add_error_class           =  cortex_translate_MPI_Add_error_class          ;
  cbacks->on_add_error_code            =  cortex_translate_MPI_Add_error_code           ;
  cbacks->on_add_error_string          =  cortex_translate_MPI_Add_error_string         ;
  cbacks->on_comm_call_errhandler      =  cortex_translate_MPI_Comm_call_errhandler     ;
  cbacks->on_comm_create_keyval        =  cortex_translate_MPI_Comm_create_keyval       ;
  cbacks->on_comm_delete_attr          =  cortex_translate_MPI_Comm_delete_attr         ;
  cbacks->on_comm_free_keyval          =  cortex_translate_MPI_Comm_free_keyval         ;
  cbacks->on_comm_get_attr             =  cortex_translate_MPI_Comm_get_attr            ;
  cbacks->on_comm_get_name             =  cortex_translate_MPI_Comm_get_name            ;
  cbacks->on_comm_set_attr             =  cortex_translate_MPI_Comm_set_attr            ;
  cbacks->on_comm_set_name             =  cortex_translate_MPI_Comm_set_name            ;
  cbacks->on_file_call_errhandler      =  cortex_translate_MPI_File_call_errhandler     ;
  cbacks->on_grequest_complete         =  cortex_translate_MPI_Grequest_complete        ;
  cbacks->on_grequest_start            =  cortex_translate_MPI_Grequest_start           ;
  cbacks->on_init_thread               =  cortex_translate_MPI_Init_thread              ;
  cbacks->on_is_thread_main            =  cortex_translate_MPI_Is_thread_main           ;
  cbacks->on_query_thread              =  cortex_translate_MPI_Query_thread             ;
  cbacks->on_status_set_cancelled      =  cortex_translate_MPI_Status_set_cancelled     ;
  cbacks->on_status_set_elements       =  cortex_translate_MPI_Status_set_elements      ;
  cbacks->on_type_create_keyval        =  cortex_translate_MPI_Type_create_keyval       ;
  cbacks->on_type_delete_attr          =  cortex_translate_MPI_Type_delete_attr         ;
  cbacks->on_type_dup                  =  cortex_translate_MPI_Type_dup                 ;
  cbacks->on_type_free_keyval          =  cortex_translate_MPI_Type_free_keyval         ;
  cbacks->on_type_get_attr             =  cortex_translate_MPI_Type_get_attr            ;
  cbacks->on_type_get_contents         =  cortex_translate_MPI_Type_get_contents        ;
  cbacks->on_type_get_envelope         =  cortex_translate_MPI_Type_get_envelope        ;
  cbacks->on_type_get_name             =  cortex_translate_MPI_Type_get_name            ;
  cbacks->on_type_set_attr             =  cortex_translate_MPI_Type_set_attr            ;
  cbacks->on_type_set_name             =  cortex_translate_MPI_Type_set_name            ;
  cbacks->on_type_match_size           =  cortex_translate_MPI_Type_match_size          ;
  cbacks->on_win_call_errhandler       =  cortex_translate_MPI_Win_call_errhandler      ;
  cbacks->on_win_create_keyval         =  cortex_translate_MPI_Win_create_keyval        ;
  cbacks->on_win_delete_attr           =  cortex_translate_MPI_Win_delete_attr          ;
  cbacks->on_win_free_keyval           =  cortex_translate_MPI_Win_free_keyval          ;
  cbacks->on_win_get_attr              =  cortex_translate_MPI_Win_get_attr             ;
  cbacks->on_win_get_name              =  cortex_translate_MPI_Win_get_name             ;
  cbacks->on_win_set_attr              =  cortex_translate_MPI_Win_set_attr             ;
  cbacks->on_win_set_name              =  cortex_translate_MPI_Win_set_name             ;
  cbacks->on_alloc_mem                 =  cortex_translate_MPI_Alloc_mem                ;
  cbacks->on_comm_create_errhandler    =  cortex_translate_MPI_Comm_create_errhandler   ;
  cbacks->on_comm_get_errhandler       =  cortex_translate_MPI_Comm_get_errhandler      ;
  cbacks->on_comm_set_errhandler       =  cortex_translate_MPI_Comm_set_errhandler      ;
  cbacks->on_file_create_errhandler    =  cortex_translate_MPI_File_create_errhandler   ;
  cbacks->on_file_get_errhandler       =  cortex_translate_MPI_File_get_errhandler      ;
  cbacks->on_file_set_errhandler       =  cortex_translate_MPI_File_set_errhandler      ;
  cbacks->on_finalized                 =  cortex_translate_MPI_Finalized                ;
  cbacks->on_free_mem                  =  cortex_translate_MPI_Free_mem                 ;
  cbacks->on_get_address               =  cortex_translate_MPI_Get_address              ;
  cbacks->on_info_create               =  cortex_translate_MPI_Info_create              ;
  cbacks->on_info_delete               =  cortex_translate_MPI_Info_delete              ;
  cbacks->on_info_dup                  =  cortex_translate_MPI_Info_dup                 ;
  cbacks->on_info_free                 =  cortex_translate_MPI_Info_free                ;
  cbacks->on_info_get                  =  cortex_translate_MPI_Info_get                 ;
  cbacks->on_info_get_nkeys            =  cortex_translate_MPI_Info_get_nkeys           ;
  cbacks->on_info_get_nthkey           =  cortex_translate_MPI_Info_get_nthkey          ;
  cbacks->on_info_get_valuelen         =  cortex_translate_MPI_Info_get_valuelen        ;
  cbacks->on_info_set                  =  cortex_translate_MPI_Info_set                 ;
  cbacks->on_pack_external             =  cortex_translate_MPI_Pack_external            ;
  cbacks->on_pack_external_size        =  cortex_translate_MPI_Pack_external_size       ;
  cbacks->on_request_get_status        =  cortex_translate_MPI_Request_get_status       ;
  cbacks->on_type_create_darray        =  cortex_translate_MPI_Type_create_darray       ;
  cbacks->on_type_create_hindexed      =  cortex_translate_MPI_Type_create_hindexed     ;
  cbacks->on_type_create_hvector       =  cortex_translate_MPI_Type_create_hvector      ;
  cbacks->on_type_create_indexed_block =  cortex_translate_MPI_Type_create_indexed_block;
  cbacks->on_type_create_resized       =  cortex_translate_MPI_Type_create_resized      ;
  cbacks->on_type_create_struct        =  cortex_translate_MPI_Type_create_struct       ;
  cbacks->on_type_create_subarray      =  cortex_translate_MPI_Type_create_subarray     ;
  cbacks->on_type_get_extent           =  cortex_translate_MPI_Type_get_extent          ;
  cbacks->on_type_get_true_extent      =  cortex_translate_MPI_Type_get_true_extent     ;
  cbacks->on_unpack_external           =  cortex_translate_MPI_Unpack_external          ;
  cbacks->on_win_create_errhandler     =  cortex_translate_MPI_Win_create_errhandler    ;
  cbacks->on_win_get_errhandler        =  cortex_translate_MPI_Win_get_errhandler       ;
  cbacks->on_win_set_errhandler        =  cortex_translate_MPI_Win_set_errhandler       ;
  cbacks->on_file_open                 =  cortex_translate_MPI_File_open                ;
  cbacks->on_file_close                =  cortex_translate_MPI_File_close               ;
  cbacks->on_file_delete               =  cortex_translate_MPI_File_delete              ;
  cbacks->on_file_set_size             =  cortex_translate_MPI_File_set_size            ;
  cbacks->on_file_preallocate          =  cortex_translate_MPI_File_preallocate         ;
  cbacks->on_file_get_size             =  cortex_translate_MPI_File_get_size            ;
  cbacks->on_file_get_group            =  cortex_translate_MPI_File_get_group           ;
  cbacks->on_file_get_amode            =  cortex_translate_MPI_File_get_amode           ;
  cbacks->on_file_set_info             =  cortex_translate_MPI_File_set_info            ;
  cbacks->on_file_get_info             =  cortex_translate_MPI_File_get_info            ;
  cbacks->on_file_set_view             =  cortex_translate_MPI_File_set_view            ;
  cbacks->on_file_get_view             =  cortex_translate_MPI_File_get_view            ;
  cbacks->on_file_read_at              =  cortex_translate_MPI_File_read_at             ;
  cbacks->on_file_read_at_all          =  cortex_translate_MPI_File_read_at_all         ;
  cbacks->on_file_write_at             =  cortex_translate_MPI_File_write_at            ;
  cbacks->on_file_write_at_all         =  cortex_translate_MPI_File_write_at_all        ;
  cbacks->on_file_iread_at             =  cortex_translate_MPI_File_iread_at            ;
  cbacks->on_file_iwrite_at            =  cortex_translate_MPI_File_iwrite_at           ;
  cbacks->on_file_read                 =  cortex_translate_MPI_File_read                ;
  cbacks->on_file_read_all             =  cortex_translate_MPI_File_read_all            ;
  cbacks->on_file_write                =  cortex_translate_MPI_File_write               ;
  cbacks->on_file_write_all            =  cortex_translate_MPI_File_write_all           ;
  cbacks->on_file_iread                =  cortex_translate_MPI_File_iread               ;
  cbacks->on_file_iwrite               =  cortex_translate_MPI_File_iwrite              ;
  cbacks->on_file_seek                 =  cortex_translate_MPI_File_seek                ;
  cbacks->on_file_get_position         =  cortex_translate_MPI_File_get_position        ;
  cbacks->on_file_get_byte_offset      =  cortex_translate_MPI_File_get_byte_offset     ;
  cbacks->on_file_read_shared          =  cortex_translate_MPI_File_read_shared         ;
  cbacks->on_file_write_shared         =  cortex_translate_MPI_File_write_shared        ;
  cbacks->on_file_iread_shared         =  cortex_translate_MPI_File_iread_shared        ;
  cbacks->on_file_iwrite_shared        =  cortex_translate_MPI_File_iwrite_shared       ;
  cbacks->on_file_read_ordered         =  cortex_translate_MPI_File_read_ordered        ;
  cbacks->on_file_write_ordered        =  cortex_translate_MPI_File_write_ordered       ;
  cbacks->on_file_seek_shared          =  cortex_translate_MPI_File_seek_shared         ;
  cbacks->on_file_get_position_shared  =  cortex_translate_MPI_File_get_position_shared ;
  cbacks->on_file_read_at_all_begin    =  cortex_translate_MPI_File_read_at_all_begin   ;
  cbacks->on_file_read_at_all_end      =  cortex_translate_MPI_File_read_at_all_end     ;
  cbacks->on_file_write_at_all_begin   =  cortex_translate_MPI_File_write_at_all_begin  ;
  cbacks->on_file_write_at_all_end     =  cortex_translate_MPI_File_write_at_all_end    ;
  cbacks->on_file_read_all_begin       =  cortex_translate_MPI_File_read_all_begin      ;
  cbacks->on_file_read_all_end         =  cortex_translate_MPI_File_read_all_end        ;
  cbacks->on_file_write_all_begin      =  cortex_translate_MPI_File_write_all_begin     ;
  cbacks->on_file_write_all_end        =  cortex_translate_MPI_File_write_all_end       ;
  cbacks->on_file_read_ordered_begin   =  cortex_translate_MPI_File_read_ordered_begin  ;
  cbacks->on_file_read_ordered_end     =  cortex_translate_MPI_File_read_ordered_end    ;
  cbacks->on_file_write_ordered_begin  =  cortex_translate_MPI_File_write_ordered_begin ;
  cbacks->on_file_write_ordered_end    =  cortex_translate_MPI_File_write_ordered_end   ;
  cbacks->on_file_get_type_extent      =  cortex_translate_MPI_File_get_type_extent     ;
  cbacks->on_register_datarep          =  cortex_translate_MPI_Register_datarep         ;
  cbacks->on_file_set_atomicity        =  cortex_translate_MPI_File_set_atomicity       ;
  cbacks->on_file_get_atomicity        =  cortex_translate_MPI_File_get_atomicity       ;
  cbacks->on_file_sync                 =  cortex_translate_MPI_File_sync                ;
  cbacks->on_iotest                    =  cortex_translate_MPIO_Test                    ;
  cbacks->on_iowait                    =  cortex_translate_MPIO_Wait                    ;
  cbacks->on_iotestall                 =  cortex_translate_MPIO_Testall                 ;
  cbacks->on_iowaitall                 =  cortex_translate_MPIO_Waitall                 ;
  cbacks->on_iotestany                 =  cortex_translate_MPIO_Testany                 ;
  cbacks->on_iowaitany                 =  cortex_translate_MPIO_Waitany                 ;
  cbacks->on_iowaitsome                =  cortex_translate_MPIO_Waitsome                ;
  cbacks->on_iotestsome                =  cortex_translate_MPIO_Testsome                ;
  cbacks->on_function_enter            =  cortex_Function_enter               ;
  cbacks->on_function_exit             =  cortex_Function_exit                ;
}

#undef CORTEX_FORWARD

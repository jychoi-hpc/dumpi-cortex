set(CORTEX_LIB_SRC
	${CORTEX_SOURCE_DIR}/src/cortex.c
	${CORTEX_SOURCE_DIR}/src/default-callbacks.c
	${CORTEX_SOURCE_DIR}/src/operation.c
	${CORTEX_SOURCE_DIR}/src/post.c
	${CORTEX_SOURCE_DIR}/src/comm.c
	${CORTEX_SOURCE_DIR}/src/datatype.c
	${CORTEX_SOURCE_DIR}/src/placement.c
	${CORTEX_SOURCE_DIR}/src/topology.c
)

add_library(cortex ${CORTEX_LIB_SRC})

set(CORTEX_MPICH_SRC
	${CORTEX_SOURCE_DIR}/src/mpich-callbacks.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_allgather.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_allgatherv.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_allreduce.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_alltoallv.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_barrier.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_bcast.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_comm_create.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_comm_dup.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_comm_split.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_reduce.c
)

add_library(cortex-mpich ${CORTEX_MPICH_SRC})

if(ENABLE_PYTHON)

set(CORTEX_PYTHON_SRC
	${CORTEX_SOURCE_DIR}/src/cortex-python.cpp
	${CORTEX_SOURCE_DIR}/src/python-callbacks.c
	${CORTEX_SOURCE_DIR}/src/python/mpi_all.cpp
)

set(CORTEX_PYTHON_SRC_OLD
	${CORTEX_SOURCE_DIR}/src/cortex-python.cpp
	${CORTEX_SOURCE_DIR}/src/python-callbacks.c
	${CORTEX_SOURCE_DIR}/src/python/module.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_abort.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_accumulate.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_add_error_class.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_add_error_code.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_add_error_string.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_address.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_allgather.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_allgatherv.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_alloc_mem.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_allreduce.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_alltoall.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_alltoallv.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_alltoallw.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_attr_delete.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_attr_get.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_attr_put.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_barrier.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_bcast.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_bsend.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_bsend_init.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_buffer_attach.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_buffer_detach.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_cancel.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_cart_coords.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_cart_create.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_cartdim_get.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_cart_get.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_cart_map.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_cart_rank.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_cart_shift.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_cart_sub.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_close_port.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_accept.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_call_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_compare.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_connect.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_create.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_create_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_create_keyval.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_delete_attr.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_disconnect.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_dup.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_free.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_free_keyval.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_get_attr.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_get_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_get_name.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_get_parent.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_group.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_join.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_rank.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_remote_group.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_remote_size.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_set_attr.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_set_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_set_name.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_size.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_spawn.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_spawn_multiple.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_split.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_comm_test_inter.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_dims_create.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_errhandler_create.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_errhandler_free.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_errhandler_get.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_errhandler_set.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_error_class.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_error_string.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_exscan.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_call_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_close.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_create_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_delete.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_amode.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_atomicity.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_byte_offset.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_group.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_info.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_position.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_position_shared.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_size.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_type_extent.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_get_view.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_iread_at.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_iread.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_iread_shared.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_iwrite_at.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_iwrite.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_iwrite_shared.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_open.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_preallocate.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_all_begin.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_all.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_all_end.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_at_all_begin.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_at_all.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_at_all_end.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_at.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_ordered_begin.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_ordered.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_ordered_end.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_read_shared.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_seek.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_seek_shared.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_set_atomicity.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_set_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_set_info.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_set_size.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_set_view.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_sync.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_all_begin.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_all.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_all_end.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_at_all_begin.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_at_all.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_at_all_end.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_at.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_ordered_begin.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_ordered.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_ordered_end.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_file_write_shared.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_finalize.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_finalized.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_free_mem.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_gather.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_gatherv.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_get_address.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_get_count.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_get.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_get_elements.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_get_processor_name.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_get_version.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_graph_create.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_graphdims_get.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_graph_get.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_graph_map.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_graph_neighbors_count.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_graph_neighbors.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_grequest_complete.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_grequest_start.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_compare.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_difference.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_excl.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_free.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_incl.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_intersection.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_range_excl.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_range_incl.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_rank.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_size.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_translate_ranks.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_group_union.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_ibsend.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_info_create.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_info_delete.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_info_dup.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_info_free.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_info_get.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_info_get_nkeys.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_info_get_nthkey.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_info_get_valuelen.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_info_set.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_init.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_initialized.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_init_thread.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_intercomm_create.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_intercomm_merge.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_iprobe.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_irecv.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_irsend.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_isend.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_issend.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_is_thread_main.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_keyval_create.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_keyval_free.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_lookup_name.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_op_create.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_open_port.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_op_free.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpio_testall.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpio_testany.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpio_test.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpio_testsome.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpio_waitall.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpio_waitany.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpio_wait.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpio_waitsome.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_pack.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_pack_external.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_pack_external_size.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_pack_size.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_probe.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_publish_name.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_put.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_query_thread.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_recv.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_recv_init.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_reduce.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_reduce_scatter.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_register_datarep.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_request_free.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_request_get_status.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_rsend.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_rsend_init.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_scan.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_scatter.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_scatterv.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_send.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_send_init.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_sendrecv.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_sendrecv_replace.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_ssend.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_ssend_init.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_startall.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_start.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_status_set_cancelled.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_status_set_elements.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_testall.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_testany.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_test_cancelled.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_test.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_testsome.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_topo_test.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_commit.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_contiguous.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_create_darray.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_create_hindexed.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_create_hvector.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_create_indexed_block.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_create_keyval.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_create_resized.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_create_struct.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_create_subarray.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_delete_attr.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_dup.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_extent.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_free.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_free_keyval.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_get_attr.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_get_contents.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_get_envelope.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_get_extent.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_get_name.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_get_true_extent.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_hindexed.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_hvector.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_indexed.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_lb.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_match_size.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_set_attr.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_set_name.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_size.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_struct.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_ub.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_type_vector.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_unpack.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_unpack_external.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_unpublish_name.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_waitall.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_waitany.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_wait.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_waitsome.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_call_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_complete.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_create.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_create_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_create_keyval.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_delete_attr.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_fence.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_free.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_free_keyval.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_get_attr.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_get_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_get_group.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_get_name.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_lock.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_post.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_set_attr.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_set_errhandler.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_set_name.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_start.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_test.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_unlock.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_win_wait.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_wtick.cpp
	${CORTEX_SOURCE_DIR}/src/python/mpi_wtime.cpp
)

add_library(cortex-python ${CORTEX_PYTHON_SRC})
endif(ENABLE_PYTHON)

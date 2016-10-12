/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */

#include "cortex/cortex.h"
#include "cortex/python-callbacks.h"
#include "cortex/python-callbacks.h"
#include <dumpi/libundumpi/callbacks.h>
#include <dumpi/common/argtypes.h>
#include <dumpi/common/constants.h>
#include <assert.h>
#include <stdio.h>

libundumpi_callbacks cortex_python_translation = {
  .on_send                      =  cortex_python_translate_MPI_Send                     ,
  .on_recv                      =  cortex_python_translate_MPI_Recv                     ,
  .on_get_count                 =  cortex_python_translate_MPI_Get_count                ,
  .on_bsend                     =  cortex_python_translate_MPI_Bsend                    ,
  .on_ssend                     =  cortex_python_translate_MPI_Ssend                    ,
  .on_rsend                     =  cortex_python_translate_MPI_Rsend                    ,
  .on_buffer_attach             =  cortex_python_translate_MPI_Buffer_attach            ,
  .on_buffer_detach             =  cortex_python_translate_MPI_Buffer_detach            ,
  .on_isend                     =  cortex_python_translate_MPI_Isend                    ,
  .on_ibsend                    =  cortex_python_translate_MPI_Ibsend                   ,
  .on_issend                    =  cortex_python_translate_MPI_Issend                   ,
  .on_irsend                    =  cortex_python_translate_MPI_Irsend                   ,
  .on_irecv                     =  cortex_python_translate_MPI_Irecv                    ,
  .on_wait                      =  cortex_python_translate_MPI_Wait                     ,
  .on_test                      =  cortex_python_translate_MPI_Test                     ,
  .on_request_free              =  cortex_python_translate_MPI_Request_free             ,
  .on_waitany                   =  cortex_python_translate_MPI_Waitany                  ,
  .on_testany                   =  cortex_python_translate_MPI_Testany                  ,
  .on_waitall                   =  cortex_python_translate_MPI_Waitall                  ,
  .on_testall                   =  cortex_python_translate_MPI_Testall                  ,
  .on_waitsome                  =  cortex_python_translate_MPI_Waitsome                 ,
  .on_testsome                  =  cortex_python_translate_MPI_Testsome                 ,
  .on_iprobe                    =  cortex_python_translate_MPI_Iprobe                   ,
  .on_probe                     =  cortex_python_translate_MPI_Probe                    ,
  .on_cancel                    =  cortex_python_translate_MPI_Cancel                   ,
  .on_test_cancelled            =  cortex_python_translate_MPI_Test_cancelled           ,
  .on_send_init                 =  cortex_python_translate_MPI_Send_init                ,
  .on_bsend_init                =  cortex_python_translate_MPI_Bsend_init               ,
  .on_ssend_init                =  cortex_python_translate_MPI_Ssend_init               ,
  .on_rsend_init                =  cortex_python_translate_MPI_Rsend_init               ,
  .on_recv_init                 =  cortex_python_translate_MPI_Recv_init                ,
  .on_start                     =  cortex_python_translate_MPI_Start                    ,
  .on_startall                  =  cortex_python_translate_MPI_Startall                 ,
  .on_sendrecv                  =  cortex_python_translate_MPI_Sendrecv                 ,
  .on_sendrecv_replace          =  cortex_python_translate_MPI_Sendrecv_replace         ,
  .on_type_contiguous           =  cortex_python_translate_MPI_Type_contiguous          ,
  .on_type_vector               =  cortex_python_translate_MPI_Type_vector              ,
  .on_type_hvector              =  cortex_python_translate_MPI_Type_hvector             ,
  .on_type_indexed              =  cortex_python_translate_MPI_Type_indexed             ,
  .on_type_hindexed             =  cortex_python_translate_MPI_Type_hindexed            ,
  .on_type_struct               =  cortex_python_translate_MPI_Type_struct              ,
  .on_address                   =  cortex_python_translate_MPI_Address                  ,
  .on_type_extent               =  cortex_python_translate_MPI_Type_extent              ,
  .on_type_size                 =  cortex_python_translate_MPI_Type_size                ,
  .on_type_lb                   =  cortex_python_translate_MPI_Type_lb                  ,
  .on_type_ub                   =  cortex_python_translate_MPI_Type_ub                  ,
  .on_type_commit               =  cortex_python_translate_MPI_Type_commit              ,
  .on_type_free                 =  cortex_python_translate_MPI_Type_free                ,
  .on_get_elements              =  cortex_python_translate_MPI_Get_elements             ,
  .on_pack                      =  cortex_python_translate_MPI_Pack                     ,
  .on_unpack                    =  cortex_python_translate_MPI_Unpack                   ,
  .on_pack_size                 =  cortex_python_translate_MPI_Pack_size                ,
  .on_barrier                   =  cortex_python_translate_MPI_Barrier                  ,
  .on_bcast                     =  cortex_python_translate_MPI_Bcast                    ,
  .on_gather                    =  cortex_python_translate_MPI_Gather                   ,
  .on_gatherv                   =  cortex_python_translate_MPI_Gatherv                  ,
  .on_scatter                   =  cortex_python_translate_MPI_Scatter                  ,
  .on_scatterv                  =  cortex_python_translate_MPI_Scatterv                 ,
  .on_allgather                 =  cortex_python_translate_MPI_Allgather                  ,
  .on_allgatherv                =  cortex_python_translate_MPI_Allgatherv                 ,
  .on_alltoall                  =  cortex_python_translate_MPI_Alltoall                 ,
  .on_alltoallv                 =  cortex_python_translate_MPI_Alltoallv                  ,
  .on_reduce                    =  cortex_python_translate_MPI_Reduce                   ,
  .on_op_create                 =  cortex_python_translate_MPI_Op_create                ,
  .on_op_free                   =  cortex_python_translate_MPI_Op_free                  ,
  .on_allreduce                 =  cortex_python_translate_MPI_Allreduce                  ,
  .on_reduce_scatter            =  cortex_python_translate_MPI_Reduce_scatter           ,
  .on_scan                      =  cortex_python_translate_MPI_Scan                     ,
  .on_group_size                =  cortex_python_translate_MPI_Group_size               ,
  .on_group_rank                =  cortex_python_translate_MPI_Group_rank               ,
  .on_group_translate_ranks     =  cortex_python_translate_MPI_Group_translate_ranks    ,
  .on_group_compare             =  cortex_python_translate_MPI_Group_compare            ,
  .on_comm_group                =  cortex_python_translate_MPI_Comm_group               ,
  .on_group_union               =  cortex_python_translate_MPI_Group_union              ,
  .on_group_intersection        =  cortex_python_translate_MPI_Group_intersection       ,
  .on_group_difference          =  cortex_python_translate_MPI_Group_difference         ,
  .on_group_incl                =  cortex_python_translate_MPI_Group_incl               ,
  .on_group_excl                =  cortex_python_translate_MPI_Group_excl               ,
  .on_group_range_incl          =  cortex_python_translate_MPI_Group_range_incl         ,
  .on_group_range_excl          =  cortex_python_translate_MPI_Group_range_excl         ,
  .on_group_free                =  cortex_python_translate_MPI_Group_free               ,
  .on_comm_size                 =  cortex_python_translate_MPI_Comm_size                ,
  .on_comm_rank                 =  cortex_python_translate_MPI_Comm_rank                ,
  .on_comm_compare              =  cortex_python_translate_MPI_Comm_compare             ,
  .on_comm_dup                  =  cortex_python_translate_MPI_Comm_dup                 ,
  .on_comm_create               =  cortex_python_translate_MPI_Comm_create              ,
  .on_comm_split                =  cortex_python_translate_MPI_Comm_split               ,
  .on_comm_free                 =  cortex_python_translate_MPI_Comm_free                ,
  .on_comm_test_inter           =  cortex_python_translate_MPI_Comm_test_inter          ,
  .on_comm_remote_size          =  cortex_python_translate_MPI_Comm_remote_size         ,
  .on_comm_remote_group         =  cortex_python_translate_MPI_Comm_remote_group        ,
  .on_intercomm_create          =  cortex_python_translate_MPI_Intercomm_create         ,
  .on_intercomm_merge           =  cortex_python_translate_MPI_Intercomm_merge          ,
  .on_keyval_create             =  cortex_python_translate_MPI_Keyval_create            ,
  .on_keyval_free               =  cortex_python_translate_MPI_Keyval_free              ,
  .on_attr_put                  =  cortex_python_translate_MPI_Attr_put                 ,
  .on_attr_get                  =  cortex_python_translate_MPI_Attr_get                 ,
  .on_attr_delete               =  cortex_python_translate_MPI_Attr_delete              ,
  .on_topo_test                 =  cortex_python_translate_MPI_Topo_test                ,
  .on_cart_create               =  cortex_python_translate_MPI_Cart_create              ,
  .on_dims_create               =  cortex_python_translate_MPI_Dims_create              ,
  .on_graph_create              =  cortex_python_translate_MPI_Graph_create             ,
  .on_graphdims_get             =  cortex_python_translate_MPI_Graphdims_get            ,
  .on_graph_get                 =  cortex_python_translate_MPI_Graph_get                ,
  .on_cartdim_get               =  cortex_python_translate_MPI_Cartdim_get              ,
  .on_cart_get                  =  cortex_python_translate_MPI_Cart_get                 ,
  .on_cart_rank                 =  cortex_python_translate_MPI_Cart_rank                ,
  .on_cart_coords               =  cortex_python_translate_MPI_Cart_coords              ,
  .on_graph_neighbors_count     =  cortex_python_translate_MPI_Graph_neighbors_count    ,
  .on_graph_neighbors           =  cortex_python_translate_MPI_Graph_neighbors          ,
  .on_cart_shift                =  cortex_python_translate_MPI_Cart_shift               ,
  .on_cart_sub                  =  cortex_python_translate_MPI_Cart_sub                 ,
  .on_cart_map                  =  cortex_python_translate_MPI_Cart_map                 ,
  .on_graph_map                 =  cortex_python_translate_MPI_Graph_map                ,
  .on_get_processor_name        =  cortex_python_translate_MPI_Get_processor_name       ,
  .on_get_version               =  cortex_python_translate_MPI_Get_version              ,
  .on_errhandler_create         =  cortex_python_translate_MPI_Errhandler_create        ,
  .on_errhandler_set            =  cortex_python_translate_MPI_Errhandler_set           ,
  .on_errhandler_get            =  cortex_python_translate_MPI_Errhandler_get           ,
  .on_errhandler_free           =  cortex_python_translate_MPI_Errhandler_free          ,
  .on_error_string              =  cortex_python_translate_MPI_Error_string             ,
  .on_error_class               =  cortex_python_translate_MPI_Error_class              ,
  .on_wtime                     =  cortex_python_translate_MPI_Wtime                    ,
  .on_wtick                     =  cortex_python_translate_MPI_Wtick                    ,
  .on_init                      =  cortex_python_translate_MPI_Init                     ,
  .on_finalize                  =  cortex_python_translate_MPI_Finalize                 ,
  .on_initialized               =  cortex_python_translate_MPI_Initialized              ,
  .on_abort                     =  cortex_python_translate_MPI_Abort                    ,
  .on_close_port                =  cortex_python_translate_MPI_Close_port               ,
  .on_comm_accept               =  cortex_python_translate_MPI_Comm_accept              ,
  .on_comm_connect              =  cortex_python_translate_MPI_Comm_connect             ,
  .on_comm_disconnect           =  cortex_python_translate_MPI_Comm_disconnect          ,
  .on_comm_get_parent           =  cortex_python_translate_MPI_Comm_get_parent          ,
  .on_comm_join                 =  cortex_python_translate_MPI_Comm_join                ,
  .on_comm_spawn                =  cortex_python_translate_MPI_Comm_spawn               ,
  .on_comm_spawn_multiple       =  cortex_python_translate_MPI_Comm_spawn_multiple      ,
  .on_lookup_name               =  cortex_python_translate_MPI_Lookup_name              ,
  .on_open_port                 =  cortex_python_translate_MPI_Open_port                ,
  .on_publish_name              =  cortex_python_translate_MPI_Publish_name             ,
  .on_unpublish_name            =  cortex_python_translate_MPI_Unpublish_name           ,
  .on_accumulate                =  cortex_python_translate_MPI_Accumulate               ,
  .on_get                       =  cortex_python_translate_MPI_Get                      ,
  .on_put                       =  cortex_python_translate_MPI_Put                      ,
  .on_win_complete              =  cortex_python_translate_MPI_Win_complete             ,
  .on_win_create                =  cortex_python_translate_MPI_Win_create               ,
  .on_win_fence                 =  cortex_python_translate_MPI_Win_fence                ,
  .on_win_free                  =  cortex_python_translate_MPI_Win_free                 ,
  .on_win_get_group             =  cortex_python_translate_MPI_Win_get_group            ,
  .on_win_lock                  =  cortex_python_translate_MPI_Win_lock                 ,
  .on_win_post                  =  cortex_python_translate_MPI_Win_post                 ,
  .on_win_start                 =  cortex_python_translate_MPI_Win_start                ,
  .on_win_test                  =  cortex_python_translate_MPI_Win_test                 ,
  .on_win_unlock                =  cortex_python_translate_MPI_Win_unlock               ,
  .on_win_wait                  =  cortex_python_translate_MPI_Win_wait                 ,
  .on_alltoallw                 =  cortex_python_translate_MPI_Alltoallw                ,
  .on_exscan                    =  cortex_python_translate_MPI_Exscan                   ,
  .on_add_error_class           =  cortex_python_translate_MPI_Add_error_class          ,
  .on_add_error_code            =  cortex_python_translate_MPI_Add_error_code           ,
  .on_add_error_string          =  cortex_python_translate_MPI_Add_error_string         ,
  .on_comm_call_errhandler      =  cortex_python_translate_MPI_Comm_call_errhandler     ,
  .on_comm_create_keyval        =  cortex_python_translate_MPI_Comm_create_keyval       ,
  .on_comm_delete_attr          =  cortex_python_translate_MPI_Comm_delete_attr         ,
  .on_comm_free_keyval          =  cortex_python_translate_MPI_Comm_free_keyval         ,
  .on_comm_get_attr             =  cortex_python_translate_MPI_Comm_get_attr            ,
  .on_comm_get_name             =  cortex_python_translate_MPI_Comm_get_name            ,
  .on_comm_set_attr             =  cortex_python_translate_MPI_Comm_set_attr            ,
  .on_comm_set_name             =  cortex_python_translate_MPI_Comm_set_name            ,
  .on_file_call_errhandler      =  cortex_python_translate_MPI_File_call_errhandler     ,
  .on_grequest_complete         =  cortex_python_translate_MPI_Grequest_complete        ,
  .on_grequest_start            =  cortex_python_translate_MPI_Grequest_start           ,
  .on_init_thread               =  cortex_python_translate_MPI_Init_thread              ,
  .on_is_thread_main            =  cortex_python_translate_MPI_Is_thread_main           ,
  .on_query_thread              =  cortex_python_translate_MPI_Query_thread             ,
  .on_status_set_cancelled      =  cortex_python_translate_MPI_Status_set_cancelled     ,
  .on_status_set_elements       =  cortex_python_translate_MPI_Status_set_elements      ,
  .on_type_create_keyval        =  cortex_python_translate_MPI_Type_create_keyval       ,
  .on_type_delete_attr          =  cortex_python_translate_MPI_Type_delete_attr         ,
  .on_type_dup                  =  cortex_python_translate_MPI_Type_dup                 ,
  .on_type_free_keyval          =  cortex_python_translate_MPI_Type_free_keyval         ,
  .on_type_get_attr             =  cortex_python_translate_MPI_Type_get_attr            ,
  .on_type_get_contents         =  cortex_python_translate_MPI_Type_get_contents        ,
  .on_type_get_envelope         =  cortex_python_translate_MPI_Type_get_envelope        ,
  .on_type_get_name             =  cortex_python_translate_MPI_Type_get_name            ,
  .on_type_set_attr             =  cortex_python_translate_MPI_Type_set_attr            ,
  .on_type_set_name             =  cortex_python_translate_MPI_Type_set_name            ,
  .on_type_match_size           =  cortex_python_translate_MPI_Type_match_size          ,
  .on_win_call_errhandler       =  cortex_python_translate_MPI_Win_call_errhandler      ,
  .on_win_create_keyval         =  cortex_python_translate_MPI_Win_create_keyval        ,
  .on_win_delete_attr           =  cortex_python_translate_MPI_Win_delete_attr          ,
  .on_win_free_keyval           =  cortex_python_translate_MPI_Win_free_keyval          ,
  .on_win_get_attr              =  cortex_python_translate_MPI_Win_get_attr             ,
  .on_win_get_name              =  cortex_python_translate_MPI_Win_get_name             ,
  .on_win_set_attr              =  cortex_python_translate_MPI_Win_set_attr             ,
  .on_win_set_name              =  cortex_python_translate_MPI_Win_set_name             ,
  .on_alloc_mem                 =  cortex_python_translate_MPI_Alloc_mem                ,
  .on_comm_create_errhandler    =  cortex_python_translate_MPI_Comm_create_errhandler   ,
  .on_comm_get_errhandler       =  cortex_python_translate_MPI_Comm_get_errhandler      ,
  .on_comm_set_errhandler       =  cortex_python_translate_MPI_Comm_set_errhandler      ,
  .on_file_create_errhandler    =  cortex_python_translate_MPI_File_create_errhandler   ,
  .on_file_get_errhandler       =  cortex_python_translate_MPI_File_get_errhandler      ,
  .on_file_set_errhandler       =  cortex_python_translate_MPI_File_set_errhandler      ,
  .on_finalized                 =  cortex_python_translate_MPI_Finalized                ,
  .on_free_mem                  =  cortex_python_translate_MPI_Free_mem                 ,
  .on_get_address               =  cortex_python_translate_MPI_Get_address              ,
  .on_info_create               =  cortex_python_translate_MPI_Info_create              ,
  .on_info_delete               =  cortex_python_translate_MPI_Info_delete              ,
  .on_info_dup                  =  cortex_python_translate_MPI_Info_dup                 ,
  .on_info_free                 =  cortex_python_translate_MPI_Info_free                ,
  .on_info_get                  =  cortex_python_translate_MPI_Info_get                 ,
  .on_info_get_nkeys            =  cortex_python_translate_MPI_Info_get_nkeys           ,
  .on_info_get_nthkey           =  cortex_python_translate_MPI_Info_get_nthkey          ,
  .on_info_get_valuelen         =  cortex_python_translate_MPI_Info_get_valuelen        ,
  .on_info_set                  =  cortex_python_translate_MPI_Info_set                 ,
  .on_pack_external             =  cortex_python_translate_MPI_Pack_external            ,
  .on_pack_external_size        =  cortex_python_translate_MPI_Pack_external_size       ,
  .on_request_get_status        =  cortex_python_translate_MPI_Request_get_status       ,
  .on_type_create_darray        =  cortex_python_translate_MPI_Type_create_darray       ,
  .on_type_create_hindexed      =  cortex_python_translate_MPI_Type_create_hindexed     ,
  .on_type_create_hvector       =  cortex_python_translate_MPI_Type_create_hvector      ,
  .on_type_create_indexed_block =  cortex_python_translate_MPI_Type_create_indexed_block,
  .on_type_create_resized       =  cortex_python_translate_MPI_Type_create_resized      ,
  .on_type_create_struct        =  cortex_python_translate_MPI_Type_create_struct       ,
  .on_type_create_subarray      =  cortex_python_translate_MPI_Type_create_subarray     ,
  .on_type_get_extent           =  cortex_python_translate_MPI_Type_get_extent          ,
  .on_type_get_true_extent      =  cortex_python_translate_MPI_Type_get_true_extent     ,
  .on_unpack_external           =  cortex_python_translate_MPI_Unpack_external          ,
  .on_win_create_errhandler     =  cortex_python_translate_MPI_Win_create_errhandler    ,
  .on_win_get_errhandler        =  cortex_python_translate_MPI_Win_get_errhandler       ,
  .on_win_set_errhandler        =  cortex_python_translate_MPI_Win_set_errhandler       ,
  .on_file_open                 =  cortex_python_translate_MPI_File_open                ,
  .on_file_close                =  cortex_python_translate_MPI_File_close               ,
  .on_file_delete               =  cortex_python_translate_MPI_File_delete              ,
  .on_file_set_size             =  cortex_python_translate_MPI_File_set_size            ,
  .on_file_preallocate          =  cortex_python_translate_MPI_File_preallocate         ,
  .on_file_get_size             =  cortex_python_translate_MPI_File_get_size            ,
  .on_file_get_group            =  cortex_python_translate_MPI_File_get_group           ,
  .on_file_get_amode            =  cortex_python_translate_MPI_File_get_amode           ,
  .on_file_set_info             =  cortex_python_translate_MPI_File_set_info            ,
  .on_file_get_info             =  cortex_python_translate_MPI_File_get_info            ,
  .on_file_set_view             =  cortex_python_translate_MPI_File_set_view            ,
  .on_file_get_view             =  cortex_python_translate_MPI_File_get_view            ,
  .on_file_read_at              =  cortex_python_translate_MPI_File_read_at             ,
  .on_file_read_at_all          =  cortex_python_translate_MPI_File_read_at_all         ,
  .on_file_write_at             =  cortex_python_translate_MPI_File_write_at            ,
  .on_file_write_at_all         =  cortex_python_translate_MPI_File_write_at_all        ,
  .on_file_iread_at             =  cortex_python_translate_MPI_File_iread_at            ,
  .on_file_iwrite_at            =  cortex_python_translate_MPI_File_iwrite_at           ,
  .on_file_read                 =  cortex_python_translate_MPI_File_read                ,
  .on_file_read_all             =  cortex_python_translate_MPI_File_read_all            ,
  .on_file_write                =  cortex_python_translate_MPI_File_write               ,
  .on_file_write_all            =  cortex_python_translate_MPI_File_write_all           ,
  .on_file_iread                =  cortex_python_translate_MPI_File_iread               ,
  .on_file_iwrite               =  cortex_python_translate_MPI_File_iwrite              ,
  .on_file_seek                 =  cortex_python_translate_MPI_File_seek                ,
  .on_file_get_position         =  cortex_python_translate_MPI_File_get_position        ,
  .on_file_get_byte_offset      =  cortex_python_translate_MPI_File_get_byte_offset     ,
  .on_file_read_shared          =  cortex_python_translate_MPI_File_read_shared         ,
  .on_file_write_shared         =  cortex_python_translate_MPI_File_write_shared        ,
  .on_file_iread_shared         =  cortex_python_translate_MPI_File_iread_shared        ,
  .on_file_iwrite_shared        =  cortex_python_translate_MPI_File_iwrite_shared       ,
  .on_file_read_ordered         =  cortex_python_translate_MPI_File_read_ordered        ,
  .on_file_write_ordered        =  cortex_python_translate_MPI_File_write_ordered       ,
  .on_file_seek_shared          =  cortex_python_translate_MPI_File_seek_shared         ,
  .on_file_get_position_shared  =  cortex_python_translate_MPI_File_get_position_shared ,
  .on_file_read_at_all_begin    =  cortex_python_translate_MPI_File_read_at_all_begin   ,
  .on_file_read_at_all_end      =  cortex_python_translate_MPI_File_read_at_all_end     ,
  .on_file_write_at_all_begin   =  cortex_python_translate_MPI_File_write_at_all_begin  ,
  .on_file_write_at_all_end     =  cortex_python_translate_MPI_File_write_at_all_end    ,
  .on_file_read_all_begin       =  cortex_python_translate_MPI_File_read_all_begin      ,
  .on_file_read_all_end         =  cortex_python_translate_MPI_File_read_all_end        ,
  .on_file_write_all_begin      =  cortex_python_translate_MPI_File_write_all_begin     ,
  .on_file_write_all_end        =  cortex_python_translate_MPI_File_write_all_end       ,
  .on_file_read_ordered_begin   =  cortex_python_translate_MPI_File_read_ordered_begin  ,
  .on_file_read_ordered_end     =  cortex_python_translate_MPI_File_read_ordered_end    ,
  .on_file_write_ordered_begin  =  cortex_python_translate_MPI_File_write_ordered_begin ,
  .on_file_write_ordered_end    =  cortex_python_translate_MPI_File_write_ordered_end   ,
  .on_file_get_type_extent      =  cortex_python_translate_MPI_File_get_type_extent     ,
  .on_register_datarep          =  cortex_python_translate_MPI_Register_datarep         ,
  .on_file_set_atomicity        =  cortex_python_translate_MPI_File_set_atomicity       ,
  .on_file_get_atomicity        =  cortex_python_translate_MPI_File_get_atomicity       ,
  .on_file_sync                 =  cortex_python_translate_MPI_File_sync                ,
  .on_iotest                    =  cortex_python_translate_MPIO_Test                    ,
  .on_iowait                    =  cortex_python_translate_MPIO_Wait                    ,
  .on_iotestall                 =  cortex_python_translate_MPIO_Testall                 ,
  .on_iowaitall                 =  cortex_python_translate_MPIO_Waitall                 ,
  .on_iotestany                 =  cortex_python_translate_MPIO_Testany                 ,
  .on_iowaitany                 =  cortex_python_translate_MPIO_Waitany                 ,
  .on_iowaitsome                =  cortex_python_translate_MPIO_Waitsome                ,
  .on_iotestsome                =  cortex_python_translate_MPIO_Testsome                ,
  .on_function_enter            =  cortex_python_Function_enter                         ,
  .on_function_exit             =  cortex_python_Function_exit                                  
};

const libundumpi_callbacks* CORTEX_PYTHON_TRANSLATION = &cortex_python_translation;

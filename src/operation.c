/*
 * Copyright (C) 2016 University of Chicago
 * See COPYRIGHT notice in top-level directory.
 *
 */

#include <string.h>
#include "cortex/operation.h"
#include "cortex/util.h"

static void enqueue_operation(cortex_dumpi_profile* profile, cortex_operation* op) {
	if(profile->first_pending == NULL) {
		profile->first_pending = op;
		profile->last_pending = op;
		op->next = NULL;
		op->prev = NULL;
	} else {
		cortex_operation* last = profile->last_pending;
		profile->last_pending = op;
		op->prev = last;
		op->next = NULL;
		last->next = op;
	}
}

static cortex_operation* dequeue_operation(cortex_dumpi_profile* profile) {
	if(profile->first_pending == NULL) return NULL;
	cortex_operation* first = profile->first_pending;
	profile->first_pending = profile->first_pending->next;
	if(profile->first_pending != NULL) {
		profile->first_pending->prev = NULL;
	}
	first->prev = first->next = NULL;
	return first;
}

static void* copy_parameters(dumpi_function type, const void *prm) {
	static unsigned int typesize[] = {
#define X(a,b) sizeof(b),
	FOREACH_DUMPI_OPERATION
#undef X
	0};
	if(type >= DUMPI_ALL_FUNCTIONS) return NULL;
	unsigned int size = typesize[type];
	void* result = malloc(size);
	memcpy(result,prm,size);
	// here we handle the case of copying pointers
	// this should be done case-by case
#define COPY2(_fun,_type,_field,_size_field,_mult) {	\
	((_fun*)result)->_field = (_type*)malloc((((_fun*)prm)->_size_field)*sizeof(_type)*_mult); \
	memcpy(((_fun*)result)->_field,((_fun*)prm)->_field,(((_fun*)prm)->_size_field)*sizeof(_type)*_mult); }

#define COPY(_fun,_type,_field,_size_field) COPY2(_fun,_type,_field,_size_field,1)

#define STRCOPY(_fun,_field) ((_fun*)result)->_field = strdup(((_fun*)prm)->_field);
	int i,j;
	switch(type) {
	case DUMPI_Waitany:
		COPY(dumpi_waitany,dumpi_request,requests,count)
		break;
	case DUMPI_Testany:
		COPY(dumpi_testany,dumpi_request,requests,count)
		break;
	case DUMPI_Waitall:
		COPY(dumpi_waitall,dumpi_request,requests,count)
		break;
	case DUMPI_Testall:
		COPY(dumpi_testall,dumpi_request,requests,count)
		break;
	case DUMPI_Waitsome:
		COPY(dumpi_waitsome,dumpi_request,requests,count)
		break;
	case DUMPI_Testsome:
		COPY(dumpi_testsome,dumpi_request,requests,count)
		break;
	case DUMPI_Startall:
		COPY(dumpi_startall,dumpi_request,requests,count)
		break;
	case DUMPI_Type_indexed:
		COPY(dumpi_type_indexed,int,lengths,count)
		COPY(dumpi_type_indexed,int,indices,count)
		break;
	case DUMPI_Type_hindexed:
		COPY(dumpi_type_hindexed,int,lengths,count)
		COPY(dumpi_type_hindexed,int,indices,count)
		break;
	case DUMPI_Type_struct:
		COPY(dumpi_type_struct,int,lengths,count)
		COPY(dumpi_type_struct,int,indices,count)
		COPY(dumpi_type_struct,dumpi_datatype,oldtypes,count)
		break;
	case DUMPI_Gatherv:
		COPY(dumpi_gatherv,int,recvcounts,commsize)
		COPY(dumpi_gatherv,int,displs,commsize)
		break;
	case DUMPI_Scatterv:
		COPY(dumpi_scatterv,int,sendcounts,commsize)
		COPY(dumpi_scatterv,int,displs,commsize)
		break;
	case DUMPI_Allgatherv:
		COPY(dumpi_allgatherv,int,recvcounts,commsize)
		COPY(dumpi_allgatherv,int,displs,commsize)
		break;
	case DUMPI_Alltoallv:
		COPY(dumpi_alltoallv,int,sendcounts,commsize)
		COPY(dumpi_alltoallv,int,senddispls,commsize)
		COPY(dumpi_alltoallv,int,recvcounts,commsize)
		COPY(dumpi_alltoallv,int,recvdispls,commsize)
		break;
	case DUMPI_Reduce_scatter:
		COPY(dumpi_reduce_scatter,int,recvcounts,commsize)
		break;
	case DUMPI_Group_translate_ranks:
		COPY(dumpi_group_translate_ranks,int,ranks1,count)
		COPY(dumpi_group_translate_ranks,int,ranks2,count)
		break;
	case DUMPI_Group_incl:
		COPY(dumpi_group_incl,int,ranks,count)
		break;
	case DUMPI_Group_excl:
		COPY(dumpi_group_excl,int,ranks,count)
		break;
	case DUMPI_Group_range_incl:
		COPY2(dumpi_group_range_incl,int,ranges,count,3)
		break;
	case DUMPI_Group_range_excl:
		COPY2(dumpi_group_range_excl,int,ranges,count,3)
		break;
	case DUMPI_Cart_create:
		COPY(dumpi_cart_create,int,dims,ndim)
		COPY(dumpi_cart_create,int,periods,ndim)
		break;
	case DUMPI_Dims_create:
		COPY(dumpi_dims_create,int,dims.in,ndim)
		COPY(dumpi_dims_create,int,dims.out,ndim)
		break;
	case DUMPI_Graph_create:
		COPY(dumpi_graph_create,int,index,nodes)
		COPY(dumpi_graph_create,int,edges,numedges)
		break;
	case DUMPI_Graph_get:
		COPY(dumpi_graph_get,int,index,totnodes)
		COPY(dumpi_graph_get,int,edges,totedges)
		break;
	case DUMPI_Cart_get:
		COPY(dumpi_cart_get,int,dims,ndim)
		COPY(dumpi_cart_get,int,periods,ndim)
		COPY(dumpi_cart_get,int,coords,ndim)
		break;
	case DUMPI_Cart_rank:
		COPY(dumpi_cart_rank,int,coords,ndim)
		break;
	case DUMPI_Cart_coords:
		COPY(dumpi_cart_coords,int,coords,ndim)
		break;
	case DUMPI_Graph_neighbors:
		COPY(dumpi_graph_neighbors,int,neighbors,nneigh)
		break;
	case DUMPI_Cart_sub:
		COPY(dumpi_cart_sub,int,remain_dims,ndim)
		break;
	case DUMPI_Cart_map:
		COPY(dumpi_cart_map,int,dims,ndim)
		COPY(dumpi_cart_map,int,period,ndim)
		break;
	case DUMPI_Graph_map:
		COPY(dumpi_graph_map,int,index,nodes)
		COPY(dumpi_graph_map,int,edges,numedges)
		break;
	case DUMPI_Get_processor_name:
		STRCOPY(dumpi_get_processor_name,name)
		break;
	case DUMPI_Error_string:
		STRCOPY(dumpi_error_string,errorstring)
		break;
	case DUMPI_Init:
		((dumpi_init*)result)->argv = (char**)malloc(sizeof(char*)*((dumpi_init*)result)->argc);
		for(i=0; i<((dumpi_init*)prm)->argc; i++) {
			STRCOPY(dumpi_init,argv[i])
		}
		break;
	case DUMPI_Close_port:
		STRCOPY(dumpi_close_port,portname)
		break;
	case DUMPI_Comm_accept:
		STRCOPY(dumpi_comm_accept,portname)
		break;
	case DUMPI_Comm_connect:
		STRCOPY(dumpi_comm_connect,portname)
		break;
	case DUMPI_Comm_spawn:
		if(((dumpi_comm_spawn*)prm)->oldcommrank == ((dumpi_comm_spawn*)prm)->root) {
			STRCOPY(dumpi_comm_spawn,command)
			i = 0;
			while(((dumpi_comm_spawn*)prm)->argv[i] != NULL) i++;
			((dumpi_comm_spawn*)result)->argv = (char**)malloc(sizeof(char*)*(i+1));
			i = 0;
			while(((dumpi_comm_spawn*)prm)->argv[i] != NULL) {
				STRCOPY(dumpi_comm_spawn,argv[i])
				i++;
			}
		}
		break;
	case DUMPI_Comm_spawn_multiple:
		if(((dumpi_comm_spawn_multiple*)prm)->oldcommrank == ((dumpi_comm_spawn_multiple*)prm)->root) {
			((dumpi_comm_spawn_multiple*)result)->commands = (char**)malloc(sizeof(char*)*((dumpi_comm_spawn_multiple*)prm)->count);
			((dumpi_comm_spawn_multiple*)result)->argvs = (char***)malloc(sizeof(char**)*((dumpi_comm_spawn_multiple*)prm)->count);
			for(j=0; j < ((dumpi_comm_spawn_multiple*)prm)->count; j++) {
				STRCOPY(dumpi_comm_spawn_multiple,commands[j])
				i = 0;
				while(((dumpi_comm_spawn_multiple*)prm)->argvs[j][i] != NULL) i++;
				((dumpi_comm_spawn_multiple*)result)->argvs[j] = (char**)malloc(sizeof(char*)*(i+1));
				i = 0;
				 while(((dumpi_comm_spawn_multiple*)prm)->argvs[j][i] != NULL) {
					STRCOPY(dumpi_comm_spawn_multiple,argvs[j][i])
					i++;
				}
			}
		}
		break;
	case DUMPI_Lookup_name:
		STRCOPY(dumpi_lookup_name,servicename)
		STRCOPY(dumpi_lookup_name,portname)
		break;
	case DUMPI_Open_port:
		STRCOPY(dumpi_open_port,portname)
		break;
	case DUMPI_Publish_name:
		STRCOPY(dumpi_publish_name,servicename)
		STRCOPY(dumpi_publish_name,portname)
		break;
	case DUMPI_Unpublish_name:
		STRCOPY(dumpi_unpublish_name,servicename)
		STRCOPY(dumpi_unpublish_name,portname)
		break;
	case DUMPI_Alltoallw:
		COPY(dumpi_alltoallw,int,sendcounts,commsize)
		COPY(dumpi_alltoallw,int,senddispls,commsize)
		COPY(dumpi_alltoallw,dumpi_datatype,sendtypes,commsize)
		COPY(dumpi_alltoallw,int,recvcounts,commsize)
		COPY(dumpi_alltoallw,int,recvdispls,commsize)
		COPY(dumpi_alltoallw,dumpi_datatype,recvtypes,commsize)
		break;
	case DUMPI_Add_error_string:
		STRCOPY(dumpi_add_error_string,errorstring)
		break;
	case DUMPI_Comm_get_name:
		STRCOPY(dumpi_comm_get_name,name)
		break;
	case DUMPI_Comm_set_name:
		STRCOPY(dumpi_comm_set_name,name)
		break;
	case DUMPI_Init_thread:
		((dumpi_init_thread*)result)->argv = (char**)malloc(sizeof(char*)*((dumpi_init_thread*)prm)->argc);
		for(i=0; i<((dumpi_init_thread*)prm)->argc; i++) {
			STRCOPY(dumpi_init_thread,argv[i])
		}
		break;
	case DUMPI_Type_get_contents:
		COPY(dumpi_type_get_contents,int,arrintegers,numintegers)
		COPY(dumpi_type_get_contents,int,arraddresses,numdatatypes)
		break;
	case DUMPI_Type_get_name:
		STRCOPY(dumpi_type_get_name,name)
		break;
	case DUMPI_Type_set_name:
		STRCOPY(dumpi_type_set_name,name)
		break;
	case DUMPI_Info_get:
		STRCOPY(dumpi_info_get,key)
		STRCOPY(dumpi_info_get,value)
		break;
	case DUMPI_Info_get_nthkey:
		STRCOPY(dumpi_info_get_nthkey,key)
		break;
	case DUMPI_Info_get_valuelen:
		STRCOPY(dumpi_info_get_valuelen,key)
		break;
	case DUMPI_Info_set:
		STRCOPY(dumpi_info_set,key)
		STRCOPY(dumpi_info_set,value)
		break;
	case DUMPI_Pack_external:
		STRCOPY(dumpi_pack_external,datarep)
		break;
	case DUMPI_Pack_external_size:
		STRCOPY(dumpi_pack_external_size,datarep)
		break;
	case DUMPI_Type_create_darray:
		COPY(dumpi_type_create_darray,int,gsizes,ndims)
		COPY(dumpi_type_create_darray,dumpi_distribution,distribs,ndims)
		COPY(dumpi_type_create_darray,int,dargs,ndims)
		COPY(dumpi_type_create_darray,int,psizes,ndims)
		break;
	case DUMPI_Type_create_hindexed:
		COPY(dumpi_type_create_hindexed,int,blocklengths,count)
		COPY(dumpi_type_create_hindexed,int,displacements,count)
		break;
	case DUMPI_Type_create_indexed_block:
		COPY(dumpi_type_create_indexed_block,int,displacments,count)
		break;
	case DUMPI_Type_create_struct:
		COPY(dumpi_type_create_struct,int,blocklengths,count)
		COPY(dumpi_type_create_struct,int,displacements,count)
		COPY(dumpi_type_create_struct,dumpi_datatype,oldtypes,count)
		break;
	case DUMPI_Type_create_subarray:
		COPY(dumpi_type_create_subarray,int,sizes,ndims)
		COPY(dumpi_type_create_subarray,int,subsizes,ndims)
		COPY(dumpi_type_create_subarray,int,starts,ndims)
		break;
	case DUMPI_Unpack_external:
		STRCOPY(dumpi_unpack_external,datarep)
		break;
	case DUMPI_File_open:
		STRCOPY(dumpi_file_open,filename)
		break;
	case DUMPI_File_delete:
		STRCOPY(dumpi_file_delete,filename)
		break;
	case DUMPI_File_set_view:
		STRCOPY(dumpi_file_set_view,datarep)
		break;
	case DUMPI_File_get_view:
		STRCOPY(dumpi_file_get_view,datarep)
		break;
	}
	return result;
}

static cortex_operation* create_operation(dumpi_function type, const void *prm,
					uint16_t thread, const dumpi_time *cpu,
					const dumpi_time *wall, const dumpi_perfinfo *perf) {
	cortex_operation* op = (cortex_operation*)malloc(sizeof(cortex_operation));
	op->type = type;
	op->args = copy_parameters(type,prm);
	op->thread = thread;
	op->cpu    = *cpu;
	op->wall   = *wall;
	op->perf   = *perf;
	return op;
}

static void fee_operation(cortex_operation* op) {
	if(op->args) free(op->args);
	free(op);
}

int cortex_has_operation(cortex_dumpi_profile* profile)
{
	return profile->first_pending != NULL;
}

int cortex_post(cortex_dumpi_profile* profile,
		dumpi_function type,
		const void *prm,
		uint16_t thread,
		const dumpi_time *cpu,
		const dumpi_time *wall,
		const dumpi_perfinfo *perf)
{
	cortex_operation* op = create_operation(type,prm,thread,cpu,wall,perf);
	enqueue_operation(profile,op);
	return 0;
}

int cortex_exec(cortex_dumpi_profile* profile, libundumpi_cbpair* callarr, void* uargs, int* mpi_finalized)
{
	cortex_operation* op = dequeue_operation(profile);
	int i = op->type;

	if(op->type == DUMPI_Finalize) *mpi_finalized = 1;
	else *mpi_finalized = 0;

	libundumpi_unsafe_fun callout = callarr[i].callout;
	if(callout) callout(op->args, op->thread, &(op->cpu), &(op->wall), &(op->perf), uargs);

	fee_operation(op);
	return 0;
}

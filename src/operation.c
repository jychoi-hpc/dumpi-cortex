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
	// TODO: for now all "status"-type pointers are ignored
	// TODO: not all the types are handles bellow
#define COPY(_fun,_type,_field,_size_field) {	\
	((_fun*)result)->_field = (_type*)malloc((((_fun*)prm)->_size_field)*sizeof(_type)); \
	memcpy(((_fun*)result)->_field,((_fun*)prm)->_field,(((_fun*)prm)->_size_field)*sizeof(_type)); }
	
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
		// TODO
	case DUMPI_Type_struct:

	case DUMPI_Gatherv:

	case DUMPI_Scatterv:

	case DUMPI_Allgatherv:

	case DUMPI_Alltoallv:

	case DUMPI_Reduce_scatter:

	case DUMPI_Group_translate_ranks:

	case DUMPI_Group_incl:

	case DUMPI_Group_excl:

	case DUMPI_Group_range_incl:

	case DUMPI_Group_range_excl:

	case DUMPI_Cart_create:

	case DUMPI_Dims_create:

	case DUMPI_Graph_create:

	case DUMPI_Graph_get:

	case DUMPI_Cart_get:

	case DUMPI_Cart_rank:

	case DUMPI_Cart_coords:

	case DUMPI_Graph_neighbors:

	case DUMPI_Cart_sub:

	case DUMPI_Cart_map:

	case DUMPI_Graph_map:

	case DUMPI_Get_processor_name:

	case DUMPI_Error_string:

	case DUMPI_Init:

	case DUMPI_Close_port:

	case DUMPI_Comm_accept:

	case DUMPI_Comm_connect:

	case DUMPI_Comm_spawn:

	case DUMPI_Comm_spawn_multiple:

	case DUMPI_Lookup_name:

	case DUMPI_Open_port:

	case DUMPI_Publish_name:

	case DUMPI_Unpublish_name:

	case DUMPI_Alltoallw:

	case DUMPI_Add_error_string:

	case DUMPI_Comm_get_name:

	case DUMPI_Comm_set_name:

	case DUMPI_Init_thread:

	case DUMPI_Type_get_contents:

	case DUMPI_Type_get_name:

	case DUMPI_Type_set_name:

	case DUMPI_Info_get:

	case DUMPI_Info_get_nthkey:

	case DUMPI_Info_get_valuelen:

	case DUMPI_Info_set:

	case DUMPI_Pack_external:

	case DUMPI_Pack_external_size:

	case DUMPI_Type_create_darray:

	case DUMPI_Type_create_hindexed:

	case DUMPI_Type_create_indexed_block:

	case DUMPI_Type_create_struct:

	case DUMPI_Type_create_subarray:

	case DUMPI_Unpack_external:

	case DUMPI_File_open:

	case DUMPI_File_delete:

	case DUMPI_File_set_view:

	case DUMPI_File_get_view:

		fprintf(stderr,"Error in file %s line %d, please see developer",__FILE__,__LINE__);
		exit(-1);
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

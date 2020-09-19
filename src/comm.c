#include <uthash/uthash.h>
#include "cortex/comm.h"
#include "cortex/profile.h"

typedef struct cortex_comm {
	dumpi_comm handle;
	unsigned int size;
	UT_hash_handle hh;
} cortex_comm;

#define HASH_FIND_COMM(head,findint,out)\
		HASH_FIND(hh,head,findint,sizeof(dumpi_comm),out)

#define HASH_ADD_COMM(head,intfield,add)\
		HASH_ADD(hh,head,intfield,sizeof(dumpi_comm),add)

comm_info_t* cortex_lookup(cortex_dumpi_profile* profile, dumpi_comm prm_comm);

int cortex_comm_add(cortex_dumpi_profile* profile, dumpi_comm comm, int size) {
	cortex_comm* ccomm = NULL;
	HASH_FIND_COMM((profile->comms), &comm, ccomm);
	if(ccomm) return -1; // comm already added

	ccomm = (cortex_comm*)malloc(sizeof(cortex_comm));
	ccomm->handle = comm;
	ccomm->size = size;

	cortex_comm** root = &(profile->comms);
	HASH_ADD_COMM(*root, handle, ccomm);
	return 0;
}

cortex_comm* cortex_comm_find(cortex_dumpi_profile* profile, dumpi_comm comm) {
	cortex_comm* ccomm = NULL;
	cortex_comm** root = &(profile->comms);
	int comm_int = comm;
	HASH_FIND_COMM(*root, &comm_int, ccomm);
	return ccomm;
}

void cortex_comm_delete(cortex_dumpi_profile* profile, dumpi_comm comm) {
	cortex_comm* ccomm =  cortex_comm_find(profile, comm);
	cortex_comm** root = &(profile->comms);
	if(ccomm) {
		HASH_DEL(*root, ccomm);
		free(ccomm);
	}
}

void cortex_comm_delete_all(cortex_dumpi_profile* profile) {
	cortex_comm *ccomm, *tmp;
	cortex_comm **root = &(profile->comms);
	HASH_ITER(hh, *root, ccomm, tmp) {
		HASH_DEL((profile->comms), ccomm);
		free(ccomm);
	}
}

int cortex_comm_get_size(cortex_dumpi_profile* profile, dumpi_comm comm, int* size) {
	/*
	cortex_comm* ccomm = cortex_comm_find(profile, comm);
	if(ccomm == NULL) {
		return -1;
	}
	*size = ccomm->size;
	*/
	comm_info_t* ccomm = cortex_lookup(profile, comm);
	*size = ccomm->size;
	return 0;
}

int cortex_comm_dup(cortex_dumpi_profile* profile, dumpi_comm oldc, dumpi_comm newc) {
	cortex_comm* ccomm = cortex_comm_find(profile,oldc);
	if(ccomm == NULL) {
		return -1;
	}

	cortex_comm* ccomm_new = cortex_comm_find(profile,newc);
	if(ccomm_new) {
		return -1;
	}

	ccomm_new = (cortex_comm*)malloc(sizeof(cortex_comm));
	ccomm_new->handle = newc;
	ccomm_new->size = ccomm->size;
	cortex_comm** root = &(profile->comms);
	HASH_ADD_COMM(*root, handle, ccomm_new);

	ccomm_new = cortex_comm_find(profile,newc);
	return 0;
}

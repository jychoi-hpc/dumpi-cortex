#include "cortex/comm.h"

int cortex_comm_add(cortex_dumpi_profile* profile, dumpi_comm comm, int size) {
	cortex_comm* ccomm = NULL;
	HASH_FIND_INT(profile->comms, &comm, ccomm);
	if(ccomm) return -1; // comm already added

	ccomm = (cortex_comm*)malloc(sizeof(cortex_comm));
	ccomm->handle = comm;
	ccomm->size = size;
	HASH_ADD_INT(profile->comms, handle, ccomm);

	return 0;
}

cortex_comm* cortex_comm_find(cortex_dumpi_profile* profile, dumpi_comm comm) {
	cortex_comm* ccomm = NULL;
	HASH_FIND_INT(profile->comms, &comm, ccomm);
	return ccomm;
}

void cortex_comm_delete(cortex_dumpi_profile* profile, dumpi_comm comm) {
	cortex_comm* ccomm =  cortex_comm_find(profile, comm);
	if(ccomm) {
		HASH_DEL(profile->comms, ccomm);
		free(ccomm);
	}
}

void cortex_comm_delete_all(cortex_dumpi_profile* profile) {
	cortex_comm *ccomm, *tmp;
	cortex_comm *root = profile->comms;
	HASH_ITER(hh, root, ccomm, tmp) {
		HASH_DEL(root, ccomm);
		free(ccomm);
	}
}

int cortex_comm_get_size(cortex_dumpi_profile* profile, dumpi_comm comm, int* size) {
	cortex_comm* ccomm = cortex_comm_find(profile, comm);
	if(ccomm == NULL) return -1;
	*size = ccomm->size;
	return 0;
}

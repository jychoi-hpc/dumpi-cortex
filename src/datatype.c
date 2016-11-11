#include "cortex/datatype.h"
#include "cortex/profile.h"
#include <uthash/uthash.h>

typedef struct cortex_datatype {
	dumpi_datatype handle;
	unsigned int size;
	UT_hash_handle hh;
} cortex_datatype;

#define HASH_FIND_DTYPE(head,findint,out)\
		HASH_FIND(hh,head,findint,sizeof(dumpi_datatype),out)

#define HASH_ADD_DTYPE(head,intfield,add)\
		HASH_ADD(hh,head,intfield,sizeof(dumpi_datatype),add)

int cortex_datatype_get_size(cortex_dumpi_profile* profile, dumpi_datatype dt)
{
	switch(dt) {
	case DUMPI_DATATYPE_ERROR:
	case DUMPI_DATATYPE_NULL:
		return -1;
		break;
	case DUMPI_CHAR:
	case DUMPI_UNSIGNED_CHAR:
	case DUMPI_SIGNED_CHAR:
	case DUMPI_BYTE:
		return 1;
		break;
	case DUMPI_WCHAR:
		return 4;
		break;
	case DUMPI_SHORT:
	case DUMPI_SHORT_INT:
	case DUMPI_UNSIGNED_SHORT:
		return 2;
		break;
	case DUMPI_INT:
	case DUMPI_UNSIGNED:
	case DUMPI_FLOAT:
	case DUMPI_FLOAT_INT:
		return 4;
		break;
	case DUMPI_DOUBLE:
	case DUMPI_LONG:
	case DUMPI_LONG_INT:
	case DUMPI_UNSIGNED_LONG:
	case DUMPI_LONG_LONG_INT:
	case DUMPI_UNSIGNED_LONG_LONG:
	case DUMPI_LONG_LONG:
	case DUMPI_DOUBLE_INT:
		return 8;
		break;
	case DUMPI_LONG_DOUBLE:
	case DUMPI_LONG_DOUBLE_INT:
		return 16;
		break;
	}

	cortex_datatype* cdt = cortex_datatype_find(profile, dt);
	if(cdt != NULL) return cdt->size;
	
	return 0;
}

int cortex_datatype_add(cortex_dumpi_profile* profile, dumpi_datatype dt, int size) {
	cortex_datatype* cdt = NULL;
	HASH_FIND_DTYPE((profile->dtypes), &dt, cdt);
	if(cdt) return -1; // datatype already added

	cdt = (cortex_datatype*)malloc(sizeof(cortex_datatype));
	cdt->handle = dt;
	cdt->size = size;

	cortex_datatype** root = &(profile->dtypes);
	HASH_ADD_DTYPE(*root, handle, cdt);
	return 0;
}

cortex_datatype* cortex_datatype_find(cortex_dumpi_profile* profile, dumpi_datatype dt) {
	cortex_datatype* cdt = NULL;
	cortex_datatype** root = &(profile->dtypes);
	int dt_int = dt;
	HASH_FIND_DTYPE(*root, &dt_int, cdt);
	return cdt;
}

void cortex_datatype_delete(cortex_dumpi_profile* profile, dumpi_datatype dt) {
	cortex_datatype* cdt =  cortex_datatype_find(profile, dt);
	cortex_datatype** root = &(profile->dtypes);
	if(cdt) {
		HASH_DEL(*root, cdt);
		free(cdt);
	}
}

void cortex_datatype_delete_all(cortex_dumpi_profile* profile) {
	cortex_datatype *cdt, *tmp;
	cortex_datatype **root = &(profile->dtypes);
	HASH_ITER(hh, *root, cdt, tmp) {
		HASH_DEL((profile->dtypes), cdt);
		free(cdt);
	}
}

int cortex_datatype_dup(cortex_dumpi_profile* profile, dumpi_datatype oldc, dumpi_datatype newc) {
	cortex_datatype* cdt = cortex_datatype_find(profile,oldc);
	if(cdt == NULL) {
		return -1;
	}

	cortex_datatype* cdt_new = cortex_datatype_find(profile,newc);
	if(cdt_new) {
		return -1;
	}

	cdt_new = (cortex_datatype*)malloc(sizeof(cortex_datatype));
	cdt_new->handle = newc;
	cdt_new->size = cdt->size;
	cortex_datatype** root = &(profile->dtypes);
	HASH_ADD_DTYPE(*root, handle, cdt_new);

	cdt_new = cortex_datatype_find(profile,newc);
	return 0;
}

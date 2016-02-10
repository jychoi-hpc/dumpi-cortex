#include "cortex/datatype.h"

int cortex_datatype_get_size(dumpi_datatype dt)
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
	default:
		return 0; // TODO handle user-defined datatypes
	}
}

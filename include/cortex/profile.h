#include <dumpi/libundumpi/bindings.h>
#include <dumpi/libundumpi/libundumpi.h>

typedef struct cortex_dumpi_profile {
	dumpi_profile* dumpi; /* internal dumpi profile */
	libundumpi_callbacks cbacks; /* callbacks for cortex */
	libundumpi_cbpair callarr[DUMPI_END_OF_STREAM]; // same callbacks in the form of an array */
} cortex_dumpi_profile;

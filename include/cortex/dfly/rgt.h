#ifndef DFLY_RGT_BCAST_H
#define DFLY_RGT_BCAST_H

#include "cortex/dfly/bcast_context.h"
#include "cortex/profile.h"

#ifdef __cplusplus
extern "C" {
#endif

int dfly_bcast_setup_rgt(job_id_t job_id, dumpi_comm comm, int16_t root, int16_t rank, int16_t size, bcast_ctx* ctx);

#ifdef __cplusplus
}
#endif

#endif

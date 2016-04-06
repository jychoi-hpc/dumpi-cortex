#ifndef DFLY_BCAST_CONTEXT_H
#define DFLY_BCAST_CONTEXT_H

#include "cortex/cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	dumpi_comm comm;
	int16_t root;
	int16_t recv_from;
	int16_t* send_to;
	int	send_cnt;
} bcast_ctx;

#ifdef __cplusplus
}
#endif

#endif

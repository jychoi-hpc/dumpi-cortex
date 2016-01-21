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

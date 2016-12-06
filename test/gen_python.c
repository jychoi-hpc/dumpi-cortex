#include <cortex/cortex.h>
#include <cortex/cortex-python.h>
#include <string.h>

static int handleDUMPIInit(const dumpi_init *prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	//printf("MPI_Init called\n");
	return 0;
}

static int handleDUMPISendrecv(const dumpi_sendrecv* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	//printf("MPI_Sendrecv called with src=%d and dst=%d\n",prm->source,prm->dest);
	return 0;
}

static int handleDUMPISend(const dumpi_send* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	printf("MPI_Send called with dst=%d\n",prm->dest);
	return 0;
}

static int handleDUMPIRecv(const dumpi_recv* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	printf("MPI_Recv called with src=%d\n",prm->source);
	return 0;
}

static int handleDUMPIBcast(const dumpi_bcast* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	printf("MPI_Bcast called with root=%d\n",prm->root);
	return 0;
}

static int handleDUMPIBarrier(const dumpi_barrier* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	//printf("MPI_Barrier called\n");
	return 0;
}

static int handleDUMPIReduce(const dumpi_reduce* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	//printf("MPI_Reduce called\n");
	return 0;
}

static int handleDUMPIAllReduce(const dumpi_allreduce* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	//printf("MPI_Allreduce called\n");
	return 0;
}

static int handleDUMPIAllgather(const dumpi_allgather* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	//printf("MPI_Allgather called\n");
	return 0;
}

static int handleDUMPIAllgatherv(const dumpi_allgatherv* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	//printf("MPI_Allgatherv called\n");
	return 0;
} 

int main(int argc, char** argv) {
	
	if(argc != 3) {
		printf("Usage: %s world_size rank\n", argv[0]);
		exit(-1);
	}
	int world_size = atoi(argv[1]);
	int rank = atoi(argv[2]);

	if(rank < 0 || rank >= world_size) {
		printf("Invalid rank\n");
		exit(-1);
	}

	cortex_dumpi_profile* profile = cortex_undumpi_open(NULL,12345,world_size,rank);

	if(!profile) {
		exit(-1);
	}

	libundumpi_callbacks cbacks;
	memset(&cbacks,0,sizeof(cbacks));
	cbacks.on_init 		= handleDUMPIInit;
	cbacks.on_sendrecv 	= handleDUMPISendrecv;
	cbacks.on_barrier 	= handleDUMPIBarrier;
	cbacks.on_send		= handleDUMPISend;
	cbacks.on_recv		= handleDUMPIRecv;
	cbacks.on_bcast		= handleDUMPIBcast;
	cbacks.on_reduce	= handleDUMPIReduce;
	cbacks.on_allreduce	= handleDUMPIAllReduce;
	cbacks.on_allgather	= handleDUMPIAllgather;
	cbacks.on_allgatherv	= handleDUMPIAllgatherv;

	cortex_python_set_module("MyGenerator",NULL);

	cortex_python_call_generator(profile, "GenerateThings");

	cortex_undumpi_read_stream(profile, &cbacks, CORTEX_PYTHON_TRANSLATION, NULL);

	cortex_undumpi_close(profile);

	return 0;
}

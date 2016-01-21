#include <cortex/cortex.h>
#include <cortex/post.h>
#include <string.h>

static int handleDUMPIInit(const dumpi_init *prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	printf("MPI_Init called\n");
	return 0;
}

static int handleDUMPISendrecv(const dumpi_sendrecv* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	printf("MPI_Sendrecv called\n");
	return 0;
}

static handleDUMPIBarrier(const dumpi_barrier* prm, uint16_t thread,
			const dumpi_time *cpu, const dumpi_time *wall,
			const dumpi_perfinfo *perf, void *uarg) {
	printf("MPI_Barrier called\n");
	return 0;
}

int cortex_translate_MPI_Init(const dumpi_init *prm, uint16_t thread, const dumpi_time *cpu, const dumpi_time *wall, const dumpi_perfinfo *perf, void *uarg) {
	printf("cortex_MPI_Init overloaded\n");
	cortex_post_MPI_Init(prm,thread,cpu,wall,perf,uarg);
	return 0;
}

int main(int argc, char** argv) {
	
	if(argc != 2) {
		printf("Usage: %s dumpifile.bin\n", argv[0]);
		exit(-1);
	}

	const char* filename = argv[1];

	cortex_dumpi_profile* profile = cortex_undumpi_open(filename,9);

	if(!profile) {
		fprintf(stderr,"Unable to open file %s\n",filename);
		exit(-1);
	}

	libundumpi_callbacks cbacks;
	memset(&cbacks,0,sizeof(cbacks));
	cbacks.on_init = handleDUMPIInit;
	cbacks.on_sendrecv = handleDUMPISendrecv;
	cbacks.on_barrier = handleDUMPIBarrier;

	cortex_dumpi_start_stream_read(profile);

	cortex_undumpi_read_stream(profile,&cbacks,NULL);

	cortex_undumpi_close(profile);

	return 0;
}

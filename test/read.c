#include <cortex/cortex.h>

int main(int argc, char** argv) {
	
	if(argc != 2) {
		printf("Usage: %s dumpifile.bin\n", argv[0]);
		exit(-1);
	}

	const char* filename = argv[1];

	cortex_dumpi_profile* profile = cortex_undumpi_open(filename);

	if(!profile) {
		fprintf(stderr,"Unable to open file %s\n",filename);
		exit(-1);
	}

	cortex_dumpi_start_stream_read(profile);

	cortex_undumpi_read_stream(profile,NULL,NULL);

	cortex_undumpi_close(profile);

	return 0;
}

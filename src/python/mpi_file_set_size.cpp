#include <boost/python.hpp>
#include "cortex/profile.h"
#include "cortex/python-util.hpp"
#include "cortex/cortex.h"
#include "cortex/debug.h"

namespace bp = boost::python;

extern bool cortex_python_initialized;
extern bp::object user_python_translator;
extern bp::object cortex_python_translator;
extern void* cortex_python_current_uarg;
extern const dumpi_time* cortex_python_current_cpu;
extern const dumpi_time* cortex_python_current_wall;
extern const dumpi_perfinfo* cortex_python_current_perf;

static void dumpi_file_set_size_to_python(bp::dict& args, const dumpi_file_set_size *prm) {

    args["file"]	= prm->file;
    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_File_set_size(const dumpi_file_set_size *prm, 
			uint16_t thread, 
			const dumpi_time *cpu, 
			const dumpi_time *wall,
			const dumpi_perfinfo *perf,
			void *uarg) {
	if(!cortex_python_initialized) {
		ERROR("Python module not set");
	}

	bp::object fun;
	try {
		fun = user_python_translator.attr("MPI_File_set_size");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_set_size, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_set_size_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

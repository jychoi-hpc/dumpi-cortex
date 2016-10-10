#include <boost/python.hpp>
#include "cortex/python-util.hpp"
#include "cortex/cortex.h"
#include "cortex/debug.h"

namespace bp = boost::python;

extern bool cortex_python_initialized;
extern bp::object user_python_translator;
extern bp::object cortex_python_translator;
extern void* cortex_python_current_uarg;

static void dumpi_waitsome_to_python(bp::dict& args, const dumpi_waitsome *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpi_request>(prm->requests,prm->requests+prm->count));
    args["outcount"]	= prm->outcount;
    args["indices"]	= stl_vector_to_py_list(std::vector<int>(prm->indices,prm->indices+prm->outcount));
    args["statuses"]	= stl_vector_to_py_list(std::vector<dumpi_status>(prm->statuses,prm->statuses+prm->outcount));

}

extern "C" int cortex_python_translate_MPI_Waitsome(const dumpi_waitsome *prm, 
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
		fun = user_python_translator.attr("MPI_Waitsome");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPI_Waitsome, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	try {
		bp::dict arguments;
		dumpi_waitsome_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	return 0;
}

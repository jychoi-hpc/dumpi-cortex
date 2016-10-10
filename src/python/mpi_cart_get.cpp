#include <boost/python.hpp>
#include "cortex/python-util.hpp"
#include "cortex/cortex.h"
#include "cortex/debug.h"

namespace bp = boost::python;

extern bool cortex_python_initialized;
extern bp::object user_python_translator;
extern bp::object cortex_python_translator;
extern void* cortex_python_current_uarg;

static void dumpi_cart_get_to_python(bp::dict& args, const dumpi_cart_get *prm) {

    args["ndim"]	= prm->ndim;
    args["comm"]	= prm->comm;
    args["maxdims"]	= prm->maxdims;
    args["dims"]	= stl_vector_to_py_list(std::vector<int>(prm->dims,prm->dims+prm->ndim));
    args["periods"]	= stl_vector_to_py_list(std::vector<int>(prm->periods,prm->periods+prm->ndim));
    args["coords"]	= stl_vector_to_py_list(std::vector<int>(prm->coords,prm->coords+prm->ndim));

}

extern "C" int cortex_python_translate_MPI_Cart_get(const dumpi_cart_get *prm, 
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
		fun = user_python_translator.attr("MPI_Cart_get");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPI_Cart_get, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	try {
		bp::dict arguments;
		dumpi_cart_get_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	return 0;
}

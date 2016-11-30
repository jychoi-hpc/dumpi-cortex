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

static void dumpi_type_create_darray_to_python(bp::dict& args, const dumpi_type_create_darray *prm) {

    args["size"]	= prm->size;
    args["rank"]	= prm->rank;
    args["ndims"]	= prm->ndims;
    args["gsizes"]	= stl_vector_to_py_list(std::vector<int>(prm->gsizes,prm->gsizes+prm->ndims));
    args["distribs"]	= stl_vector_to_py_list(std::vector<int>(prm->distribs,prm->distribs+prm->ndims));
    args["dargs"]	= stl_vector_to_py_list(std::vector<int>(prm->dargs,prm->dargs+prm->ndims));
    args["psizes"]	= stl_vector_to_py_list(std::vector<int>(prm->psizes,prm->psizes+prm->ndims));
    args["order"]	= prm->order;
    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_create_darray(const dumpi_type_create_darray *prm, 
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
		fun = user_python_translator.attr("MPI_Type_create_darray");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_create_darray, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_create_darray_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

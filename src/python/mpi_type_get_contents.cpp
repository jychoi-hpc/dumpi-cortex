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

static void dumpi_type_get_contents_to_python(bp::dict& args, const dumpi_type_get_contents *prm) {

    args["numdatatypes"]	= prm->numdatatypes;
    args["numaddresses"]	= prm->numaddresses;
    args["numintegers"]	= prm->numintegers;
    args["datatype"]	= prm->datatype;
    args["maxintegers"]	= prm->maxintegers;
    args["maxaddresses"]	= prm->maxaddresses;
    args["maxdatatypes"]	= prm->maxdatatypes;
    args["arrintegers"]	= stl_vector_to_py_list(std::vector<int>(prm->arrintegers,prm->arrintegers+prm->numintegers));
    args["arraddresses"]	= stl_vector_to_py_list(std::vector<int>(prm->arraddresses,prm->arraddresses+prm->numaddresses));
    args["arrdatatypes"]	= stl_vector_to_py_list(std::vector<dumpi_datatype>(prm->arrdatatypes,prm->arrdatatypes+prm->numdatatypes));

}

extern "C" int cortex_python_translate_MPI_Type_get_contents(const dumpi_type_get_contents *prm, 
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
		fun = user_python_translator.attr("MPI_Type_get_contents");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_get_contents, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_get_contents_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

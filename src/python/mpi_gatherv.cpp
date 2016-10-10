#include <boost/python.hpp>
#include "cortex/python-util.hpp"
#include "cortex/cortex.h"
#include "cortex/debug.h"

namespace bp = boost::python;

extern bool cortex_python_initialized;
extern bp::object user_python_translator;
extern bp::object cortex_python_translator;
extern void* cortex_python_current_uarg;

static void dumpi_gatherv_to_python(bp::dict& args, const dumpi_gatherv *prm) {

    args["commrank"]	= prm->commrank;
    args["commsize"]	= prm->commsize;
    args["sendcount"]	= prm->sendcount;
    args["sendtype"]	= prm->sendtype;
    args["recvcounts"]	= stl_vector_to_py_list(std::vector<int>(prm->recvcounts,prm->recvcounts+prm->commsize));
    args["displs"]	= stl_vector_to_py_list(std::vector<int>(prm->displs,prm->displs+prm->commsize));
    args["recvtype"]	= prm->recvtype;
    args["root"]	= prm->root;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Gatherv(const dumpi_gatherv *prm, 
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
		fun = user_python_translator.attr("MPI_Gatherv");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPI_Gatherv, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	try {
		bp::dict arguments;
		dumpi_gatherv_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	return 0;
}

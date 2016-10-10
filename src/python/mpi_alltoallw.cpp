#include <boost/python.hpp>
#include "cortex/python-util.hpp"
#include "cortex/cortex.h"
#include "cortex/debug.h"

namespace bp = boost::python;

extern bool cortex_python_initialized;
extern bp::object user_python_translator;
extern bp::object cortex_python_translator;
extern void* cortex_python_current_uarg;

static void dumpi_alltoallw_to_python(bp::dict& args, const dumpi_alltoallw *prm) {

    args["commsize"]	= prm->commsize;
    args["sendcounts"]	= stl_vector_to_py_list(std::vector<int>(prm->sendcounts,prm->sendcounts+prm->commsize));
    args["senddispls"]	= stl_vector_to_py_list(std::vector<int>(prm->senddispls,prm->senddispls+prm->commsize));
    args["sendtypes"]	= stl_vector_to_py_list(std::vector<dumpi_datatype>(prm->sendtypes,prm->sendtypes+prm->commsize));
    args["recvcounts"]	= stl_vector_to_py_list(std::vector<int>(prm->recvcounts,prm->recvcounts+prm->commsize));
    args["recvdispls"]	= stl_vector_to_py_list(std::vector<int>(prm->recvdispls,prm->recvdispls+prm->commsize));
    args["recvtypes"]	= stl_vector_to_py_list(std::vector<dumpi_datatype>(prm->recvtypes,prm->recvtypes+prm->commsize));
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Alltoallw(const dumpi_alltoallw *prm, 
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
		fun = user_python_translator.attr("MPI_Alltoallw");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPI_Alltoallw, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	try {
		bp::dict arguments;
		dumpi_alltoallw_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	return 0;
}

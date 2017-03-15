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

static void dumpi_abort_to_python(bp::dict& args, const dumpi_abort *prm) {

    args["comm"]	= prm->comm;
    args["errorcode"]	= prm->errorcode;

}

extern "C" int cortex_python_translate_MPI_Abort(const dumpi_abort *prm, 
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
		fun = user_python_translator.attr("MPI_Abort");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Abort, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_abort_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;
	cortex_python_current_wall = NULL;
	cortex_python_current_perf = NULL;
	return 0;
}

static void dumpi_accumulate_to_python(bp::dict& args, const dumpi_accumulate *prm) {

    args["origincount"]	= prm->origincount;
    args["origintype"]	= prm->origintype;
    args["targetrank"]	= prm->targetrank;
    args["targetdisp"]	= prm->targetdisp;
    args["targetcount"]	= prm->targetcount;
    args["targettype"]	= prm->targettype;
    args["op"]	= prm->op;
    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Accumulate(const dumpi_accumulate *prm, 
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
		fun = user_python_translator.attr("MPI_Accumulate");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Accumulate, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_accumulate_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_add_error_class_to_python(bp::dict& args, const dumpi_add_error_class *prm) {

    args["errorclass"]	= prm->errorclass;

}

extern "C" int cortex_python_translate_MPI_Add_error_class(const dumpi_add_error_class *prm, 
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
		fun = user_python_translator.attr("MPI_Add_error_class");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Add_error_class, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_add_error_class_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_add_error_code_to_python(bp::dict& args, const dumpi_add_error_code *prm) {

    args["errorclass"]	= prm->errorclass;
    args["errorcode"]	= prm->errorcode;

}

extern "C" int cortex_python_translate_MPI_Add_error_code(const dumpi_add_error_code *prm, 
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
		fun = user_python_translator.attr("MPI_Add_error_code");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Add_error_code, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_add_error_code_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_add_error_string_to_python(bp::dict& args, const dumpi_add_error_string *prm) {

    args["errorcode"]	= prm->errorcode;
    args["errorstring"]	= std::string(prm->errorstring);

}

extern "C" int cortex_python_translate_MPI_Add_error_string(const dumpi_add_error_string *prm, 
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
		fun = user_python_translator.attr("MPI_Add_error_string");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Add_error_string, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_add_error_string_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_address_to_python(bp::dict& args, const dumpi_address *prm) {

    args["address"]	= prm->address;

}

extern "C" int cortex_python_translate_MPI_Address(const dumpi_address *prm, 
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
		fun = user_python_translator.attr("MPI_Address");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Address, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_address_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_allgather_to_python(bp::dict& args, const dumpi_allgather *prm) {

    args["sendcount"]	= prm->sendcount;
    args["sendtype"]	= prm->sendtype;
    args["recvcount"]	= prm->recvcount;
    args["recvtype"]	= prm->recvtype;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Allgather(const dumpi_allgather *prm, 
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
		fun = user_python_translator.attr("MPI_Allgather");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Allgather, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_allgather_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_allgatherv_to_python(bp::dict& args, const dumpi_allgatherv *prm) {

    args["commsize"]	= prm->commsize;
    args["sendcount"]	= prm->sendcount;
    args["sendtype"]	= prm->sendtype;
    args["recvcounts"]	= stl_vector_to_py_list(std::vector<int>(prm->recvcounts,prm->recvcounts+prm->commsize));
    args["displs"]	= stl_vector_to_py_list(std::vector<int>(prm->displs,prm->displs+prm->commsize));
    args["recvtype"]	= prm->recvtype;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Allgatherv(const dumpi_allgatherv *prm, 
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
		fun = user_python_translator.attr("MPI_Allgatherv");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Allgatherv, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_allgatherv_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_alloc_mem_to_python(bp::dict& args, const dumpi_alloc_mem *prm) {

    args["size"]	= prm->size;
    args["info"]	= prm->info;

}

extern "C" int cortex_python_translate_MPI_Alloc_mem(const dumpi_alloc_mem *prm, 
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
		fun = user_python_translator.attr("MPI_Alloc_mem");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Alloc_mem, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_alloc_mem_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_allreduce_to_python(bp::dict& args, const dumpi_allreduce *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["op"]	= prm->op;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Allreduce(const dumpi_allreduce *prm, 
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
		fun = user_python_translator.attr("MPI_Allreduce");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Allreduce, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_allreduce_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_alltoall_to_python(bp::dict& args, const dumpi_alltoall *prm) {

    args["sendcount"]	= prm->sendcount;
    args["sendtype"]	= prm->sendtype;
    args["recvcount"]	= prm->recvcount;
    args["recvtype"]	= prm->recvtype;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Alltoall(const dumpi_alltoall *prm, 
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
		fun = user_python_translator.attr("MPI_Alltoall");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Alltoall, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_alltoall_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_alltoallv_to_python(bp::dict& args, const dumpi_alltoallv *prm) {

    args["commsize"]	= prm->commsize;
    args["sendcounts"]	= stl_vector_to_py_list(std::vector<int>(prm->sendcounts,prm->sendcounts+prm->commsize));
    args["senddispls"]	= stl_vector_to_py_list(std::vector<int>(prm->senddispls,prm->senddispls+prm->commsize));
    args["sendtype"]	= prm->sendtype;
    args["recvcounts"]	= stl_vector_to_py_list(std::vector<int>(prm->recvcounts,prm->recvcounts+prm->commsize));
    args["recvdispls"]	= stl_vector_to_py_list(std::vector<int>(prm->recvdispls,prm->recvdispls+prm->commsize));
    args["recvtype"]	= prm->recvtype;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Alltoallv(const dumpi_alltoallv *prm, 
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
		fun = user_python_translator.attr("MPI_Alltoallv");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Alltoallv, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_alltoallv_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

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
                thread = profile->rank;
		cortex_post(profile, DUMPI_Alltoallw, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_alltoallw_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_attr_delete_to_python(bp::dict& args, const dumpi_attr_delete *prm) {

    args["comm"]	= prm->comm;
    args["key"]	= prm->key;

}

extern "C" int cortex_python_translate_MPI_Attr_delete(const dumpi_attr_delete *prm, 
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
		fun = user_python_translator.attr("MPI_Attr_delete");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Attr_delete, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_attr_delete_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_attr_get_to_python(bp::dict& args, const dumpi_attr_get *prm) {

    args["comm"]	= prm->comm;
    args["key"]	= prm->key;
    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_Attr_get(const dumpi_attr_get *prm, 
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
		fun = user_python_translator.attr("MPI_Attr_get");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Attr_get, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_attr_get_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_attr_put_to_python(bp::dict& args, const dumpi_attr_put *prm) {

    args["comm"]	= prm->comm;
    args["key"]	= prm->key;

}

extern "C" int cortex_python_translate_MPI_Attr_put(const dumpi_attr_put *prm, 
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
		fun = user_python_translator.attr("MPI_Attr_put");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Attr_put, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_attr_put_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_barrier_to_python(bp::dict& args, const dumpi_barrier *prm) {

    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Barrier(const dumpi_barrier *prm, 
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
		fun = user_python_translator.attr("MPI_Barrier");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Barrier, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_barrier_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_bcast_to_python(bp::dict& args, const dumpi_bcast *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["root"]	= prm->root;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Bcast(const dumpi_bcast *prm, 
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
		fun = user_python_translator.attr("MPI_Bcast");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Bcast, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_bcast_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_bsend_to_python(bp::dict& args, const dumpi_bsend *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Bsend(const dumpi_bsend *prm, 
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
		fun = user_python_translator.attr("MPI_Bsend");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Bsend, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_bsend_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_bsend_init_to_python(bp::dict& args, const dumpi_bsend_init *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Bsend_init(const dumpi_bsend_init *prm, 
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
		fun = user_python_translator.attr("MPI_Bsend_init");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Bsend_init, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_bsend_init_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_buffer_attach_to_python(bp::dict& args, const dumpi_buffer_attach *prm) {

    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_Buffer_attach(const dumpi_buffer_attach *prm, 
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
		fun = user_python_translator.attr("MPI_Buffer_attach");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Buffer_attach, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_buffer_attach_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_buffer_detach_to_python(bp::dict& args, const dumpi_buffer_detach *prm) {

    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_Buffer_detach(const dumpi_buffer_detach *prm, 
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
		fun = user_python_translator.attr("MPI_Buffer_detach");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Buffer_detach, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_buffer_detach_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_cancel_to_python(bp::dict& args, const dumpi_cancel *prm) {

    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Cancel(const dumpi_cancel *prm, 
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
		fun = user_python_translator.attr("MPI_Cancel");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Cancel, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_cancel_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_cart_coords_to_python(bp::dict& args, const dumpi_cart_coords *prm) {

    args["ndim"]	= prm->ndim;
    args["comm"]	= prm->comm;
    args["rank"]	= prm->rank;
    args["maxdims"]	= prm->maxdims;
    args["coords"]	= stl_vector_to_py_list(std::vector<int>(prm->coords,prm->coords+prm->ndim));

}

extern "C" int cortex_python_translate_MPI_Cart_coords(const dumpi_cart_coords *prm, 
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
		fun = user_python_translator.attr("MPI_Cart_coords");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Cart_coords, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_cart_coords_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_cart_create_to_python(bp::dict& args, const dumpi_cart_create *prm) {

    args["oldcomm"]	= prm->oldcomm;
    args["ndim"]	= prm->ndim;
    args["dims"]	= stl_vector_to_py_list(std::vector<int>(prm->dims,prm->dims+prm->ndim));
    args["periods"]	= stl_vector_to_py_list(std::vector<int>(prm->periods,prm->periods+prm->ndim));
    args["reorder"]	= prm->reorder;
    args["newcomm"]	= prm->newcomm;

}

extern "C" int cortex_python_translate_MPI_Cart_create(const dumpi_cart_create *prm, 
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
		fun = user_python_translator.attr("MPI_Cart_create");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Cart_create, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_cart_create_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_cartdim_get_to_python(bp::dict& args, const dumpi_cartdim_get *prm) {

    args["comm"]	= prm->comm;
    args["ndim"]	= prm->ndim;

}

extern "C" int cortex_python_translate_MPI_Cartdim_get(const dumpi_cartdim_get *prm, 
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
		fun = user_python_translator.attr("MPI_Cartdim_get");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Cartdim_get, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_cartdim_get_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

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
                thread = profile->rank;
		cortex_post(profile, DUMPI_Cart_get, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_cart_get_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_cart_map_to_python(bp::dict& args, const dumpi_cart_map *prm) {

    args["comm"]	= prm->comm;
    args["ndim"]	= prm->ndim;
    args["dims"]	= stl_vector_to_py_list(std::vector<int>(prm->dims,prm->dims+prm->ndim));
    args["period"]	= stl_vector_to_py_list(std::vector<int>(prm->period,prm->period+prm->ndim));
    args["newrank"]	= prm->newrank;

}

extern "C" int cortex_python_translate_MPI_Cart_map(const dumpi_cart_map *prm, 
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
		fun = user_python_translator.attr("MPI_Cart_map");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Cart_map, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_cart_map_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_cart_rank_to_python(bp::dict& args, const dumpi_cart_rank *prm) {

    args["ndim"]	= prm->ndim;
    args["comm"]	= prm->comm;
    args["coords"]	= stl_vector_to_py_list(std::vector<int>(prm->coords,prm->coords+prm->ndim));
    args["rank"]	= prm->rank;

}

extern "C" int cortex_python_translate_MPI_Cart_rank(const dumpi_cart_rank *prm, 
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
		fun = user_python_translator.attr("MPI_Cart_rank");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Cart_rank, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_cart_rank_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_cart_shift_to_python(bp::dict& args, const dumpi_cart_shift *prm) {

    args["comm"]	= prm->comm;
    args["direction"]	= prm->direction;
    args["displ"]	= prm->displ;
    args["source"]	= prm->source;
    args["dest"]	= prm->dest;

}

extern "C" int cortex_python_translate_MPI_Cart_shift(const dumpi_cart_shift *prm, 
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
		fun = user_python_translator.attr("MPI_Cart_shift");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Cart_shift, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_cart_shift_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_cart_sub_to_python(bp::dict& args, const dumpi_cart_sub *prm) {

    args["ndim"]	= prm->ndim;
    args["oldcomm"]	= prm->oldcomm;
    args["remain_dims"]	= stl_vector_to_py_list(std::vector<int>(prm->remain_dims,prm->remain_dims+prm->ndim));
    args["newcomm"]	= prm->newcomm;

}

extern "C" int cortex_python_translate_MPI_Cart_sub(const dumpi_cart_sub *prm, 
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
		fun = user_python_translator.attr("MPI_Cart_sub");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Cart_sub, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_cart_sub_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_close_port_to_python(bp::dict& args, const dumpi_close_port *prm) {

    args["portname"]	= std::string(prm->portname);

}

extern "C" int cortex_python_translate_MPI_Close_port(const dumpi_close_port *prm, 
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
		fun = user_python_translator.attr("MPI_Close_port");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Close_port, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_close_port_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_accept_to_python(bp::dict& args, const dumpi_comm_accept *prm) {

    args["portname"]	= std::string(prm->portname);
    args["info"]	= prm->info;
    args["root"]	= prm->root;
    args["oldcomm"]	= prm->oldcomm;
    args["newcomm"]	= prm->newcomm;

}

extern "C" int cortex_python_translate_MPI_Comm_accept(const dumpi_comm_accept *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_accept");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_accept, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_accept_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_call_errhandler_to_python(bp::dict& args, const dumpi_comm_call_errhandler *prm) {

    args["comm"]	= prm->comm;
    args["errorcode"]	= prm->errorcode;

}

extern "C" int cortex_python_translate_MPI_Comm_call_errhandler(const dumpi_comm_call_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_call_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_call_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_call_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_compare_to_python(bp::dict& args, const dumpi_comm_compare *prm) {

    args["comm1"]	= prm->comm1;
    args["comm2"]	= prm->comm2;
    args["result"]	= prm->result;

}

extern "C" int cortex_python_translate_MPI_Comm_compare(const dumpi_comm_compare *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_compare");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_compare, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_compare_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_connect_to_python(bp::dict& args, const dumpi_comm_connect *prm) {

    args["portname"]	= std::string(prm->portname);
    args["info"]	= prm->info;
    args["root"]	= prm->root;
    args["oldcomm"]	= prm->oldcomm;
    args["newcomm"]	= prm->newcomm;

}

extern "C" int cortex_python_translate_MPI_Comm_connect(const dumpi_comm_connect *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_connect");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_connect, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_connect_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_create_to_python(bp::dict& args, const dumpi_comm_create *prm) {

    args["oldcomm"]	= prm->oldcomm;
    args["group"]	= prm->group;
    args["newcomm"]	= prm->newcomm;

}

extern "C" int cortex_python_translate_MPI_Comm_create(const dumpi_comm_create *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_create");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_create, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_create_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_create_errhandler_to_python(bp::dict& args, const dumpi_comm_create_errhandler *prm) {

    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_Comm_create_errhandler(const dumpi_comm_create_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_create_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_create_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_create_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_create_keyval_to_python(bp::dict& args, const dumpi_comm_create_keyval *prm) {

    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Comm_create_keyval(const dumpi_comm_create_keyval *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_create_keyval");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_create_keyval, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_create_keyval_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_delete_attr_to_python(bp::dict& args, const dumpi_comm_delete_attr *prm) {

    args["comm"]	= prm->comm;
    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Comm_delete_attr(const dumpi_comm_delete_attr *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_delete_attr");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_delete_attr, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_delete_attr_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_disconnect_to_python(bp::dict& args, const dumpi_comm_disconnect *prm) {

    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Comm_disconnect(const dumpi_comm_disconnect *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_disconnect");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_disconnect, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_disconnect_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_dup_to_python(bp::dict& args, const dumpi_comm_dup *prm) {

    args["oldcomm"]	= prm->oldcomm;
    args["newcomm"]	= prm->newcomm;

}

extern "C" int cortex_python_translate_MPI_Comm_dup(const dumpi_comm_dup *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_dup");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_dup, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_dup_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_free_to_python(bp::dict& args, const dumpi_comm_free *prm) {

    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Comm_free(const dumpi_comm_free *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_free");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_free, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_free_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_free_keyval_to_python(bp::dict& args, const dumpi_comm_free_keyval *prm) {

    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Comm_free_keyval(const dumpi_comm_free_keyval *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_free_keyval");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_free_keyval, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_free_keyval_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_get_attr_to_python(bp::dict& args, const dumpi_comm_get_attr *prm) {

    args["comm"]	= prm->comm;
    args["keyval"]	= prm->keyval;
    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_Comm_get_attr(const dumpi_comm_get_attr *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_get_attr");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_get_attr, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_get_attr_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_get_errhandler_to_python(bp::dict& args, const dumpi_comm_get_errhandler *prm) {

    args["comm"]	= prm->comm;
    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_Comm_get_errhandler(const dumpi_comm_get_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_get_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_get_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_get_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_get_name_to_python(bp::dict& args, const dumpi_comm_get_name *prm) {

    args["comm"]	= prm->comm;
    args["name"]	= std::string(prm->name);
    args["resultlen"]	= prm->resultlen;

}

extern "C" int cortex_python_translate_MPI_Comm_get_name(const dumpi_comm_get_name *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_get_name");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_get_name, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_get_name_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_get_parent_to_python(bp::dict& args, const dumpi_comm_get_parent *prm) {

    args["parent"]	= prm->parent;

}

extern "C" int cortex_python_translate_MPI_Comm_get_parent(const dumpi_comm_get_parent *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_get_parent");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_get_parent, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_get_parent_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_group_to_python(bp::dict& args, const dumpi_comm_group *prm) {

    args["comm"]	= prm->comm;
    args["group"]	= prm->group;

}

extern "C" int cortex_python_translate_MPI_Comm_group(const dumpi_comm_group *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_group");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_group, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_group_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_join_to_python(bp::dict& args, const dumpi_comm_join *prm) {

    args["fd"]	= prm->fd;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Comm_join(const dumpi_comm_join *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_join");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_join, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_join_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_rank_to_python(bp::dict& args, const dumpi_comm_rank *prm) {

    args["comm"]	= prm->comm;
    args["rank"]	= prm->rank;

}

extern "C" int cortex_python_translate_MPI_Comm_rank(const dumpi_comm_rank *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_rank");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_rank, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_rank_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_remote_group_to_python(bp::dict& args, const dumpi_comm_remote_group *prm) {

    args["comm"]	= prm->comm;
    args["group"]	= prm->group;

}

extern "C" int cortex_python_translate_MPI_Comm_remote_group(const dumpi_comm_remote_group *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_remote_group");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_remote_group, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_remote_group_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_remote_size_to_python(bp::dict& args, const dumpi_comm_remote_size *prm) {

    args["comm"]	= prm->comm;
    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_Comm_remote_size(const dumpi_comm_remote_size *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_remote_size");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_remote_size, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_remote_size_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_set_attr_to_python(bp::dict& args, const dumpi_comm_set_attr *prm) {

    args["comm"]	= prm->comm;
    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Comm_set_attr(const dumpi_comm_set_attr *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_set_attr");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_set_attr, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_set_attr_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_set_errhandler_to_python(bp::dict& args, const dumpi_comm_set_errhandler *prm) {

    args["comm"]	= prm->comm;
    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_Comm_set_errhandler(const dumpi_comm_set_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_set_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_set_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_set_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_set_name_to_python(bp::dict& args, const dumpi_comm_set_name *prm) {

    args["comm"]	= prm->comm;
    args["name"]	= std::string(prm->name);

}

extern "C" int cortex_python_translate_MPI_Comm_set_name(const dumpi_comm_set_name *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_set_name");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_set_name, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_set_name_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_size_to_python(bp::dict& args, const dumpi_comm_size *prm) {

    args["comm"]	= prm->comm;
    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_Comm_size(const dumpi_comm_size *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_size");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_size, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_size_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_spawn_to_python(bp::dict& args, const dumpi_comm_spawn *prm) {

    args["oldcommrank"]	= prm->oldcommrank;
    args["command"]	= std::string(prm->command);
    int i=0;
    bp::list l;
    while(prm->argv[i] != NULL) {;      l.append(std::string(prm->argv[i]));
    }
    args["argv"]	= l;
    args["maxprocs"]	= prm->maxprocs;
    args["info"]	= prm->info;
    args["root"]	= prm->root;
    args["oldcomm"]	= prm->oldcomm;
    args["newcomm"]	= prm->newcomm;
    args["errcodes"]	= stl_vector_to_py_list(std::vector<int>(prm->errcodes,prm->errcodes+prm->maxprocs));

}

extern "C" int cortex_python_translate_MPI_Comm_spawn(const dumpi_comm_spawn *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_spawn");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_spawn, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_spawn_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_spawn_multiple_to_python(bp::dict& args, const dumpi_comm_spawn_multiple *prm) {

    args["totprocs"]	= prm->totprocs;
    args["oldcommrank"]	= prm->oldcommrank;
    args["count"]	= prm->count;
     { bp::list l; for(int i=0; i < prm->count; i++) l.append(std::string(prm->commands[i]));
     args["commands"]	= l; }
    {
	bp::list l;
	for(int i=0; i < prm->count; i++) {
		bp::list l2;
		int j = 0;
		while(prm->argvs[i][j] != NULL) {;			l2.append(std::string(prm->argvs[i][j]));
			j++;
		}
		l.append(l2);
	}
	args["argvs"] 	= l;
    }

    args["maxprocs"]	= stl_vector_to_py_list(std::vector<int>(prm->maxprocs,prm->maxprocs+prm->count));
    args["info"]	= stl_vector_to_py_list(std::vector<dumpi_info>(prm->info,prm->info+prm->count));
    args["root"]	= prm->root;
    args["oldcomm"]	= prm->oldcomm;
    args["newcomm"]	= prm->newcomm;
    { int x = 0;
      for(int i=0; i<prm->count; i++) {
	x += prm->maxprocs[i];
      }
      args["errcodes"] 	= stl_vector_to_py_list(std::vector<int>(prm->errcodes,prm->errcodes+x));
    }

}

extern "C" int cortex_python_translate_MPI_Comm_spawn_multiple(const dumpi_comm_spawn_multiple *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_spawn_multiple");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_spawn_multiple, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_spawn_multiple_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_split_to_python(bp::dict& args, const dumpi_comm_split *prm) {

    args["oldcomm"]	= prm->oldcomm;
    args["color"]	= prm->color;
    args["key"]	= prm->key;
    args["newcomm"]	= prm->newcomm;

}

extern "C" int cortex_python_translate_MPI_Comm_split(const dumpi_comm_split *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_split");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_split, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_split_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_comm_test_inter_to_python(bp::dict& args, const dumpi_comm_test_inter *prm) {

    args["comm"]	= prm->comm;
    args["inter"]	= prm->inter;

}

extern "C" int cortex_python_translate_MPI_Comm_test_inter(const dumpi_comm_test_inter *prm, 
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
		fun = user_python_translator.attr("MPI_Comm_test_inter");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Comm_test_inter, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_comm_test_inter_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_dims_create_to_python(bp::dict& args, const dumpi_dims_create *prm) {

    args["nodes"]	= prm->nodes;
    args["ndim"]	= prm->ndim;
      bp::dict dims;
      dims["in"] = stl_vector_to_py_list(std::vector<int>(prm->dims.in,prm->dims.in+prm->ndim));
      dims["out"] = stl_vector_to_py_list(std::vector<int>(prm->dims.out,prm->dims.out+prm->ndim));
    args["dims"] = dims;
}

extern "C" int cortex_python_translate_MPI_Dims_create(const dumpi_dims_create *prm, 
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
		fun = user_python_translator.attr("MPI_Dims_create");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Dims_create, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_dims_create_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_errhandler_create_to_python(bp::dict& args, const dumpi_errhandler_create *prm) {

    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_Errhandler_create(const dumpi_errhandler_create *prm, 
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
		fun = user_python_translator.attr("MPI_Errhandler_create");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Errhandler_create, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_errhandler_create_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_errhandler_free_to_python(bp::dict& args, const dumpi_errhandler_free *prm) {

    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_Errhandler_free(const dumpi_errhandler_free *prm, 
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
		fun = user_python_translator.attr("MPI_Errhandler_free");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Errhandler_free, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_errhandler_free_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_errhandler_get_to_python(bp::dict& args, const dumpi_errhandler_get *prm) {

    args["comm"]	= prm->comm;
    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_Errhandler_get(const dumpi_errhandler_get *prm, 
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
		fun = user_python_translator.attr("MPI_Errhandler_get");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Errhandler_get, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_errhandler_get_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_errhandler_set_to_python(bp::dict& args, const dumpi_errhandler_set *prm) {

    args["comm"]	= prm->comm;
    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_Errhandler_set(const dumpi_errhandler_set *prm, 
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
		fun = user_python_translator.attr("MPI_Errhandler_set");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Errhandler_set, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_errhandler_set_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_error_class_to_python(bp::dict& args, const dumpi_error_class *prm) {

    args["errorcode"]	= prm->errorcode;
    args["errorclass"]	= prm->errorclass;

}

extern "C" int cortex_python_translate_MPI_Error_class(const dumpi_error_class *prm, 
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
		fun = user_python_translator.attr("MPI_Error_class");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Error_class, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_error_class_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_error_string_to_python(bp::dict& args, const dumpi_error_string *prm) {

    args["errorcode"]	= prm->errorcode;
    args["errorstring"]	= std::string(prm->errorstring);
    args["resultlen"]	= prm->resultlen;

}

extern "C" int cortex_python_translate_MPI_Error_string(const dumpi_error_string *prm, 
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
		fun = user_python_translator.attr("MPI_Error_string");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Error_string, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_error_string_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_exscan_to_python(bp::dict& args, const dumpi_exscan *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["op"]	= prm->op;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Exscan(const dumpi_exscan *prm, 
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
		fun = user_python_translator.attr("MPI_Exscan");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Exscan, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_exscan_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_call_errhandler_to_python(bp::dict& args, const dumpi_file_call_errhandler *prm) {

    args["file"]	= prm->file;
    args["errorcode"]	= prm->errorcode;

}

extern "C" int cortex_python_translate_MPI_File_call_errhandler(const dumpi_file_call_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_File_call_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_call_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_call_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_close_to_python(bp::dict& args, const dumpi_file_close *prm) {

    args["file"]	= prm->file;

}

extern "C" int cortex_python_translate_MPI_File_close(const dumpi_file_close *prm, 
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
		fun = user_python_translator.attr("MPI_File_close");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_close, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_close_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_create_errhandler_to_python(bp::dict& args, const dumpi_file_create_errhandler *prm) {

    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_File_create_errhandler(const dumpi_file_create_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_File_create_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_create_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_create_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_delete_to_python(bp::dict& args, const dumpi_file_delete *prm) {

    args["filename"]	= std::string(prm->filename);
    args["info"]	= prm->info;

}

extern "C" int cortex_python_translate_MPI_File_delete(const dumpi_file_delete *prm, 
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
		fun = user_python_translator.attr("MPI_File_delete");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_delete, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_delete_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_amode_to_python(bp::dict& args, const dumpi_file_get_amode *prm) {

    args["file"]	= prm->file;
    args["amode"]	= prm->amode;

}

extern "C" int cortex_python_translate_MPI_File_get_amode(const dumpi_file_get_amode *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_amode");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_amode, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_amode_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_atomicity_to_python(bp::dict& args, const dumpi_file_get_atomicity *prm) {

    args["file"]	= prm->file;
    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_File_get_atomicity(const dumpi_file_get_atomicity *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_atomicity");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_atomicity, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_atomicity_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_byte_offset_to_python(bp::dict& args, const dumpi_file_get_byte_offset *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["bytes"]	= prm->bytes;

}

extern "C" int cortex_python_translate_MPI_File_get_byte_offset(const dumpi_file_get_byte_offset *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_byte_offset");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_byte_offset, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_byte_offset_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_errhandler_to_python(bp::dict& args, const dumpi_file_get_errhandler *prm) {

    args["file"]	= prm->file;
    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_File_get_errhandler(const dumpi_file_get_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_group_to_python(bp::dict& args, const dumpi_file_get_group *prm) {

    args["file"]	= prm->file;
    args["group"]	= prm->group;

}

extern "C" int cortex_python_translate_MPI_File_get_group(const dumpi_file_get_group *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_group");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_group, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_group_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_info_to_python(bp::dict& args, const dumpi_file_get_info *prm) {

    args["file"]	= prm->file;
    args["info"]	= prm->info;

}

extern "C" int cortex_python_translate_MPI_File_get_info(const dumpi_file_get_info *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_info");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_info, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_info_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_position_to_python(bp::dict& args, const dumpi_file_get_position *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;

}

extern "C" int cortex_python_translate_MPI_File_get_position(const dumpi_file_get_position *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_position");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_position, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_position_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_position_shared_to_python(bp::dict& args, const dumpi_file_get_position_shared *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;

}

extern "C" int cortex_python_translate_MPI_File_get_position_shared(const dumpi_file_get_position_shared *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_position_shared");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_position_shared, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_position_shared_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_size_to_python(bp::dict& args, const dumpi_file_get_size *prm) {

    args["file"]	= prm->file;
    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_File_get_size(const dumpi_file_get_size *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_size");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_size, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_size_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_type_extent_to_python(bp::dict& args, const dumpi_file_get_type_extent *prm) {

    args["file"]	= prm->file;
    args["datatype"]	= prm->datatype;
    args["extent"]	= prm->extent;

}

extern "C" int cortex_python_translate_MPI_File_get_type_extent(const dumpi_file_get_type_extent *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_type_extent");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_type_extent, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_type_extent_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_get_view_to_python(bp::dict& args, const dumpi_file_get_view *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["hosttype"]	= prm->hosttype;
    args["filetype"]	= prm->filetype;
    args["datarep"]	= std::string(prm->datarep);

}

extern "C" int cortex_python_translate_MPI_File_get_view(const dumpi_file_get_view *prm, 
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
		fun = user_python_translator.attr("MPI_File_get_view");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_get_view, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_get_view_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_iread_at_to_python(bp::dict& args, const dumpi_file_iread_at *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_File_iread_at(const dumpi_file_iread_at *prm, 
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
		fun = user_python_translator.attr("MPI_File_iread_at");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_iread_at, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_iread_at_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_iread_to_python(bp::dict& args, const dumpi_file_iread *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_File_iread(const dumpi_file_iread *prm, 
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
		fun = user_python_translator.attr("MPI_File_iread");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_iread, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_iread_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_iread_shared_to_python(bp::dict& args, const dumpi_file_iread_shared *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_File_iread_shared(const dumpi_file_iread_shared *prm, 
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
		fun = user_python_translator.attr("MPI_File_iread_shared");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_iread_shared, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_iread_shared_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_iwrite_at_to_python(bp::dict& args, const dumpi_file_iwrite_at *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_File_iwrite_at(const dumpi_file_iwrite_at *prm, 
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
		fun = user_python_translator.attr("MPI_File_iwrite_at");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_iwrite_at, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_iwrite_at_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_iwrite_to_python(bp::dict& args, const dumpi_file_iwrite *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_File_iwrite(const dumpi_file_iwrite *prm, 
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
		fun = user_python_translator.attr("MPI_File_iwrite");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_iwrite, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_iwrite_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_iwrite_shared_to_python(bp::dict& args, const dumpi_file_iwrite_shared *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_File_iwrite_shared(const dumpi_file_iwrite_shared *prm, 
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
		fun = user_python_translator.attr("MPI_File_iwrite_shared");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_iwrite_shared, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_iwrite_shared_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_open_to_python(bp::dict& args, const dumpi_file_open *prm) {

    args["comm"]	= prm->comm;
    args["filename"]	= std::string(prm->filename);
    args["amode"]	= prm->amode;
    args["info"]	= prm->info;
    args["file"]	= prm->file;

}

extern "C" int cortex_python_translate_MPI_File_open(const dumpi_file_open *prm, 
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
		fun = user_python_translator.attr("MPI_File_open");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_open, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_open_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_preallocate_to_python(bp::dict& args, const dumpi_file_preallocate *prm) {

    args["file"]	= prm->file;
    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_File_preallocate(const dumpi_file_preallocate *prm, 
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
		fun = user_python_translator.attr("MPI_File_preallocate");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_preallocate, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_preallocate_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_all_begin_to_python(bp::dict& args, const dumpi_file_read_all_begin *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;

}

extern "C" int cortex_python_translate_MPI_File_read_all_begin(const dumpi_file_read_all_begin *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_all_begin");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_all_begin, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_all_begin_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_all_to_python(bp::dict& args, const dumpi_file_read_all *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_read_all(const dumpi_file_read_all *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_all");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_all, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_all_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_all_end_to_python(bp::dict& args, const dumpi_file_read_all_end *prm) {

    args["file"]	= prm->file;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_read_all_end(const dumpi_file_read_all_end *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_all_end");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_all_end, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_all_end_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_at_all_begin_to_python(bp::dict& args, const dumpi_file_read_at_all_begin *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;

}

extern "C" int cortex_python_translate_MPI_File_read_at_all_begin(const dumpi_file_read_at_all_begin *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_at_all_begin");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_at_all_begin, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_at_all_begin_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_at_all_to_python(bp::dict& args, const dumpi_file_read_at_all *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_read_at_all(const dumpi_file_read_at_all *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_at_all");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_at_all, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_at_all_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_at_all_end_to_python(bp::dict& args, const dumpi_file_read_at_all_end *prm) {

    args["file"]	= prm->file;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_read_at_all_end(const dumpi_file_read_at_all_end *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_at_all_end");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_at_all_end, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_at_all_end_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_at_to_python(bp::dict& args, const dumpi_file_read_at *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_read_at(const dumpi_file_read_at *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_at");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_at, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_at_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_to_python(bp::dict& args, const dumpi_file_read *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_read(const dumpi_file_read *prm, 
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
		fun = user_python_translator.attr("MPI_File_read");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_ordered_begin_to_python(bp::dict& args, const dumpi_file_read_ordered_begin *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;

}

extern "C" int cortex_python_translate_MPI_File_read_ordered_begin(const dumpi_file_read_ordered_begin *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_ordered_begin");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_ordered_begin, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_ordered_begin_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_ordered_to_python(bp::dict& args, const dumpi_file_read_ordered *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_read_ordered(const dumpi_file_read_ordered *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_ordered");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_ordered, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_ordered_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_ordered_end_to_python(bp::dict& args, const dumpi_file_read_ordered_end *prm) {

    args["file"]	= prm->file;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_read_ordered_end(const dumpi_file_read_ordered_end *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_ordered_end");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_ordered_end, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_ordered_end_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_read_shared_to_python(bp::dict& args, const dumpi_file_read_shared *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_read_shared(const dumpi_file_read_shared *prm, 
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
		fun = user_python_translator.attr("MPI_File_read_shared");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_read_shared, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_read_shared_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_seek_to_python(bp::dict& args, const dumpi_file_seek *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["whence"]	= prm->whence;

}

extern "C" int cortex_python_translate_MPI_File_seek(const dumpi_file_seek *prm, 
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
		fun = user_python_translator.attr("MPI_File_seek");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_seek, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_seek_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_seek_shared_to_python(bp::dict& args, const dumpi_file_seek_shared *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["whence"]	= prm->whence;

}

extern "C" int cortex_python_translate_MPI_File_seek_shared(const dumpi_file_seek_shared *prm, 
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
		fun = user_python_translator.attr("MPI_File_seek_shared");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_seek_shared, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_seek_shared_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_set_atomicity_to_python(bp::dict& args, const dumpi_file_set_atomicity *prm) {

    args["file"]	= prm->file;
    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_File_set_atomicity(const dumpi_file_set_atomicity *prm, 
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
		fun = user_python_translator.attr("MPI_File_set_atomicity");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_set_atomicity, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_set_atomicity_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_set_errhandler_to_python(bp::dict& args, const dumpi_file_set_errhandler *prm) {

    args["file"]	= prm->file;
    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_File_set_errhandler(const dumpi_file_set_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_File_set_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_set_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_set_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_set_info_to_python(bp::dict& args, const dumpi_file_set_info *prm) {

    args["file"]	= prm->file;
    args["info"]	= prm->info;

}

extern "C" int cortex_python_translate_MPI_File_set_info(const dumpi_file_set_info *prm, 
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
		fun = user_python_translator.attr("MPI_File_set_info");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_set_info, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_set_info_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

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

static void dumpi_file_set_view_to_python(bp::dict& args, const dumpi_file_set_view *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["hosttype"]	= prm->hosttype;
    args["filetype"]	= prm->filetype;
    args["datarep"]	= std::string(prm->datarep);
    args["info"]	= prm->info;

}

extern "C" int cortex_python_translate_MPI_File_set_view(const dumpi_file_set_view *prm, 
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
		fun = user_python_translator.attr("MPI_File_set_view");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_set_view, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_set_view_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_sync_to_python(bp::dict& args, const dumpi_file_sync *prm) {

    args["file"]	= prm->file;

}

extern "C" int cortex_python_translate_MPI_File_sync(const dumpi_file_sync *prm, 
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
		fun = user_python_translator.attr("MPI_File_sync");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_sync, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_sync_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_all_begin_to_python(bp::dict& args, const dumpi_file_write_all_begin *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;

}

extern "C" int cortex_python_translate_MPI_File_write_all_begin(const dumpi_file_write_all_begin *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_all_begin");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_all_begin, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_all_begin_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_all_to_python(bp::dict& args, const dumpi_file_write_all *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_write_all(const dumpi_file_write_all *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_all");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_all, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_all_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_all_end_to_python(bp::dict& args, const dumpi_file_write_all_end *prm) {

    args["file"]	= prm->file;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_write_all_end(const dumpi_file_write_all_end *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_all_end");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_all_end, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_all_end_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_at_all_begin_to_python(bp::dict& args, const dumpi_file_write_at_all_begin *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;

}

extern "C" int cortex_python_translate_MPI_File_write_at_all_begin(const dumpi_file_write_at_all_begin *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_at_all_begin");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_at_all_begin, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_at_all_begin_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_at_all_to_python(bp::dict& args, const dumpi_file_write_at_all *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_write_at_all(const dumpi_file_write_at_all *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_at_all");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_at_all, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_at_all_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_at_all_end_to_python(bp::dict& args, const dumpi_file_write_at_all_end *prm) {

    args["file"]	= prm->file;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_write_at_all_end(const dumpi_file_write_at_all_end *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_at_all_end");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_at_all_end, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_at_all_end_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_at_to_python(bp::dict& args, const dumpi_file_write_at *prm) {

    args["file"]	= prm->file;
    args["offset"]	= prm->offset;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_write_at(const dumpi_file_write_at *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_at");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_at, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_at_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_to_python(bp::dict& args, const dumpi_file_write *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_write(const dumpi_file_write *prm, 
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
		fun = user_python_translator.attr("MPI_File_write");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_ordered_begin_to_python(bp::dict& args, const dumpi_file_write_ordered_begin *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;

}

extern "C" int cortex_python_translate_MPI_File_write_ordered_begin(const dumpi_file_write_ordered_begin *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_ordered_begin");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_ordered_begin, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_ordered_begin_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_ordered_to_python(bp::dict& args, const dumpi_file_write_ordered *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_write_ordered(const dumpi_file_write_ordered *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_ordered");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_ordered, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_ordered_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_ordered_end_to_python(bp::dict& args, const dumpi_file_write_ordered_end *prm) {

    args["file"]	= prm->file;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_write_ordered_end(const dumpi_file_write_ordered_end *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_ordered_end");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_ordered_end, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_ordered_end_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_file_write_shared_to_python(bp::dict& args, const dumpi_file_write_shared *prm) {

    args["file"]	= prm->file;
    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_File_write_shared(const dumpi_file_write_shared *prm, 
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
		fun = user_python_translator.attr("MPI_File_write_shared");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_File_write_shared, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_file_write_shared_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_finalize_to_python(bp::dict& args, const dumpi_finalize *prm) {

    args["dummy"]	= prm->dummy;

}

extern "C" int cortex_python_translate_MPI_Finalize(const dumpi_finalize *prm, 
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
		fun = user_python_translator.attr("MPI_Finalize");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Finalize, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_finalize_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_finalized_to_python(bp::dict& args, const dumpi_finalized *prm) {

    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_Finalized(const dumpi_finalized *prm, 
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
		fun = user_python_translator.attr("MPI_Finalized");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Finalized, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_finalized_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_free_mem_to_python(bp::dict& args, const dumpi_free_mem *prm) {

    args["dummy"]	= prm->dummy;

}

extern "C" int cortex_python_translate_MPI_Free_mem(const dumpi_free_mem *prm, 
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
		fun = user_python_translator.attr("MPI_Free_mem");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Free_mem, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_free_mem_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_gather_to_python(bp::dict& args, const dumpi_gather *prm) {

    args["commrank"]	= prm->commrank;
    args["sendcount"]	= prm->sendcount;
    args["sendtype"]	= prm->sendtype;
    args["recvcount"]	= prm->recvcount;
    args["recvtype"]	= prm->recvtype;
    args["root"]	= prm->root;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Gather(const dumpi_gather *prm, 
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
		fun = user_python_translator.attr("MPI_Gather");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Gather, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_gather_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

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
                thread = profile->rank;
		cortex_post(profile, DUMPI_Gatherv, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_gatherv_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_get_address_to_python(bp::dict& args, const dumpi_get_address *prm) {

    args["address"]	= prm->address;

}

extern "C" int cortex_python_translate_MPI_Get_address(const dumpi_get_address *prm, 
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
		fun = user_python_translator.attr("MPI_Get_address");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Get_address, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_get_address_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_get_count_to_python(bp::dict& args, const dumpi_get_count *prm) {

    args["status"]	= *(prm->status);
    args["datatype"]	= prm->datatype;
    args["count"]	= prm->count;

}

extern "C" int cortex_python_translate_MPI_Get_count(const dumpi_get_count *prm, 
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
		fun = user_python_translator.attr("MPI_Get_count");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Get_count, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_get_count_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_get_to_python(bp::dict& args, const dumpi_get *prm) {

    args["origincount"]	= prm->origincount;
    args["origintype"]	= prm->origintype;
    args["targetrank"]	= prm->targetrank;
    args["targetdisp"]	= prm->targetdisp;
    args["targetcount"]	= prm->targetcount;
    args["targettype"]	= prm->targettype;
    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Get(const dumpi_get *prm, 
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
		fun = user_python_translator.attr("MPI_Get");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Get, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_get_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_get_elements_to_python(bp::dict& args, const dumpi_get_elements *prm) {

    args["status"]	= *(prm->status);
    args["datatype"]	= prm->datatype;
    args["elements"]	= prm->elements;

}

extern "C" int cortex_python_translate_MPI_Get_elements(const dumpi_get_elements *prm, 
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
		fun = user_python_translator.attr("MPI_Get_elements");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Get_elements, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_get_elements_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_get_processor_name_to_python(bp::dict& args, const dumpi_get_processor_name *prm) {

    args["name"]	= std::string(prm->name);
    args["resultlen"]	= prm->resultlen;

}

extern "C" int cortex_python_translate_MPI_Get_processor_name(const dumpi_get_processor_name *prm, 
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
		fun = user_python_translator.attr("MPI_Get_processor_name");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Get_processor_name, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_get_processor_name_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_get_version_to_python(bp::dict& args, const dumpi_get_version *prm) {

    args["version"]	= prm->version;
    args["subversion"]	= prm->subversion;

}

extern "C" int cortex_python_translate_MPI_Get_version(const dumpi_get_version *prm, 
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
		fun = user_python_translator.attr("MPI_Get_version");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Get_version, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_get_version_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_graph_create_to_python(bp::dict& args, const dumpi_graph_create *prm) {

    args["numedges"]	= prm->numedges;
    args["oldcomm"]	= prm->oldcomm;
    args["nodes"]	= prm->nodes;
    args["index"]	= stl_vector_to_py_list(std::vector<int>(prm->index,prm->index+prm->nodes));
    args["edges"]	= stl_vector_to_py_list(std::vector<int>(prm->edges,prm->edges+prm->numedges));
    args["reorder"]	= prm->reorder;
    args["newcomm"]	= prm->newcomm;

}

extern "C" int cortex_python_translate_MPI_Graph_create(const dumpi_graph_create *prm, 
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
		fun = user_python_translator.attr("MPI_Graph_create");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Graph_create, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_graph_create_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_graphdims_get_to_python(bp::dict& args, const dumpi_graphdims_get *prm) {

    args["comm"]	= prm->comm;
    args["nodes"]	= prm->nodes;
    args["edges"]	= prm->edges;

}

extern "C" int cortex_python_translate_MPI_Graphdims_get(const dumpi_graphdims_get *prm, 
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
		fun = user_python_translator.attr("MPI_Graphdims_get");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Graphdims_get, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_graphdims_get_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_graph_get_to_python(bp::dict& args, const dumpi_graph_get *prm) {

    args["totedges"]	= prm->totedges;
    args["totnodes"]	= prm->totnodes;
    args["comm"]	= prm->comm;
    args["maxindex"]	= prm->maxindex;
    args["maxedges"]	= prm->maxedges;
    args["index"]	= stl_vector_to_py_list(std::vector<int>(prm->index,prm->index+prm->totnodes));
    args["edges"]	= stl_vector_to_py_list(std::vector<int>(prm->edges,prm->edges+prm->totedges));

}

extern "C" int cortex_python_translate_MPI_Graph_get(const dumpi_graph_get *prm, 
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
		fun = user_python_translator.attr("MPI_Graph_get");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Graph_get, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_graph_get_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_graph_map_to_python(bp::dict& args, const dumpi_graph_map *prm) {

    args["numedges"]	= prm->numedges;
    args["comm"]	= prm->comm;
    args["nodes"]	= prm->nodes;
    args["index"]	= stl_vector_to_py_list(std::vector<int>(prm->index,prm->index+prm->nodes));
    args["edges"]	= stl_vector_to_py_list(std::vector<int>(prm->edges,prm->edges+prm->numedges));
    args["newrank"]	= prm->newrank;

}

extern "C" int cortex_python_translate_MPI_Graph_map(const dumpi_graph_map *prm, 
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
		fun = user_python_translator.attr("MPI_Graph_map");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Graph_map, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_graph_map_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_graph_neighbors_count_to_python(bp::dict& args, const dumpi_graph_neighbors_count *prm) {

    args["comm"]	= prm->comm;
    args["rank"]	= prm->rank;
    args["nneigh"]	= prm->nneigh;

}

extern "C" int cortex_python_translate_MPI_Graph_neighbors_count(const dumpi_graph_neighbors_count *prm, 
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
		fun = user_python_translator.attr("MPI_Graph_neighbors_count");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Graph_neighbors_count, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_graph_neighbors_count_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_graph_neighbors_to_python(bp::dict& args, const dumpi_graph_neighbors *prm) {

    args["nneigh"]	= prm->nneigh;
    args["comm"]	= prm->comm;
    args["rank"]	= prm->rank;
    args["maxneighbors"]	= prm->maxneighbors;
    args["neighbors"]	= stl_vector_to_py_list(std::vector<int>(prm->neighbors,prm->neighbors+prm->nneigh));

}

extern "C" int cortex_python_translate_MPI_Graph_neighbors(const dumpi_graph_neighbors *prm, 
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
		fun = user_python_translator.attr("MPI_Graph_neighbors");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Graph_neighbors, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_graph_neighbors_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_grequest_complete_to_python(bp::dict& args, const dumpi_grequest_complete *prm) {

    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Grequest_complete(const dumpi_grequest_complete *prm, 
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
		fun = user_python_translator.attr("MPI_Grequest_complete");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Grequest_complete, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_grequest_complete_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_grequest_start_to_python(bp::dict& args, const dumpi_grequest_start *prm) {

    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Grequest_start(const dumpi_grequest_start *prm, 
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
		fun = user_python_translator.attr("MPI_Grequest_start");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Grequest_start, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_grequest_start_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_compare_to_python(bp::dict& args, const dumpi_group_compare *prm) {

    args["group1"]	= prm->group1;
    args["group2"]	= prm->group2;
    args["result"]	= prm->result;

}

extern "C" int cortex_python_translate_MPI_Group_compare(const dumpi_group_compare *prm, 
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
		fun = user_python_translator.attr("MPI_Group_compare");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_compare, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_compare_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_difference_to_python(bp::dict& args, const dumpi_group_difference *prm) {

    args["group1"]	= prm->group1;
    args["group2"]	= prm->group2;
    args["newgroup"]	= prm->newgroup;

}

extern "C" int cortex_python_translate_MPI_Group_difference(const dumpi_group_difference *prm, 
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
		fun = user_python_translator.attr("MPI_Group_difference");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_difference, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_difference_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_excl_to_python(bp::dict& args, const dumpi_group_excl *prm) {

    args["group"]	= prm->group;
    args["count"]	= prm->count;
    args["ranks"]	= stl_vector_to_py_list(std::vector<int>(prm->ranks,prm->ranks+prm->count));
    args["newgroup"]	= prm->newgroup;

}

extern "C" int cortex_python_translate_MPI_Group_excl(const dumpi_group_excl *prm, 
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
		fun = user_python_translator.attr("MPI_Group_excl");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_excl, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_excl_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_free_to_python(bp::dict& args, const dumpi_group_free *prm) {

    args["group"]	= prm->group;

}

extern "C" int cortex_python_translate_MPI_Group_free(const dumpi_group_free *prm, 
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
		fun = user_python_translator.attr("MPI_Group_free");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_free, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_free_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_incl_to_python(bp::dict& args, const dumpi_group_incl *prm) {

    args["group"]	= prm->group;
    args["count"]	= prm->count;
    args["ranks"]	= stl_vector_to_py_list(std::vector<int>(prm->ranks,prm->ranks+prm->count));
    args["newgroup"]	= prm->newgroup;

}

extern "C" int cortex_python_translate_MPI_Group_incl(const dumpi_group_incl *prm, 
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
		fun = user_python_translator.attr("MPI_Group_incl");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_incl, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_incl_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_intersection_to_python(bp::dict& args, const dumpi_group_intersection *prm) {

    args["group1"]	= prm->group1;
    args["group2"]	= prm->group2;
    args["newgroup"]	= prm->newgroup;

}

extern "C" int cortex_python_translate_MPI_Group_intersection(const dumpi_group_intersection *prm, 
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
		fun = user_python_translator.attr("MPI_Group_intersection");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_intersection, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_intersection_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_range_excl_to_python(bp::dict& args, const dumpi_group_range_excl *prm) {

    args["group"]	= prm->group;
    args["count"]	= prm->count;
    bp::list l;
    for(int i=0; i<prm->count; i++) {
	l.append(bp::make_tuple(prm->ranges[i][0],prm->ranges[i][1],prm->ranges[i][2]));
    }
    args["ranges"]	= l;
    args["newgroup"]	= prm->newgroup;

}

extern "C" int cortex_python_translate_MPI_Group_range_excl(const dumpi_group_range_excl *prm, 
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
		fun = user_python_translator.attr("MPI_Group_range_excl");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_range_excl, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_range_excl_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_range_incl_to_python(bp::dict& args, const dumpi_group_range_incl *prm) {

    args["group"]	= prm->group;
    args["count"]	= prm->count;
    bp::list l;
    for(int i = 0; i< prm->count; i++) {
	l.append(bp::make_tuple(prm->ranges[i][0],prm->ranges[i][1],prm->ranges[i][2]));
    }
    args["ranges"] 	= l;
    args["newgroup"]	= prm->newgroup;

}

extern "C" int cortex_python_translate_MPI_Group_range_incl(const dumpi_group_range_incl *prm, 
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
		fun = user_python_translator.attr("MPI_Group_range_incl");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_range_incl, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_range_incl_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_rank_to_python(bp::dict& args, const dumpi_group_rank *prm) {

    args["group"]	= prm->group;
    args["rank"]	= prm->rank;

}

extern "C" int cortex_python_translate_MPI_Group_rank(const dumpi_group_rank *prm, 
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
		fun = user_python_translator.attr("MPI_Group_rank");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_rank, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_rank_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_size_to_python(bp::dict& args, const dumpi_group_size *prm) {

    args["group"]	= prm->group;
    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_Group_size(const dumpi_group_size *prm, 
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
		fun = user_python_translator.attr("MPI_Group_size");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_size, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_size_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_translate_ranks_to_python(bp::dict& args, const dumpi_group_translate_ranks *prm) {

    args["group1"]	= prm->group1;
    args["count"]	= prm->count;
    args["ranks1"]	= stl_vector_to_py_list(std::vector<int>(prm->ranks1,prm->ranks1+prm->count));
    args["group2"]	= prm->group2;
    args["ranks2"]	= stl_vector_to_py_list(std::vector<int>(prm->ranks2,prm->ranks2+prm->count));

}

extern "C" int cortex_python_translate_MPI_Group_translate_ranks(const dumpi_group_translate_ranks *prm, 
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
		fun = user_python_translator.attr("MPI_Group_translate_ranks");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_translate_ranks, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_translate_ranks_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_group_union_to_python(bp::dict& args, const dumpi_group_union *prm) {

    args["group1"]	= prm->group1;
    args["group2"]	= prm->group2;
    args["newgroup"]	= prm->newgroup;

}

extern "C" int cortex_python_translate_MPI_Group_union(const dumpi_group_union *prm, 
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
		fun = user_python_translator.attr("MPI_Group_union");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Group_union, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_group_union_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_ibsend_to_python(bp::dict& args, const dumpi_ibsend *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Ibsend(const dumpi_ibsend *prm, 
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
		fun = user_python_translator.attr("MPI_Ibsend");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Ibsend, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_ibsend_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_info_create_to_python(bp::dict& args, const dumpi_info_create *prm) {

    args["info"]	= prm->info;

}

extern "C" int cortex_python_translate_MPI_Info_create(const dumpi_info_create *prm, 
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
		fun = user_python_translator.attr("MPI_Info_create");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Info_create, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_info_create_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_info_delete_to_python(bp::dict& args, const dumpi_info_delete *prm) {

    args["info"]	= prm->info;
    args["key"]	= std::string(prm->key);

}

extern "C" int cortex_python_translate_MPI_Info_delete(const dumpi_info_delete *prm, 
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
		fun = user_python_translator.attr("MPI_Info_delete");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Info_delete, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_info_delete_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_info_dup_to_python(bp::dict& args, const dumpi_info_dup *prm) {

    args["oldinfo"]	= prm->oldinfo;
    args["newinfo"]	= prm->newinfo;

}

extern "C" int cortex_python_translate_MPI_Info_dup(const dumpi_info_dup *prm, 
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
		fun = user_python_translator.attr("MPI_Info_dup");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Info_dup, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_info_dup_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_info_free_to_python(bp::dict& args, const dumpi_info_free *prm) {

    args["info"]	= prm->info;

}

extern "C" int cortex_python_translate_MPI_Info_free(const dumpi_info_free *prm, 
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
		fun = user_python_translator.attr("MPI_Info_free");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Info_free, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_info_free_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_info_get_to_python(bp::dict& args, const dumpi_info_get *prm) {

    args["info"]	= prm->info;
    args["key"]	= std::string(prm->key);
    args["valuelength"]	= prm->valuelength;
    args["value"]	= std::string(prm->value);
    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_Info_get(const dumpi_info_get *prm, 
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
		fun = user_python_translator.attr("MPI_Info_get");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Info_get, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_info_get_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_info_get_nkeys_to_python(bp::dict& args, const dumpi_info_get_nkeys *prm) {

    args["info"]	= prm->info;
    args["nkeys"]	= prm->nkeys;

}

extern "C" int cortex_python_translate_MPI_Info_get_nkeys(const dumpi_info_get_nkeys *prm, 
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
		fun = user_python_translator.attr("MPI_Info_get_nkeys");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Info_get_nkeys, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_info_get_nkeys_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_info_get_nthkey_to_python(bp::dict& args, const dumpi_info_get_nthkey *prm) {

    args["info"]	= prm->info;
    args["n"]	= prm->n;
    args["key"]	= std::string(prm->key);

}

extern "C" int cortex_python_translate_MPI_Info_get_nthkey(const dumpi_info_get_nthkey *prm, 
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
		fun = user_python_translator.attr("MPI_Info_get_nthkey");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Info_get_nthkey, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_info_get_nthkey_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_info_get_valuelen_to_python(bp::dict& args, const dumpi_info_get_valuelen *prm) {

    args["info"]	= prm->info;
    args["key"]	= std::string(prm->key);
    args["valuelen"]	= prm->valuelen;
    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_Info_get_valuelen(const dumpi_info_get_valuelen *prm, 
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
		fun = user_python_translator.attr("MPI_Info_get_valuelen");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Info_get_valuelen, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_info_get_valuelen_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_info_set_to_python(bp::dict& args, const dumpi_info_set *prm) {

    args["info"]	= prm->info;
    args["key"]	= std::string(prm->key);
    args["value"]	= std::string(prm->value);

}

extern "C" int cortex_python_translate_MPI_Info_set(const dumpi_info_set *prm, 
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
		fun = user_python_translator.attr("MPI_Info_set");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Info_set, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_info_set_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_init_to_python(bp::dict& args, const dumpi_init *prm) {

    args["argc"]	= prm->argc;
     { bp::list l; for(int i=0; i < prm->argc; i++) l.append(std::string(prm->argv[i]));
     args["argv"]	= l; }

}

extern "C" int cortex_python_translate_MPI_Init(const dumpi_init *prm, 
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
		fun = user_python_translator.attr("MPI_Init");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Init, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_init_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_initialized_to_python(bp::dict& args, const dumpi_initialized *prm) {

    args["result"]	= prm->result;

}

extern "C" int cortex_python_translate_MPI_Initialized(const dumpi_initialized *prm, 
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
		fun = user_python_translator.attr("MPI_Initialized");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Initialized, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_initialized_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_init_thread_to_python(bp::dict& args, const dumpi_init_thread *prm) {

    args["argc"]	= prm->argc;
     { bp::list l; for(int i=0; i < prm->argc; i++) l.append(std::string(prm->argv[i]));
     args["argv"]	= l; }
    args["required"]	= prm->required;
    args["provided"]	= prm->provided;

}

extern "C" int cortex_python_translate_MPI_Init_thread(const dumpi_init_thread *prm, 
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
		fun = user_python_translator.attr("MPI_Init_thread");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Init_thread, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_init_thread_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_intercomm_create_to_python(bp::dict& args, const dumpi_intercomm_create *prm) {

    args["localcomm"]	= prm->localcomm;
    args["localleader"]	= prm->localleader;
    args["remotecomm"]	= prm->remotecomm;
    args["remoteleader"]	= prm->remoteleader;
    args["tag"]	= prm->tag;
    args["newcomm"]	= prm->newcomm;

}

extern "C" int cortex_python_translate_MPI_Intercomm_create(const dumpi_intercomm_create *prm, 
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
		fun = user_python_translator.attr("MPI_Intercomm_create");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Intercomm_create, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_intercomm_create_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_intercomm_merge_to_python(bp::dict& args, const dumpi_intercomm_merge *prm) {

    args["comm"]	= prm->comm;
    args["high"]	= prm->high;
    args["newcomm"]	= prm->newcomm;

}

extern "C" int cortex_python_translate_MPI_Intercomm_merge(const dumpi_intercomm_merge *prm, 
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
		fun = user_python_translator.attr("MPI_Intercomm_merge");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Intercomm_merge, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_intercomm_merge_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_iprobe_to_python(bp::dict& args, const dumpi_iprobe *prm) {

    args["source"]	= prm->source;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["flag"]	= prm->flag;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_Iprobe(const dumpi_iprobe *prm, 
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
		fun = user_python_translator.attr("MPI_Iprobe");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Iprobe, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_iprobe_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_irecv_to_python(bp::dict& args, const dumpi_irecv *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["source"]	= prm->source;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Irecv(const dumpi_irecv *prm, 
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
		fun = user_python_translator.attr("MPI_Irecv");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Irecv, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_irecv_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_irsend_to_python(bp::dict& args, const dumpi_irsend *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Irsend(const dumpi_irsend *prm, 
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
		fun = user_python_translator.attr("MPI_Irsend");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Irsend, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_irsend_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_isend_to_python(bp::dict& args, const dumpi_isend *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Isend(const dumpi_isend *prm, 
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
		fun = user_python_translator.attr("MPI_Isend");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Isend, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_isend_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_issend_to_python(bp::dict& args, const dumpi_issend *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Issend(const dumpi_issend *prm, 
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
		fun = user_python_translator.attr("MPI_Issend");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Issend, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_issend_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_is_thread_main_to_python(bp::dict& args, const dumpi_is_thread_main *prm) {

    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_Is_thread_main(const dumpi_is_thread_main *prm, 
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
		fun = user_python_translator.attr("MPI_Is_thread_main");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Is_thread_main, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_is_thread_main_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_keyval_create_to_python(bp::dict& args, const dumpi_keyval_create *prm) {

    args["key"]	= prm->key;

}

extern "C" int cortex_python_translate_MPI_Keyval_create(const dumpi_keyval_create *prm, 
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
		fun = user_python_translator.attr("MPI_Keyval_create");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Keyval_create, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_keyval_create_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_keyval_free_to_python(bp::dict& args, const dumpi_keyval_free *prm) {

    args["key"]	= prm->key;

}

extern "C" int cortex_python_translate_MPI_Keyval_free(const dumpi_keyval_free *prm, 
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
		fun = user_python_translator.attr("MPI_Keyval_free");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Keyval_free, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_keyval_free_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_lookup_name_to_python(bp::dict& args, const dumpi_lookup_name *prm) {

    args["servicename"]	= std::string(prm->servicename);
    args["info"]	= prm->info;
    args["portname"]	= std::string(prm->portname);

}

extern "C" int cortex_python_translate_MPI_Lookup_name(const dumpi_lookup_name *prm, 
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
		fun = user_python_translator.attr("MPI_Lookup_name");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Lookup_name, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_lookup_name_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_op_create_to_python(bp::dict& args, const dumpi_op_create *prm) {

    args["commute"]	= prm->commute;
    args["op"]	= prm->op;

}

extern "C" int cortex_python_translate_MPI_Op_create(const dumpi_op_create *prm, 
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
		fun = user_python_translator.attr("MPI_Op_create");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Op_create, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_op_create_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_open_port_to_python(bp::dict& args, const dumpi_open_port *prm) {

    args["info"]	= prm->info;
    args["portname"]	= std::string(prm->portname);

}

extern "C" int cortex_python_translate_MPI_Open_port(const dumpi_open_port *prm, 
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
		fun = user_python_translator.attr("MPI_Open_port");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Open_port, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_open_port_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_op_free_to_python(bp::dict& args, const dumpi_op_free *prm) {

    args["op"]	= prm->op;

}

extern "C" int cortex_python_translate_MPI_Op_free(const dumpi_op_free *prm, 
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
		fun = user_python_translator.attr("MPI_Op_free");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Op_free, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_op_free_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpio_testall_to_python(bp::dict& args, const dumpio_testall *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpio_request>(prm->requests,prm->requests+prm->count));
    args["flag"]	= prm->flag;
    args["statuses"]	= stl_vector_to_py_list(std::vector<dumpi_status>(prm->statuses,prm->statuses+prm->count));

}

extern "C" int cortex_python_translate_MPIO_Testall(const dumpio_testall *prm, 
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
		fun = user_python_translator.attr("MPIO_Testall");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPIO_Testall, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpio_testall_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpio_testany_to_python(bp::dict& args, const dumpio_testany *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpio_request>(prm->requests,prm->requests+prm->count));
    args["index"]	= prm->index;
    args["flag"]	= prm->flag;
    args["statuses"]	= stl_vector_to_py_list(std::vector<dumpi_status>(prm->statuses,prm->statuses+prm->count));

}

extern "C" int cortex_python_translate_MPIO_Testany(const dumpio_testany *prm, 
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
		fun = user_python_translator.attr("MPIO_Testany");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPIO_Testany, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpio_testany_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpio_test_to_python(bp::dict& args, const dumpio_test *prm) {

    args["request"]	= prm->request;
    args["flag"]	= prm->flag;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPIO_Test(const dumpio_test *prm, 
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
		fun = user_python_translator.attr("MPIO_Test");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPIO_Test, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpio_test_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpio_testsome_to_python(bp::dict& args, const dumpio_testsome *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpio_request>(prm->requests,prm->requests+prm->count));
    args["outcount"]	= prm->outcount;
    args["indices"]	= stl_vector_to_py_list(std::vector<int>(prm->indices,prm->indices+prm->outcount));
    args["statuses"]	= stl_vector_to_py_list(std::vector<dumpi_status>(prm->statuses,prm->statuses+prm->outcount));

}

extern "C" int cortex_python_translate_MPIO_Testsome(const dumpio_testsome *prm, 
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
		fun = user_python_translator.attr("MPIO_Testsome");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPIO_Testsome, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpio_testsome_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpio_waitall_to_python(bp::dict& args, const dumpio_waitall *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpio_request>(prm->requests,prm->requests+prm->count));
    args["statuses"]	= stl_vector_to_py_list(std::vector<dumpi_status>(prm->statuses,prm->statuses+prm->count));

}

extern "C" int cortex_python_translate_MPIO_Waitall(const dumpio_waitall *prm, 
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
		fun = user_python_translator.attr("MPIO_Waitall");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPIO_Waitall, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpio_waitall_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpio_waitany_to_python(bp::dict& args, const dumpio_waitany *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpio_request>(prm->requests,prm->requests+prm->count));
    args["index"]	= prm->index;
    args["statuses"]	= stl_vector_to_py_list(std::vector<dumpi_status>(prm->statuses,prm->statuses+prm->count));

}

extern "C" int cortex_python_translate_MPIO_Waitany(const dumpio_waitany *prm, 
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
		fun = user_python_translator.attr("MPIO_Waitany");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPIO_Waitany, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpio_waitany_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpio_wait_to_python(bp::dict& args, const dumpio_wait *prm) {

    args["request"]	= prm->request;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPIO_Wait(const dumpio_wait *prm, 
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
		fun = user_python_translator.attr("MPIO_Wait");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPIO_Wait, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpio_wait_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpio_waitsome_to_python(bp::dict& args, const dumpio_waitsome *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpio_request>(prm->requests,prm->requests+prm->count));
    args["outcount"]	= prm->outcount;
    args["indices"]	= stl_vector_to_py_list(std::vector<int>(prm->indices,prm->indices+prm->outcount));
    args["statuses"]	= stl_vector_to_py_list(std::vector<dumpi_status>(prm->statuses,prm->statuses+prm->outcount));

}

extern "C" int cortex_python_translate_MPIO_Waitsome(const dumpio_waitsome *prm, 
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
		fun = user_python_translator.attr("MPIO_Waitsome");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
		cortex_post(profile, DUMPIO_Waitsome, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpio_waitsome_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_pack_to_python(bp::dict& args, const dumpi_pack *prm) {

    args["incount"]	= prm->incount;
    args["datatype"]	= prm->datatype;
    args["outcount"]	= prm->outcount;
      bp::dict position;
      position["in"]  = prm->position.in;
      position["out"] = prm->position.out;
    args["position"] 	= position;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Pack(const dumpi_pack *prm, 
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
		fun = user_python_translator.attr("MPI_Pack");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Pack, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_pack_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_pack_external_to_python(bp::dict& args, const dumpi_pack_external *prm) {

    args["datarep"]	= std::string(prm->datarep);
    args["incount"]	= prm->incount;
    args["intype"]	= prm->intype;
    args["outcount"]	= prm->outcount;
    bp::dict d;
    d["in"]  = prm->position.in;
    d["out"] = prm->position.out;
    args["position"] = d;
}

extern "C" int cortex_python_translate_MPI_Pack_external(const dumpi_pack_external *prm, 
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
		fun = user_python_translator.attr("MPI_Pack_external");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Pack_external, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_pack_external_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_pack_external_size_to_python(bp::dict& args, const dumpi_pack_external_size *prm) {

    args["datarep"]	= std::string(prm->datarep);
    args["incount"]	= prm->incount;
    args["datatype"]	= prm->datatype;
    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_Pack_external_size(const dumpi_pack_external_size *prm, 
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
		fun = user_python_translator.attr("MPI_Pack_external_size");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Pack_external_size, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_pack_external_size_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_pack_size_to_python(bp::dict& args, const dumpi_pack_size *prm) {

    args["incount"]	= prm->incount;
    args["datatype"]	= prm->datatype;
    args["comm"]	= prm->comm;
    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_Pack_size(const dumpi_pack_size *prm, 
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
		fun = user_python_translator.attr("MPI_Pack_size");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Pack_size, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_pack_size_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_probe_to_python(bp::dict& args, const dumpi_probe *prm) {

    args["source"]	= prm->source;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_Probe(const dumpi_probe *prm, 
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
		fun = user_python_translator.attr("MPI_Probe");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Probe, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_probe_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_publish_name_to_python(bp::dict& args, const dumpi_publish_name *prm) {

    args["servicename"]	= std::string(prm->servicename);
    args["info"]	= prm->info;
    args["portname"]	= std::string(prm->portname);

}

extern "C" int cortex_python_translate_MPI_Publish_name(const dumpi_publish_name *prm, 
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
		fun = user_python_translator.attr("MPI_Publish_name");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Publish_name, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_publish_name_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_put_to_python(bp::dict& args, const dumpi_put *prm) {

    args["origincount"]	= prm->origincount;
    args["origintype"]	= prm->origintype;
    args["targetrank"]	= prm->targetrank;
    args["targetdisp"]	= prm->targetdisp;
    args["targetcount"]	= prm->targetcount;
    args["targettype"]	= prm->targettype;
    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Put(const dumpi_put *prm, 
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
		fun = user_python_translator.attr("MPI_Put");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Put, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_put_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_query_thread_to_python(bp::dict& args, const dumpi_query_thread *prm) {

    args["supported"]	= prm->supported;

}

extern "C" int cortex_python_translate_MPI_Query_thread(const dumpi_query_thread *prm, 
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
		fun = user_python_translator.attr("MPI_Query_thread");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Query_thread, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_query_thread_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_recv_to_python(bp::dict& args, const dumpi_recv *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["source"]	= prm->source;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_Recv(const dumpi_recv *prm, 
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
		fun = user_python_translator.attr("MPI_Recv");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Recv, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_recv_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_recv_init_to_python(bp::dict& args, const dumpi_recv_init *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["source"]	= prm->source;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Recv_init(const dumpi_recv_init *prm, 
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
		fun = user_python_translator.attr("MPI_Recv_init");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Recv_init, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_recv_init_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_reduce_to_python(bp::dict& args, const dumpi_reduce *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["op"]	= prm->op;
    args["root"]	= prm->root;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Reduce(const dumpi_reduce *prm, 
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
		fun = user_python_translator.attr("MPI_Reduce");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Reduce, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_reduce_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_reduce_scatter_to_python(bp::dict& args, const dumpi_reduce_scatter *prm) {

    args["commsize"]	= prm->commsize;
    args["recvcounts"]	= stl_vector_to_py_list(std::vector<int>(prm->recvcounts,prm->recvcounts+prm->commsize));
    args["datatype"]	= prm->datatype;
    args["op"]	= prm->op;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Reduce_scatter(const dumpi_reduce_scatter *prm, 
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
		fun = user_python_translator.attr("MPI_Reduce_scatter");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Reduce_scatter, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_reduce_scatter_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_register_datarep_to_python(bp::dict& args, const dumpi_register_datarep *prm) {

    args["name"]	= std::string(prm->name);

}

extern "C" int cortex_python_translate_MPI_Register_datarep(const dumpi_register_datarep *prm, 
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
		fun = user_python_translator.attr("MPI_Register_datarep");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Register_datarep, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_register_datarep_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_request_free_to_python(bp::dict& args, const dumpi_request_free *prm) {

    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Request_free(const dumpi_request_free *prm, 
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
		fun = user_python_translator.attr("MPI_Request_free");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Request_free, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_request_free_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_request_get_status_to_python(bp::dict& args, const dumpi_request_get_status *prm) {

    args["request"]	= prm->request;
    args["flag"]	= prm->flag;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_Request_get_status(const dumpi_request_get_status *prm, 
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
		fun = user_python_translator.attr("MPI_Request_get_status");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Request_get_status, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_request_get_status_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_rsend_to_python(bp::dict& args, const dumpi_rsend *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Rsend(const dumpi_rsend *prm, 
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
		fun = user_python_translator.attr("MPI_Rsend");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Rsend, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_rsend_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_rsend_init_to_python(bp::dict& args, const dumpi_rsend_init *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Rsend_init(const dumpi_rsend_init *prm, 
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
		fun = user_python_translator.attr("MPI_Rsend_init");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Rsend_init, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_rsend_init_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_scan_to_python(bp::dict& args, const dumpi_scan *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["op"]	= prm->op;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Scan(const dumpi_scan *prm, 
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
		fun = user_python_translator.attr("MPI_Scan");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Scan, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_scan_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_scatter_to_python(bp::dict& args, const dumpi_scatter *prm) {

    args["commrank"]	= prm->commrank;
    args["sendcount"]	= prm->sendcount;
    args["sendtype"]	= prm->sendtype;
    args["recvcount"]	= prm->recvcount;
    args["recvtype"]	= prm->recvtype;
    args["root"]	= prm->root;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Scatter(const dumpi_scatter *prm, 
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
		fun = user_python_translator.attr("MPI_Scatter");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Scatter, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_scatter_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_scatterv_to_python(bp::dict& args, const dumpi_scatterv *prm) {

    args["commrank"]	= prm->commrank;
    args["commsize"]	= prm->commsize;
    args["sendcounts"]	= stl_vector_to_py_list(std::vector<int>(prm->sendcounts,prm->sendcounts+prm->commsize));
    args["displs"]	= stl_vector_to_py_list(std::vector<int>(prm->displs,prm->displs+prm->commsize));
    args["sendtype"]	= prm->sendtype;
    args["recvcount"]	= prm->recvcount;
    args["recvtype"]	= prm->recvtype;
    args["root"]	= prm->root;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Scatterv(const dumpi_scatterv *prm, 
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
		fun = user_python_translator.attr("MPI_Scatterv");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Scatterv, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_scatterv_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_send_to_python(bp::dict& args, const dumpi_send *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Send(const dumpi_send *prm, 
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
		fun = user_python_translator.attr("MPI_Send");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Send, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_send_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_send_init_to_python(bp::dict& args, const dumpi_send_init *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Send_init(const dumpi_send_init *prm, 
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
		fun = user_python_translator.attr("MPI_Send_init");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Send_init, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_send_init_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_sendrecv_to_python(bp::dict& args, const dumpi_sendrecv *prm) {

    args["sendcount"]	= prm->sendcount;
    args["sendtype"]	= prm->sendtype;
    args["dest"]	= prm->dest;
    args["sendtag"]	= prm->sendtag;
    args["recvcount"]	= prm->recvcount;
    args["recvtype"]	= prm->recvtype;
    args["source"]	= prm->source;
    args["recvtag"]	= prm->recvtag;
    args["comm"]	= prm->comm;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_Sendrecv(const dumpi_sendrecv *prm, 
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
		fun = user_python_translator.attr("MPI_Sendrecv");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Sendrecv, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_sendrecv_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_sendrecv_replace_to_python(bp::dict& args, const dumpi_sendrecv_replace *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["sendtag"]	= prm->sendtag;
    args["source"]	= prm->source;
    args["recvtag"]	= prm->recvtag;
    args["comm"]	= prm->comm;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_Sendrecv_replace(const dumpi_sendrecv_replace *prm, 
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
		fun = user_python_translator.attr("MPI_Sendrecv_replace");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Sendrecv_replace, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_sendrecv_replace_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_ssend_to_python(bp::dict& args, const dumpi_ssend *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Ssend(const dumpi_ssend *prm, 
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
		fun = user_python_translator.attr("MPI_Ssend");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Ssend, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_ssend_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_ssend_init_to_python(bp::dict& args, const dumpi_ssend_init *prm) {

    args["count"]	= prm->count;
    args["datatype"]	= prm->datatype;
    args["dest"]	= prm->dest;
    args["tag"]	= prm->tag;
    args["comm"]	= prm->comm;
    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Ssend_init(const dumpi_ssend_init *prm, 
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
		fun = user_python_translator.attr("MPI_Ssend_init");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Ssend_init, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_ssend_init_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_startall_to_python(bp::dict& args, const dumpi_startall *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpi_request>(prm->requests,prm->requests+prm->count));

}

extern "C" int cortex_python_translate_MPI_Startall(const dumpi_startall *prm, 
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
		fun = user_python_translator.attr("MPI_Startall");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Startall, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_startall_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_start_to_python(bp::dict& args, const dumpi_start *prm) {

    args["request"]	= prm->request;

}

extern "C" int cortex_python_translate_MPI_Start(const dumpi_start *prm, 
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
		fun = user_python_translator.attr("MPI_Start");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Start, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_start_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_status_set_cancelled_to_python(bp::dict& args, const dumpi_status_set_cancelled *prm) {

    args["status"]	= *(prm->status);
    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_Status_set_cancelled(const dumpi_status_set_cancelled *prm, 
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
		fun = user_python_translator.attr("MPI_Status_set_cancelled");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Status_set_cancelled, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_status_set_cancelled_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_status_set_elements_to_python(bp::dict& args, const dumpi_status_set_elements *prm) {

    args["status"]	= *(prm->status);
    args["datatype"]	= prm->datatype;
    args["count"]	= prm->count;

}

extern "C" int cortex_python_translate_MPI_Status_set_elements(const dumpi_status_set_elements *prm, 
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
		fun = user_python_translator.attr("MPI_Status_set_elements");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Status_set_elements, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_status_set_elements_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_testall_to_python(bp::dict& args, const dumpi_testall *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpi_request>(prm->requests,prm->requests+prm->count));
    args["flag"]	= prm->flag;
    args["statuses"]	= stl_vector_to_py_list(std::vector<dumpi_status>(prm->statuses,prm->statuses+prm->count));

}

extern "C" int cortex_python_translate_MPI_Testall(const dumpi_testall *prm, 
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
		fun = user_python_translator.attr("MPI_Testall");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Testall, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_testall_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_testany_to_python(bp::dict& args, const dumpi_testany *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpi_request>(prm->requests,prm->requests+prm->count));
    args["index"]	= prm->index;
    args["flag"]	= prm->flag;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_Testany(const dumpi_testany *prm, 
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
		fun = user_python_translator.attr("MPI_Testany");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Testany, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_testany_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_test_cancelled_to_python(bp::dict& args, const dumpi_test_cancelled *prm) {

    args["status"]	= *(prm->status);
    args["cancelled"]	= prm->cancelled;

}

extern "C" int cortex_python_translate_MPI_Test_cancelled(const dumpi_test_cancelled *prm, 
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
		fun = user_python_translator.attr("MPI_Test_cancelled");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Test_cancelled, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_test_cancelled_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_test_to_python(bp::dict& args, const dumpi_test *prm) {

    args["request"]	= prm->request;
    args["flag"]	= prm->flag;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_Test(const dumpi_test *prm, 
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
		fun = user_python_translator.attr("MPI_Test");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Test, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_test_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_testsome_to_python(bp::dict& args, const dumpi_testsome *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpi_request>(prm->requests,prm->requests+prm->count));
    args["outcount"]	= prm->outcount;
    args["indices"]	= stl_vector_to_py_list(std::vector<int>(prm->indices,prm->indices+prm->outcount));
    args["statuses"]	= stl_vector_to_py_list(std::vector<dumpi_status>(prm->statuses,prm->statuses+prm->outcount));

}

extern "C" int cortex_python_translate_MPI_Testsome(const dumpi_testsome *prm, 
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
		fun = user_python_translator.attr("MPI_Testsome");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Testsome, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_testsome_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_topo_test_to_python(bp::dict& args, const dumpi_topo_test *prm) {

    args["comm"]	= prm->comm;
    args["topo"]	= prm->topo;

}

extern "C" int cortex_python_translate_MPI_Topo_test(const dumpi_topo_test *prm, 
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
		fun = user_python_translator.attr("MPI_Topo_test");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Topo_test, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_topo_test_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_commit_to_python(bp::dict& args, const dumpi_type_commit *prm) {

    args["datatype"]	= prm->datatype;

}

extern "C" int cortex_python_translate_MPI_Type_commit(const dumpi_type_commit *prm, 
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
		fun = user_python_translator.attr("MPI_Type_commit");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_commit, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_commit_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_contiguous_to_python(bp::dict& args, const dumpi_type_contiguous *prm) {

    args["count"]	= prm->count;
    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_contiguous(const dumpi_type_contiguous *prm, 
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
		fun = user_python_translator.attr("MPI_Type_contiguous");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_contiguous, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_contiguous_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

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

static void dumpi_type_create_hindexed_to_python(bp::dict& args, const dumpi_type_create_hindexed *prm) {

    args["count"]	= prm->count;
    args["blocklengths"]	= stl_vector_to_py_list(std::vector<int>(prm->blocklengths,prm->blocklengths+prm->count));
    args["displacements"]	= stl_vector_to_py_list(std::vector<int>(prm->displacements,prm->displacements+prm->count));
    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_create_hindexed(const dumpi_type_create_hindexed *prm, 
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
		fun = user_python_translator.attr("MPI_Type_create_hindexed");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_create_hindexed, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_create_hindexed_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_create_hvector_to_python(bp::dict& args, const dumpi_type_create_hvector *prm) {

    args["count"]	= prm->count;
    args["blocklength"]	= prm->blocklength;
    args["stride"]	= prm->stride;
    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_create_hvector(const dumpi_type_create_hvector *prm, 
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
		fun = user_python_translator.attr("MPI_Type_create_hvector");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_create_hvector, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_create_hvector_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_create_indexed_block_to_python(bp::dict& args, const dumpi_type_create_indexed_block *prm) {

    args["count"]	= prm->count;
    args["blocklength"]	= prm->blocklength;
    args["displacments"]	= stl_vector_to_py_list(std::vector<int>(prm->displacments,prm->displacments+prm->count));
    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_create_indexed_block(const dumpi_type_create_indexed_block *prm, 
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
		fun = user_python_translator.attr("MPI_Type_create_indexed_block");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_create_indexed_block, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_create_indexed_block_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_create_keyval_to_python(bp::dict& args, const dumpi_type_create_keyval *prm) {

    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Type_create_keyval(const dumpi_type_create_keyval *prm, 
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
		fun = user_python_translator.attr("MPI_Type_create_keyval");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_create_keyval, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_create_keyval_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_create_resized_to_python(bp::dict& args, const dumpi_type_create_resized *prm) {

    args["oldtype"]	= prm->oldtype;
    args["lb"]	= prm->lb;
    args["extent"]	= prm->extent;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_create_resized(const dumpi_type_create_resized *prm, 
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
		fun = user_python_translator.attr("MPI_Type_create_resized");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_create_resized, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_create_resized_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_create_struct_to_python(bp::dict& args, const dumpi_type_create_struct *prm) {

    args["count"]	= prm->count;
    args["blocklengths"]	= stl_vector_to_py_list(std::vector<int>(prm->blocklengths,prm->blocklengths+prm->count));
    args["displacements"]	= stl_vector_to_py_list(std::vector<int>(prm->displacements,prm->displacements+prm->count));
    args["oldtypes"]	= stl_vector_to_py_list(std::vector<dumpi_datatype>(prm->oldtypes,prm->oldtypes+prm->count));
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_create_struct(const dumpi_type_create_struct *prm, 
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
		fun = user_python_translator.attr("MPI_Type_create_struct");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_create_struct, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_create_struct_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_create_subarray_to_python(bp::dict& args, const dumpi_type_create_subarray *prm) {

    args["ndims"]	= prm->ndims;
    args["sizes"]	= stl_vector_to_py_list(std::vector<int>(prm->sizes,prm->sizes+prm->ndims));
    args["subsizes"]	= stl_vector_to_py_list(std::vector<int>(prm->subsizes,prm->subsizes+prm->ndims));
    args["starts"]	= stl_vector_to_py_list(std::vector<int>(prm->starts,prm->starts+prm->ndims));
    args["order"]	= prm->order;
    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_create_subarray(const dumpi_type_create_subarray *prm, 
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
		fun = user_python_translator.attr("MPI_Type_create_subarray");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_create_subarray, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_create_subarray_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_delete_attr_to_python(bp::dict& args, const dumpi_type_delete_attr *prm) {

    args["datatype"]	= prm->datatype;
    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Type_delete_attr(const dumpi_type_delete_attr *prm, 
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
		fun = user_python_translator.attr("MPI_Type_delete_attr");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_delete_attr, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_delete_attr_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_dup_to_python(bp::dict& args, const dumpi_type_dup *prm) {

    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_dup(const dumpi_type_dup *prm, 
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
		fun = user_python_translator.attr("MPI_Type_dup");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_dup, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_dup_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_extent_to_python(bp::dict& args, const dumpi_type_extent *prm) {

    args["datatype"]	= prm->datatype;
    args["extent"]	= prm->extent;

}

extern "C" int cortex_python_translate_MPI_Type_extent(const dumpi_type_extent *prm, 
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
		fun = user_python_translator.attr("MPI_Type_extent");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_extent, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_extent_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_free_to_python(bp::dict& args, const dumpi_type_free *prm) {

    args["datatype"]	= prm->datatype;

}

extern "C" int cortex_python_translate_MPI_Type_free(const dumpi_type_free *prm, 
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
		fun = user_python_translator.attr("MPI_Type_free");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_free, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_free_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_free_keyval_to_python(bp::dict& args, const dumpi_type_free_keyval *prm) {

    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Type_free_keyval(const dumpi_type_free_keyval *prm, 
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
		fun = user_python_translator.attr("MPI_Type_free_keyval");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_free_keyval, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_free_keyval_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_get_attr_to_python(bp::dict& args, const dumpi_type_get_attr *prm) {

    args["datatype"]	= prm->datatype;
    args["keyval"]	= prm->keyval;
    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_Type_get_attr(const dumpi_type_get_attr *prm, 
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
		fun = user_python_translator.attr("MPI_Type_get_attr");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_get_attr, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_get_attr_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

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

static void dumpi_type_get_envelope_to_python(bp::dict& args, const dumpi_type_get_envelope *prm) {

    args["datatype"]	= prm->datatype;
    args["numintegers"]	= prm->numintegers;
    args["numaddresses"]	= prm->numaddresses;
    args["numdatatypes"]	= prm->numdatatypes;
    args["combiner"]	= prm->combiner;

}

extern "C" int cortex_python_translate_MPI_Type_get_envelope(const dumpi_type_get_envelope *prm, 
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
		fun = user_python_translator.attr("MPI_Type_get_envelope");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_get_envelope, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_get_envelope_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_get_extent_to_python(bp::dict& args, const dumpi_type_get_extent *prm) {

    args["datatype"]	= prm->datatype;
    args["lb"]	= prm->lb;
    args["extent"]	= prm->extent;

}

extern "C" int cortex_python_translate_MPI_Type_get_extent(const dumpi_type_get_extent *prm, 
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
		fun = user_python_translator.attr("MPI_Type_get_extent");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_get_extent, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_get_extent_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_get_name_to_python(bp::dict& args, const dumpi_type_get_name *prm) {

    args["datatype"]	= prm->datatype;
    args["name"]	= std::string(prm->name);
    args["resultlen"]	= prm->resultlen;

}

extern "C" int cortex_python_translate_MPI_Type_get_name(const dumpi_type_get_name *prm, 
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
		fun = user_python_translator.attr("MPI_Type_get_name");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_get_name, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_get_name_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_get_true_extent_to_python(bp::dict& args, const dumpi_type_get_true_extent *prm) {

    args["datatype"]	= prm->datatype;
    args["lb"]	= prm->lb;
    args["extent"]	= prm->extent;

}

extern "C" int cortex_python_translate_MPI_Type_get_true_extent(const dumpi_type_get_true_extent *prm, 
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
		fun = user_python_translator.attr("MPI_Type_get_true_extent");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_get_true_extent, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_get_true_extent_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_hindexed_to_python(bp::dict& args, const dumpi_type_hindexed *prm) {

    args["count"]	= prm->count;
    args["lengths"]	= stl_vector_to_py_list(std::vector<int>(prm->lengths,prm->lengths+prm->count));
    args["indices"]	= stl_vector_to_py_list(std::vector<int>(prm->indices,prm->indices+prm->count));
    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_hindexed(const dumpi_type_hindexed *prm, 
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
		fun = user_python_translator.attr("MPI_Type_hindexed");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_hindexed, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_hindexed_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_hvector_to_python(bp::dict& args, const dumpi_type_hvector *prm) {

    args["count"]	= prm->count;
    args["blocklength"]	= prm->blocklength;
    args["stride"]	= prm->stride;
    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_hvector(const dumpi_type_hvector *prm, 
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
		fun = user_python_translator.attr("MPI_Type_hvector");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_hvector, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_hvector_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_indexed_to_python(bp::dict& args, const dumpi_type_indexed *prm) {

    args["count"]	= prm->count;
    args["lengths"]	= stl_vector_to_py_list(std::vector<int>(prm->lengths,prm->lengths+prm->count));
    args["indices"]	= stl_vector_to_py_list(std::vector<int>(prm->indices,prm->indices+prm->count));
    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_indexed(const dumpi_type_indexed *prm, 
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
		fun = user_python_translator.attr("MPI_Type_indexed");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_indexed, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_indexed_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_lb_to_python(bp::dict& args, const dumpi_type_lb *prm) {

    args["datatype"]	= prm->datatype;
    args["lb"]	= prm->lb;

}

extern "C" int cortex_python_translate_MPI_Type_lb(const dumpi_type_lb *prm, 
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
		fun = user_python_translator.attr("MPI_Type_lb");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_lb, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_lb_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_match_size_to_python(bp::dict& args, const dumpi_type_match_size *prm) {

    args["typeclass"]	= prm->typeclass;
    args["size"]	= prm->size;
    args["datatype"]	= prm->datatype;

}

extern "C" int cortex_python_translate_MPI_Type_match_size(const dumpi_type_match_size *prm, 
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
		fun = user_python_translator.attr("MPI_Type_match_size");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_match_size, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_match_size_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_set_attr_to_python(bp::dict& args, const dumpi_type_set_attr *prm) {

    args["datatype"]	= prm->datatype;
    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Type_set_attr(const dumpi_type_set_attr *prm, 
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
		fun = user_python_translator.attr("MPI_Type_set_attr");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_set_attr, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_set_attr_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_set_name_to_python(bp::dict& args, const dumpi_type_set_name *prm) {

    args["datatype"]	= prm->datatype;
    args["name"]	= std::string(prm->name);

}

extern "C" int cortex_python_translate_MPI_Type_set_name(const dumpi_type_set_name *prm, 
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
		fun = user_python_translator.attr("MPI_Type_set_name");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_set_name, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_set_name_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_size_to_python(bp::dict& args, const dumpi_type_size *prm) {

    args["datatype"]	= prm->datatype;
    args["size"]	= prm->size;

}

extern "C" int cortex_python_translate_MPI_Type_size(const dumpi_type_size *prm, 
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
		fun = user_python_translator.attr("MPI_Type_size");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_size, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_size_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_struct_to_python(bp::dict& args, const dumpi_type_struct *prm) {

    args["count"]	= prm->count;
    args["lengths"]	= stl_vector_to_py_list(std::vector<int>(prm->lengths,prm->lengths+prm->count));
    args["indices"]	= stl_vector_to_py_list(std::vector<int>(prm->indices,prm->indices+prm->count));
    args["oldtypes"]	= stl_vector_to_py_list(std::vector<dumpi_datatype>(prm->oldtypes,prm->oldtypes+prm->count));
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_struct(const dumpi_type_struct *prm, 
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
		fun = user_python_translator.attr("MPI_Type_struct");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_struct, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_struct_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_ub_to_python(bp::dict& args, const dumpi_type_ub *prm) {

    args["datatype"]	= prm->datatype;
    args["ub"]	= prm->ub;

}

extern "C" int cortex_python_translate_MPI_Type_ub(const dumpi_type_ub *prm, 
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
		fun = user_python_translator.attr("MPI_Type_ub");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_ub, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_ub_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_type_vector_to_python(bp::dict& args, const dumpi_type_vector *prm) {

    args["count"]	= prm->count;
    args["blocklength"]	= prm->blocklength;
    args["stride"]	= prm->stride;
    args["oldtype"]	= prm->oldtype;
    args["newtype"]	= prm->newtype;

}

extern "C" int cortex_python_translate_MPI_Type_vector(const dumpi_type_vector *prm, 
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
		fun = user_python_translator.attr("MPI_Type_vector");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Type_vector, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_type_vector_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_unpack_to_python(bp::dict& args, const dumpi_unpack *prm) {

    args["incount"]	= prm->incount;
      bp::dict position;
      position["in"] = prm->position.in;
      position["out"] = prm->position.out;
    args["position"] 	= position;
    args["outcount"]	= prm->outcount;
    args["datatype"]	= prm->datatype;
    args["comm"]	= prm->comm;

}

extern "C" int cortex_python_translate_MPI_Unpack(const dumpi_unpack *prm, 
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
		fun = user_python_translator.attr("MPI_Unpack");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Unpack, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_unpack_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_unpack_external_to_python(bp::dict& args, const dumpi_unpack_external *prm) {

    args["datarep"]	= std::string(prm->datarep);
    args["insize"]	= prm->insize;
    bp::dict d;
    d["in"]  = prm->position.in;
    d["out"] = prm->position.out;
    args["position"] 	= d;
    args["outcount"]	= prm->outcount;
    args["datatype"]	= prm->datatype;

}

extern "C" int cortex_python_translate_MPI_Unpack_external(const dumpi_unpack_external *prm, 
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
		fun = user_python_translator.attr("MPI_Unpack_external");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Unpack_external, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_unpack_external_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_unpublish_name_to_python(bp::dict& args, const dumpi_unpublish_name *prm) {

    args["servicename"]	= std::string(prm->servicename);
    args["info"]	= prm->info;
    args["portname"]	= std::string(prm->portname);

}

extern "C" int cortex_python_translate_MPI_Unpublish_name(const dumpi_unpublish_name *prm, 
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
		fun = user_python_translator.attr("MPI_Unpublish_name");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Unpublish_name, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_unpublish_name_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_waitall_to_python(bp::dict& args, const dumpi_waitall *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpi_request>(prm->requests,prm->requests+prm->count));
    args["statuses"]	= stl_vector_to_py_list(std::vector<dumpi_status>(prm->statuses,prm->statuses+prm->count));

}

extern "C" int cortex_python_translate_MPI_Waitall(const dumpi_waitall *prm, 
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
		fun = user_python_translator.attr("MPI_Waitall");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Waitall, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_waitall_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_waitany_to_python(bp::dict& args, const dumpi_waitany *prm) {

    args["count"]	= prm->count;
    args["requests"]	= stl_vector_to_py_list(std::vector<dumpi_request>(prm->requests,prm->requests+prm->count));
    args["index"]	= prm->index;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_Waitany(const dumpi_waitany *prm, 
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
		fun = user_python_translator.attr("MPI_Waitany");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Waitany, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_waitany_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_wait_to_python(bp::dict& args, const dumpi_wait *prm) {

    args["request"]	= prm->request;
    args["status"]	= *(prm->status);

}

extern "C" int cortex_python_translate_MPI_Wait(const dumpi_wait *prm, 
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
		fun = user_python_translator.attr("MPI_Wait");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Wait, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_wait_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

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
                thread = profile->rank;
		cortex_post(profile, DUMPI_Waitsome, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_waitsome_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_call_errhandler_to_python(bp::dict& args, const dumpi_win_call_errhandler *prm) {

    args["win"]	= prm->win;
    args["errorcode"]	= prm->errorcode;

}

extern "C" int cortex_python_translate_MPI_Win_call_errhandler(const dumpi_win_call_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_Win_call_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_call_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_call_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_complete_to_python(bp::dict& args, const dumpi_win_complete *prm) {

    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Win_complete(const dumpi_win_complete *prm, 
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
		fun = user_python_translator.attr("MPI_Win_complete");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_complete, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_complete_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_create_to_python(bp::dict& args, const dumpi_win_create *prm) {

    args["size"]	= prm->size;
    args["dispunit"]	= prm->dispunit;
    args["info"]	= prm->info;
    args["comm"]	= prm->comm;
    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Win_create(const dumpi_win_create *prm, 
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
		fun = user_python_translator.attr("MPI_Win_create");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_create, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_create_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_create_errhandler_to_python(bp::dict& args, const dumpi_win_create_errhandler *prm) {

    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_Win_create_errhandler(const dumpi_win_create_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_Win_create_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_create_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_create_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_create_keyval_to_python(bp::dict& args, const dumpi_win_create_keyval *prm) {

    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Win_create_keyval(const dumpi_win_create_keyval *prm, 
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
		fun = user_python_translator.attr("MPI_Win_create_keyval");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_create_keyval, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_create_keyval_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_delete_attr_to_python(bp::dict& args, const dumpi_win_delete_attr *prm) {

    args["win"]	= prm->win;
    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Win_delete_attr(const dumpi_win_delete_attr *prm, 
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
		fun = user_python_translator.attr("MPI_Win_delete_attr");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_delete_attr, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_delete_attr_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_fence_to_python(bp::dict& args, const dumpi_win_fence *prm) {

    args["assertion"]	= prm->assertion;
    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Win_fence(const dumpi_win_fence *prm, 
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
		fun = user_python_translator.attr("MPI_Win_fence");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_fence, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_fence_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_free_to_python(bp::dict& args, const dumpi_win_free *prm) {

    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Win_free(const dumpi_win_free *prm, 
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
		fun = user_python_translator.attr("MPI_Win_free");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_free, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_free_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_free_keyval_to_python(bp::dict& args, const dumpi_win_free_keyval *prm) {

    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Win_free_keyval(const dumpi_win_free_keyval *prm, 
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
		fun = user_python_translator.attr("MPI_Win_free_keyval");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_free_keyval, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_free_keyval_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_get_attr_to_python(bp::dict& args, const dumpi_win_get_attr *prm) {

    args["win"]	= prm->win;
    args["keyval"]	= prm->keyval;
    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_Win_get_attr(const dumpi_win_get_attr *prm, 
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
		fun = user_python_translator.attr("MPI_Win_get_attr");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_get_attr, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_get_attr_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_get_errhandler_to_python(bp::dict& args, const dumpi_win_get_errhandler *prm) {

    args["win"] = prm->win;
    args["errhandler"]  = prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_Win_get_errhandler(const dumpi_win_get_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_Win_get_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_get_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_get_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_get_group_to_python(bp::dict& args, const dumpi_win_get_group *prm) {

    args["win"]	= prm->win;
    args["group"]	= prm->group;

}

extern "C" int cortex_python_translate_MPI_Win_get_group(const dumpi_win_get_group *prm, 
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
		fun = user_python_translator.attr("MPI_Win_get_group");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_get_group, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_get_group_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_get_name_to_python(bp::dict& args, const dumpi_win_get_name *prm) {

    args["win"]	= prm->win;
    args["name"]	= std::string(prm->name);
    args["resultlen"]	= prm->resultlen;

}

extern "C" int cortex_python_translate_MPI_Win_get_name(const dumpi_win_get_name *prm, 
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
		fun = user_python_translator.attr("MPI_Win_get_name");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_get_name, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_get_name_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_lock_to_python(bp::dict& args, const dumpi_win_lock *prm) {

    args["locktype"]	= prm->locktype;
    args["winrank"]	= prm->winrank;
    args["assertion"]	= prm->assertion;
    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Win_lock(const dumpi_win_lock *prm, 
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
		fun = user_python_translator.attr("MPI_Win_lock");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_lock, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_lock_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_post_to_python(bp::dict& args, const dumpi_win_post *prm) {

    args["group"]	= prm->group;
    args["assertion"]	= prm->assertion;
    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Win_post(const dumpi_win_post *prm, 
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
		fun = user_python_translator.attr("MPI_Win_post");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_post, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_post_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_set_attr_to_python(bp::dict& args, const dumpi_win_set_attr *prm) {

    args["win"]	= prm->win;
    args["keyval"]	= prm->keyval;

}

extern "C" int cortex_python_translate_MPI_Win_set_attr(const dumpi_win_set_attr *prm, 
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
		fun = user_python_translator.attr("MPI_Win_set_attr");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_set_attr, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_set_attr_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_set_errhandler_to_python(bp::dict& args, const dumpi_win_set_errhandler *prm) {

    args["win"]	= prm->win;
    args["errhandler"]	= prm->errhandler;

}

extern "C" int cortex_python_translate_MPI_Win_set_errhandler(const dumpi_win_set_errhandler *prm, 
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
		fun = user_python_translator.attr("MPI_Win_set_errhandler");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_set_errhandler, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_set_errhandler_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_set_name_to_python(bp::dict& args, const dumpi_win_set_name *prm) {

    args["win"]	= prm->win;
    args["name"]	= std::string(prm->name);

}

extern "C" int cortex_python_translate_MPI_Win_set_name(const dumpi_win_set_name *prm, 
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
		fun = user_python_translator.attr("MPI_Win_set_name");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_set_name, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_set_name_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_start_to_python(bp::dict& args, const dumpi_win_start *prm) {

    args["group"]	= prm->group;
    args["assertion"]	= prm->assertion;
    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Win_start(const dumpi_win_start *prm, 
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
		fun = user_python_translator.attr("MPI_Win_start");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_start, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_start_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_test_to_python(bp::dict& args, const dumpi_win_test *prm) {

    args["win"]	= prm->win;
    args["flag"]	= prm->flag;

}

extern "C" int cortex_python_translate_MPI_Win_test(const dumpi_win_test *prm, 
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
		fun = user_python_translator.attr("MPI_Win_test");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_test, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_test_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_unlock_to_python(bp::dict& args, const dumpi_win_unlock *prm) {

    args["winrank"]	= prm->winrank;
    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Win_unlock(const dumpi_win_unlock *prm, 
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
		fun = user_python_translator.attr("MPI_Win_unlock");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_unlock, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_unlock_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_win_wait_to_python(bp::dict& args, const dumpi_win_wait *prm) {

    args["win"]	= prm->win;

}

extern "C" int cortex_python_translate_MPI_Win_wait(const dumpi_win_wait *prm, 
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
		fun = user_python_translator.attr("MPI_Win_wait");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Win_wait, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_win_wait_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_wtick_to_python(bp::dict& args, const dumpi_wtick *prm) {

    args["psec"]	= prm->psec;

}

extern "C" int cortex_python_translate_MPI_Wtick(const dumpi_wtick *prm, 
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
		fun = user_python_translator.attr("MPI_Wtick");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Wtick, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_wtick_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}

static void dumpi_wtime_to_python(bp::dict& args, const dumpi_wtime *prm) {

    args["psec"]	= prm->psec;

}

extern "C" int cortex_python_translate_MPI_Wtime(const dumpi_wtime *prm, 
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
		fun = user_python_translator.attr("MPI_Wtime");
	} catch(const bp::error_already_set&) {
		// No translation provided, just forward the call
		PyErr_Clear();
		cortex_dumpi_profile* profile = (cortex_dumpi_profile*)uarg;
                thread = profile->rank;
		cortex_post(profile, DUMPI_Wtime, prm, thread, cpu, wall, perf);
		return 0;
	}
	// set the uarg attribute
	cortex_python_current_uarg = uarg;
	cortex_python_current_cpu  = cpu;
	cortex_python_current_wall = wall;
	cortex_python_current_perf = perf;
	try {
		bp::dict arguments;
		dumpi_wtime_to_python(arguments,prm);
		fun(*bp::make_tuple(thread),**arguments);
	} catch(const bp::error_already_set&) {
		PyErr_Print();
		exit(-1);
	}
	cortex_python_current_uarg = NULL;
	cortex_python_current_cpu  = NULL;	cortex_python_current_wall = NULL;	cortex_python_current_perf = NULL;	return 0;
}


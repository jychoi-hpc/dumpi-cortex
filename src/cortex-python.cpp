#include <boost/python.hpp>
#include <cstdlib>
#include <cortex/cortex-python.h>

namespace bp = boost::python;

bool cortex_python_initialized = false;
bp::object user_python_module;
bp::object cortex_python_module;
bp::object user_python_translator;
void* cortex_python_current_uarg = NULL;

BOOST_PYTHON_MODULE(cortex)
{
	bp::class_<dumpi_status>("DUMPI_Status")
		.def_readonly("bytes",&dumpi_status::bytes)
		.def_readonly("source",&dumpi_status::source)
		.def_readonly("tag",&dumpi_status::tag)
		.def_readonly("cancelled",&dumpi_status::cancelled)
		.def_readonly("error",&dumpi_status::error);
}


extern "C" int cortex_python_set_module(const char* module, const char* class_name) {
	if(cortex_python_initialized) return -1;

	setenv("PYTHONPATH", ".", 1);

	Py_Initialize();
	try {
		PyImport_AppendInittab((char*)"cortex",&initcortex);
		bp::object __main__(bp::handle<>(bp::borrowed(PyImport_AddModule("__main__"))));
		bp::object __dict__ = __main__.attr("__dict__");
		cortex_python_module = bp::object(bp::handle<>(PyImport_ImportModule("cortex")));
		user_python_module = bp::import(module);
		user_python_translator 
			= user_python_module.attr(class_name)();
		
	} catch(const bp::error_already_set&)
	{
		PyErr_Print();
		exit(-1);
	}
	cortex_python_initialized = true;
	return 0;
}

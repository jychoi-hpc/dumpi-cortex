#include <boost/python.hpp>
#include "cortex/cortex.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(cortex)
{
	class_<dumpi_status>("DUMPI_Status")
		.def_readonly("bytes",&dumpi_status::bytes)
		.def_readonly("source",&dumpi_status::source)
		.def_readonly("tag",&dumpi_status::tag)
		.def_readonly("cancelled",&dumpi_status::cancelled)
		.def_readonly("error",&dumpi_status::error);
}

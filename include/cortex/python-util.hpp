#include <boost/python.hpp>
#include <vector>
#include "cortex/operation.h"

namespace py = boost::python;

template<typename T>
py::list stl_vector_to_py_list(const std::vector<T>& v) {
	py::list l;
	for(int i=0; i<v.size(); i++) {
		l.append(v[i]);
	}
	return l;
}

#include <boost/python.hpp>
#include <vector>

namespace py = boost::python;

template<typename T>
py::list stl_vector_to_py_list(const std::vector<T>& v) {
/*	py::object get_iter = py::iterator<std::vector<T> >();
	py::object iter = get_iter(v);
	return py::list(iter);
*/
	py::list l;
	for(int i=0; i<v.size(); i++) {
		l.append(v[i]);
	}
	return l;
}

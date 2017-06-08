#-----------------------------------------------------------#
# Copyright (C) 2016 University of Chicago.
# See COPYRIGHT notice in top-level directory.
#-----------------------------------------------------------#
cmake_minimum_required (VERSION 2.8)

#-----------------------------------------------------------#
# Starting project definition
#-----------------------------------------------------------#
project(CORTEX)

set(DEV_FLAGS "-g -Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS "-g")

if(DEFINED MPICH_FORWARD)
if(MPICH_FORWARD)
	set(CMAKE_C_FLAGS "-DMPICH_FORWARD")
endif()
endif()

#-----------------------------------------------------------#
# Set the location of CMake Modules
#-----------------------------------------------------------#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} 
		"${CORTEX_SOURCE_DIR}/cmake/Modules/")

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
	set(CMAKE_INSTALL_PREFIX /usr/local)
endif(NOT DEFINED CMAKE_INSTALL_PREFIX)

find_package(DUMPI REQUIRED)
include_directories(${DUMPI_INCLUDE_DIR})

set(Python_ADDITIONAL_VERSIONS 3.4 3.5)
if(DEFINED PYTHON_ROOT)
	if(EXISTS ${PYTHON_ROOT}/lib/libpython2.7.a)
		set(PYTHON_LIBRARY ${PYTHON_ROOT}/lib/libpython2.7.a)
	else()
		set(PYTHON_LIBRARY ${PYTHON_ROOT}/lib/libpython2.7.so)
	endif()
	set(PYTHON_INCLUDE_DIR ${PYTHON_ROOT}/include/python2.7)
endif(DEFINED PYTHON_ROOT)
find_package(PythonLibs)
if(PYTHONLIBS_FOUND)
	find_package(Boost 1.61 COMPONENTS python)
	if(Boost_FOUND)
		set(ENABLE_PYTHON 1)
		include_directories(${Boost_INCLUDE_DIRS})
message(STATUS "Python Include dirs contains ${PYTHON_INCLUDE_DIRS}")
		include_directories(${PYTHON_INCLUDE_DIRS})
	else(Boost_FOUND)
		set(ENABLE_PYTHON 0)
	endif(Boost_FOUND)
endif(PYTHONLIBS_FOUND)

#-----------------------------------------------------------#
include_directories(${CORTEX_SOURCE_DIR})
include_directories(${CORTEX_SOURCE_DIR}/include)
include_directories(${CORTEX_SOURCE_DIR}/src)

#-----------------------------------------------------------#
# Set subdirectories for the compilation process
#-----------------------------------------------------------#
add_subdirectory (lib)
add_subdirectory (test)

#-----------------------------------------------------------#
# Installation
#-----------------------------------------------------------#
install(DIRECTORY "include/cortex" DESTINATION include)
install(FILES "${CMAKE_BINARY_DIR}/lib/libcortex.a" DESTINATION lib)
install(FILES "${CMAKE_BINARY_DIR}/lib/libcortex-mpich.a" DESTINATION lib)
if(ENABLE_PYTHON)
  install(FILES "${CMAKE_BINARY_DIR}/lib/libcortex-python.a" DESTINATION lib)
endif(ENABLE_PYTHON)

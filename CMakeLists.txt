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

#-----------------------------------------------------------#
# Set the location of CMake Modules
#-----------------------------------------------------------#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} 
		"${CORTEX_SOURCE_DIR}/cmake/Modules/")

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
	set(CMAKE_INSTALL_PREFIX /usr/local)
endif(NOT DEFINED CMAKE_INSTALL_PREFIX)

set(DUMPI_ROOT "/home/mdorier/sw/dumpi/0.0.0")

find_package(DUMPI REQUIRED)

#include_directories(${DUMPI_ROOT}/include)
#link_directories(${DUMPI_ROOT}/lib)

include_directories(${DUMPI_INCLUDE_DIR})

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

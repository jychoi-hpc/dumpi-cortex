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

#set(DUMPI_ROOT "/home/mdorier/sw/dumpi")
find_package(DUMPI REQUIRED)
include_directories(${DUMPI_INCLUDE_DIR})

#set(CODES_ROOT "/home/mdorier/sw/codes")
find_package(CODES REQUIRED)
include_directories(${CODES_INCLUDE_DIR})

#set(ROSS_ROOT "/home/mdorier/sw/ross")
find_package(ROSS REQUIRED)
include_directories(${ROSS_INCLUDE_DIR})

#set(TOPO_ROOT "/home/mdorier/sw/topo")
find_package(TOPO REQUIRED)
include_directories(${TOPO_INCLUDE_DIR})

#-----------------------------------------------------------#
include_directories(${CORTEX_SOURCE_DIR})
include_directories(${CORTEX_SOURCE_DIR}/include)
include_directories(${CORTEX_SOURCE_DIR}/src)

#-----------------------------------------------------------#
# Set subdirectories for the compilation process
#-----------------------------------------------------------#
add_subdirectory (lib)
add_subdirectory (test)
add_subdirectory (bin)

#-----------------------------------------------------------#
# Installation
#-----------------------------------------------------------#
install(DIRECTORY "include/cortex" DESTINATION include)
install(FILES "${CMAKE_BINARY_DIR}/lib/libcortex.a" DESTINATION lib)

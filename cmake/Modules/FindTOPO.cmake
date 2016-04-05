# - Try to find TOPO
# Once done this will define
#  TOPO_FOUND - System has TOPO
#  TOPO_INCLUDE_DIRS - The TOPO include directories
#  TOPO_LIBRARIES - The libraries needed to use TOPO
#  TOPO_DEFINITIONS - Compiler switches required for using TOPO

find_package(PkgConfig)
pkg_check_modules(PC_TOPO QUIET libxml-2.0)
set(TOPO_DEFINITIONS ${PC_TOPO_CFLAGS_OTHER})

find_path(TOPO_INCLUDE_DIR codes/dragonfly-cortex-api.h 
          HINTS ${PC_TOPO_INCLUDEDIR} ${PC_TOPO_INCLUDE_DIRS} ${TOPO_ROOT}/include
          PATH_SUFFIXES codes)

find_library(TOPO_LIBRARY NAMES codes-dragonfly-cortex libcodes-dragonfly-cortex
             HINTS ${PC_TOPO_LIBDIR} ${PC_TOPO_LIBRARY_DIRS} ${TOPO_ROOT}/lib)

set(TOPO_LIBRARIES ${TOPO_LIBRARY} )
set(TOPO_INCLUDE_DIRS ${TOPO_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set TOPO2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(TOPO  DEFAULT_MSG
                                  TOPO_LIBRARY TOPO_INCLUDE_DIR)

mark_as_advanced(TOPO_INCLUDE_DIR TOPO_LIBRARY )

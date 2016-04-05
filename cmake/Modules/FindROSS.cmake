# - Try to find ROSS
# Once done this will define
#  ROSS_FOUND - System has ROSS
#  ROSS_INCLUDE_DIRS - The ROSS include directories
#  ROSS_LIBRARIES - The libraries needed to use ROSS
#  ROSS_DEFINITIONS - Compiler switches required for using ROSS

find_package(PkgConfig)
pkg_check_modules(PC_ROSS QUIET libxml-2.0)
set(ROSS_DEFINITIONS ${PC_ROSS_CFLAGS_OTHER})

find_path(ROSS_INCLUDE_DIR ross.h
          HINTS ${PC_ROSS_INCLUDEDIR} ${PC_ROSS_INCLUDE_DIRS} ${ROSS_ROOT}/include
          PATH_SUFFIXES ross)

find_library(ROSS_LIBRARY NAMES ROSS libROSS
             HINTS ${PC_ROSS_LIBDIR} ${PC_ROSS_LIBRARY_DIRS} ${ROSS_ROOT}/lib)

set(ROSS_LIBRARIES ${ROSS_LIBRARY} )
set(ROSS_INCLUDE_DIRS ${ROSS_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set ROSS2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(ROSS  DEFAULT_MSG
                                  ROSS_LIBRARY ROSS_INCLUDE_DIR)

mark_as_advanced(ROSS_INCLUDE_DIR ROSS_LIBRARY )

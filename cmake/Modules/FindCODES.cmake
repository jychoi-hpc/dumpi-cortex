# - Try to find CODES
# Once done this will define
#  CODES_FOUND - System has CODES
#  CODES_INCLUDE_DIRS - The CODES include directories
#  CODES_LIBRARIES - The libraries needed to use CODES
#  CODES_DEFINITIONS - Compiler switches required for using CODES

find_package(PkgConfig)
pkg_check_modules(PC_CODES QUIET libxml-2.0)
set(CODES_DEFINITIONS ${PC_CODES_CFLAGS_OTHER})

find_path(CODES_INCLUDE_DIR codes/codes.h
          HINTS ${PC_CODES_INCLUDEDIR} ${PC_CODES_INCLUDE_DIRS} ${CODES_ROOT}/include
          PATH_SUFFIXES codes)

find_library(CODES_LIBRARY NAMES codes libcodes
             HINTS ${PC_CODES_LIBDIR} ${PC_CODES_LIBRARY_DIRS} ${CODES_ROOT}/lib)

set(CODES_LIBRARIES ${CODES_LIBRARY} )
set(CODES_INCLUDE_DIRS ${CODES_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set CODES2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(CODES  DEFAULT_MSG
                                  CODES_LIBRARY CODES_INCLUDE_DIR)

mark_as_advanced(CODES_INCLUDE_DIR CODES_LIBRARY )

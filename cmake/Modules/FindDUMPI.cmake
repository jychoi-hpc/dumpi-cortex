# - Try to find DUMPI
# Once done this will define
#  DUMPI_FOUND - System has DUMPI
#  DUMPI_INCLUDE_DIRS - The DUMPI include directories
#  DUMPI_LIBRARIES - The libraries needed to use DUMPI
#  DUMPI_DEFINITIONS - Compiler switches required for using DUMPI

find_package(PkgConfig)
pkg_check_modules(PC_DUMPI QUIET libxml-2.0)
set(DUMPI_DEFINITIONS ${PC_DUMPI_CFLAGS_OTHER})

find_path(DUMPI_INCLUDE_DIR dumpi/dumpiconfig.h
          HINTS ${PC_DUMPI_INCLUDEDIR} ${PC_DUMPI_INCLUDE_DIRS} ${DUMPI_ROOT}/include
          PATH_SUFFIXES dumpi)

find_library(DUMPI_LIBRARY NAMES undumpi libundumpi
             HINTS ${PC_DUMPI_LIBDIR} ${PC_DUMPI_LIBRARY_DIRS} ${DUMPI_ROOT}/lib)

set(DUMPI_LIBRARIES ${DUMPI_LIBRARY} )
set(DUMPI_INCLUDE_DIRS ${DUMPI_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set DUMPI2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(DUMPI  DEFAULT_MSG
                                  DUMPI_LIBRARY DUMPI_INCLUDE_DIR)

mark_as_advanced(DUMPI_INCLUDE_DIR DUMPI_LIBRARY )

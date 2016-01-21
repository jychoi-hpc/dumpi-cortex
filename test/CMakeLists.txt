set(READ_TEST_SOURCE read.c)

set(TRANSLATION_SOURCE
	${CORTEX_SOURCE_DIR}/src/translations/mpi_barrier.c
)

add_executable(read ${READ_TEST_SOURCE} ${TRANSLATION_SOURCE})
target_link_libraries(read cortex ${DUMPI_LIBRARIES})

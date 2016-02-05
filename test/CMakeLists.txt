set(READ_TEST_SOURCE read.c)

set(TRANSLATION_SOURCE
	${CORTEX_SOURCE_DIR}/src/translations/mpi_barrier.c
	${CORTEX_SOURCE_DIR}/src/translations/mpi_bcast.c
	${CORTEX_SOURCE_DIR}/src/translations/mpi_reduce.c
	${CORTEX_SOURCE_DIR}/src/translations/mpi_allreduce.c
	${CORTEX_SOURCE_DIR}/src/translations/mpi_allgather.c
	${CORTEX_SOURCE_DIR}/src/translations/mpi_allgatherv.c
	${CORTEX_SOURCE_DIR}/src/translations/mpi_comm_dup.c
	${CORTEX_SOURCE_DIR}/src/translations/mpi_comm_split.c
	${CORTEX_SOURCE_DIR}/src/translations/mpi_comm_create.c
)

add_executable(translate ${READ_TEST_SOURCE} ${TRANSLATION_SOURCE})
target_link_libraries(translate cortex ${DUMPI_LIBRARIES})

add_executable(read ${READ_TEST_SOURCE})
target_link_libraries(read cortex ${DUMPI_LIBRARIES})

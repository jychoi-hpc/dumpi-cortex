set(CORTEX_LIB_SRC
	${CORTEX_SOURCE_DIR}/src/cortex.c
	${CORTEX_SOURCE_DIR}/src/callbacks.c
	${CORTEX_SOURCE_DIR}/src/operation.c
	${CORTEX_SOURCE_DIR}/src/post.c
	${CORTEX_SOURCE_DIR}/src/comm.c
	${CORTEX_SOURCE_DIR}/src/datatype.c
)

add_library(cortex ${CORTEX_LIB_SRC})

set(CORTEX_MPICH_SRC
	${CORTEX_SOURCE_DIR}/src/mpich-callbacks.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_allgather.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_allgatherv.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_allreduce.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_alltoallv.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_barrier.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_bcast.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_comm_create.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_comm_dup.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_comm_split.c
	${CORTEX_SOURCE_DIR}/src/mpich/mpi_reduce.c
)

add_library(cortex-mpich ${CORTEX_MPICH_SRC})

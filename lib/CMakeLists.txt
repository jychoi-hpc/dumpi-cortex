set(CORTEX_LIB_SRC
	${CORTEX_SOURCE_DIR}/src/cortex.c
	${CORTEX_SOURCE_DIR}/src/callbacks.c
	${CORTEX_SOURCE_DIR}/src/operation.c
	${CORTEX_SOURCE_DIR}/src/post.c
	${CORTEX_SOURCE_DIR}/src/comm.c
)

add_library(cortex ${CORTEX_LIB_SRC})

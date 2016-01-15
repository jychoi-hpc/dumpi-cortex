set(CORTEX_LIB_SRC
	${CORTEX_SOURCE_DIR}/src/cortex.c
	${CORTEX_SOURCE_DIR}/src/callbacks.c
)

add_library(cortex ${CORTEX_LIB_SRC})

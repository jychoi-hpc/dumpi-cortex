set(READ_TEST_SOURCE read.c)

add_executable(read ${READ_TEST_SOURCE})
target_link_libraries(read cortex-python cortex ${DUMPI_LIBRARIES} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

add_executable(py py.cpp)
target_link_libraries(py ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

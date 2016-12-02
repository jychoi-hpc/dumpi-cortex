add_executable(read_mpich read_mpich.c)
target_link_libraries(read_mpich cortex-mpich cortex ${DUMPI_LIBRARIES})

if(ENABLE_PYTHON)
  add_executable(read_python read_python.c)
  target_link_libraries(read_python cortex-python cortex ${DUMPI_LIBRARIES} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

  add_executable(gen_python gen_python.c)
  target_link_libraries(gen_python cortex-python cortex ${DUMPI_LIBRARIES} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
endif(ENABLE_PYTHON)

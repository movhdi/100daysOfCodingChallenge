# set(${CMAKE_CXX_FLAGS} "${CMAKE_CXX_FLAGS}" "-pthread")
# set(${CMAKE_EXE_LINKER_FLAGS} "${CMAKE_EXE_LINKER_FLAGS} -lpthread")
add_library(parallelAlg)

target_sources(parallelAlg PUBLIC parallelAlg.cpp)

target_include_directories(parallelAlg PUBLIC ${CMAKE_SOURCE_DIR}/include)
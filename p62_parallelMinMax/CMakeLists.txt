cmake_minimum_required(VERSION 3.14)


set(CMAKE_CXX_STANDARD 17)
set(projectName parallelMinMaxFinder)
set(thread_compiler_flag "-pthread")

project(${projectName} VERSION 1.0.0 LANGUAGES CXX)
set(${CMAKE_CXX_FLAGS} "${CMAKE_CXX_FLAGS} ${thread_compiler_flag}")

# set(${CMAKE_EXE_LINKER_FLAGS} "${CMAKE_EXE_LINKER_FLAGS} -lpthread")
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)


add_subdirectory(src)

add_executable(${projectName} main.cpp)
target_link_libraries(${projectName} PUBLIC parallelAlg Threads::Threads)
add_compile_options("-pthread")
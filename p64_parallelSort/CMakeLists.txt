cmake_minimum_required(VERSION 3.14)

set(ProjectName parallelMinMaxAsync)
set(CMAKE_CXX_STANDARD 17)


project(${ProjectName} LANGUAGES CXX VERSION 1.0.0)
set(CMAKE_CXX_FLAGS "-pthread")
add_executable(${ProjectName} main.cpp)
cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(ProjectName VigenerCipher)
add_compile_definitions(DEBUG)

project(${ProjectName} VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(src)

add_executable(${ProjectName} main.cpp)
target_link_libraries(${ProjectName} cryptoLib)
target_include_directories(${ProjectName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
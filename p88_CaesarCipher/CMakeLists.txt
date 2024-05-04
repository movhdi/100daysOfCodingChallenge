cmake_minimum_required(VERSION 3.14)
set(ProjectName CaesarCipher)
project(${ProjectName} VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(src)

add_executable(${ProjectName} main.cpp)
target_link_libraries(${ProjectName} cryptoLib)
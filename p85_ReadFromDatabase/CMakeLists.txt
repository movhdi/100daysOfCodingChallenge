cmake_minimum_required(VERSION 3.14)
project(databasePractice LANGUAGES CXX)
set(${CXX_STANDARD} 17)

find_package(SQLite3 REQUIRED)
find_package(Threads REQUIRED)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SQLiteCpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)
message("CMAKE_CURRENT_SOURCE_DIR :  " ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(databaseRunner main.cpp)
target_link_libraries(databaseRunner
                      performanceEval
                      sqlite3
                      SQLiteCpp
                      pthread
                      dl)
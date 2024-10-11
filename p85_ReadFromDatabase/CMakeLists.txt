cmake_minimum_required(VERSION 3.14)
project(databasePractice LANGUAGES CXX)
set(${CXX_STANDARD} 17)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SQLiteCpp)
message(${CMAKE_CURRENT_SOURCE_DIR})

find_package(SQLite3)
find_package(Threads REQUIRED)

add_executable(databaseRunner main.cpp)
target_link_libraries(databaseRunner
                      SQLiteCpp
                      sqlite3
                      pthread
                      dl)
cmake_minimum_required(VERSION 3.14)

set(${CMAKE_CXX_STANDARD} 17)
set(${CMAKE_CXX_STANDARD_REQUIRED} True)


project(databasePractice LANGUAGES CXX)

find_package(SQLite3 REQUIRED)
find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS log_setup log system thread filesystem)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SQLiteCpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)
message("CMAKE_CURRENT_SOURCE_DIR :  " ${CMAKE_CURRENT_SOURCE_DIR})


if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})    
    add_executable(databaseRunner main.cpp)
    target_include_directories(databaseRunner PUBLIC ".")
    target_link_libraries(databaseRunner  
                                         performanceEval
                                         Boost::log_setup
                                         Boost::log
                                         sqlite3
                                         #   SQLiteCpp
                                         pthread
                                         dl)
    message("Boost FOUND!!!!s")
else()
    message(FATAL_ERROR "Boost Not Found!!!!!")
endif(Boost_FOUND)    


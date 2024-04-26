cmake_minimum_required(VERSION 3.14)

set(ProjectName xmlDataSerialize)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    pugixml
    GIT_REPOSITORY https://github.com/zeux/pugixml.git
    GIT_TAG v1.14
)
message("this is going to populate the pugixml")

# FetchContent_MakeAvailable(pugixml)
FetchContent_GetProperties(pugixml)
string(TOLOWER "pugixml" lcname)
if(NOT ${lcname}_POPULATED)
    FetchContent_Populate(pugixml)
    message(${${lcname}_SOURCE_DIR})
    message(${${lcname}_BINARY_DIR})
    add_subdirectory(${${lcname}_SOURCE_DIR} ${${lcname}_BINARY_DIR})
endif()
message("The path to pugixml src stored in cmake is: " ${${lcname}_SOURCE_DIR})
message("The path to pugixml bin stored in cmake is: " ${${lcname}_BINARY_DIR})


project(${ProjectName} LANGUAGES CXX VERSION 1.0.0)
set(CMAKE_CXX_FLAGS "-pthread")
add_executable(${ProjectName} main.cpp)
target_link_libraries(${ProjectName} pugixml)

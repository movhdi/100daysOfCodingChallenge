cmake_minimum_required(VERSION 3.14)

set(ProjectName UserCredential)
set(CMAKE_CXX_STANDARD 11)
set(3rdPartyLib cryptlib)

include(FetchContent)

FetchContent_Declare(
    ${3rdPartyLib}
    GIT_REPOSITORY git@github.com:weidai11/cryptopp.git
    GIT_TAG CRYPTOPP_5_6_5
    GIT_PROGRESS TRUE
    )
Set(FETCHCONTENT_QUIET FALSE)

message("this is going to populate the ${3rdPartyLib}")

FetchContent_MakeAvailable(${3rdPartyLib})

message("the current list dir is : " ${CMAKE_CURRENT_LIST_DIR})
message("the current bin dir is : " ${CMAKE_BINARY_DIR})

add_subdirectory(${CMAKE_BINARY_DIR}/_deps/cryptlib-src/)
include_directories(${CMAKE_CURRENT_LIST_DIR}/build/_deps/cryptlib-src/)
add_definitions(-DCRYPTOPP_CXX11_LAMBDA)

project(${ProjectName} LANGUAGES CXX VERSION 1.0.0)
set(CMAKE_CXX_FLAGS "-pthread")
add_executable(${ProjectName} main.cpp)
target_link_libraries(${ProjectName} ${3rdPartyLib})

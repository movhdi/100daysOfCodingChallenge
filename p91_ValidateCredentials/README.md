## Build instruction
Firstly, Run the file run.sh

The result is unsuccessful, do not panic it is ok because the goal is to clone cryptopp library. The cryptopp library will be cloned in the build directory under _deps. After that you will need to replace the CMakeLists.txt file in the cryptopp lib with the following CMakeLists.txt.

```cmake
cmake_minimum_required (VERSION 3.7.0) 
project(cryptlib)

add_definitions(-DUSE_PRECOMPILED_HEADERS)
add_definitions(-D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)

file(GLOB headers *.h)
file(GLOB sources *.cpp)

add_library (cryptlib STATIC ${headers} ${sources})
```
Now it is time to do some changes in the root CMakeLists.txt file, you need to comment all the codes related to fetch content. To be exact, you should comment the following lines.
```cmake
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
```
Here for running the actual build, you need to execute ./run.sh again, but this time with some changes because you do not want to remove build folder, so change the ./run.sh like following.

```bash
#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
# rm -rf $SCRIPT_DIR/build
# mkdir $SCRIPT_DIR/build
cd $SCRIPT_DIR/build
cmake .. 
cmake --build .

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
$SCRIPT_DIR/UserCredential
```

The program prompts for username and password. You can enter `johnsmith` as the username and `Meco@123` as the password.
Enjoy!
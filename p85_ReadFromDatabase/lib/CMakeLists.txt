# adding libraries
add_library(performanceEval)

find_package(Boost REQUIRED COMPONENTS log_setup log system thread filesystem)

target_sources(performanceEval PUBLIC 
                    databasehandler.cpp
                    logging.cpp
                    SystemInit.cpp 
                    dbStatement.cpp)

target_include_directories(performanceEval
            PUBLIC 
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_link_libraries(performanceEval PRIVATE sqlite3)
target_compile_features(performanceEval PUBLIC cxx_std_17)

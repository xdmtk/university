cmake_minimum_required(VERSION 3.7)
project(distance_vector_routing)

set(SOURCE_FILES
        src/main.cpp
        src/shell.cpp
        src/utils.cpp
        src/logger.cpp
        src/server.cpp
        src/client.cpp
        src/signals.cpp
        src/connector.cpp
        src/handler.cpp
        src/topology.cpp
        src/args.cpp
)
include_directories(include)
add_executable(dvr ${SOURCE_FILES})
target_link_libraries(dvr pthread)

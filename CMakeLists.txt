cmake_minimum_required(VERSION 3.9)
project(chat)

set(SOURCE_FILES
        src/main.cpp
        src/shell.cpp
        src/utils.cpp
        src/logger.cpp
        src/server.cpp
        src/client.cpp
        src/signals.cpp
        )
include_directories(include)
add_executable(chat ${SOURCE_FILES})
target_link_libraries(chat pthread)

cmake_minimum_required(VERSION 3.9)
project(hw1)

set(SOURCE_FILES CS465Homework1.cpp glad.c)
include_directories(include)
link_directories(lib)
add_executable(hw1 ${SOURCE_FILES})
target_link_libraries(hw1 glfw3 opengl32)

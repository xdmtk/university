cmake_minimum_required(VERSION 3.9)
project(gl-test)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
set(SOURCE_FILES
        src/glad.c
        src/OpenGlVk.cpp
        )
include_directories(include ${OPENGL_INCLUDE_DIR})
add_executable(gl-test ${SOURCE_FILES})
target_link_libraries(glfw INTERFACE ${OPENGL_gl_LIBRARY})
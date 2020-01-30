cmake_minimum_required(VERSION 3.9)
project(lab0)

include_directories(include)
add_executable(lab0 src/main.c src/parse.c  src/convert.c src/print.c )
cmake_minimum_required(VERSION 3.17)
project(codekata_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(codekata_cpp main.cpp)
add_executable(ptr ptr/main.cpp  ptr/string_wrapper.cpp ptr/string_wrapper.h)
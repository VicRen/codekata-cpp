cmake_minimum_required(VERSION 3.17)
project(codekata_cpp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(codekata_cpp ${SOURCE_FILES})

include_directories(leetcode)
add_subdirectory(leetcode)
include_directories(gof)
add_subdirectory(gof)

target_link_libraries(codekata_cpp LeetCode_lib GoF_lib)

add_subdirectory(Google_tests)

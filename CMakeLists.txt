cmake_minimum_required(VERSION 3.17)
project(codekata_cpp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(codekata_cpp ${SOURCE_FILES})

include_directories(leetcode fsm)
add_subdirectory(leetcode fsm)

target_link_libraries(codekata_cpp LeetCode_lib FSM_lib)

add_subdirectory(Google_tests)

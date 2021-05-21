cmake_minimum_required(VERSION 3.17)
project(codekata_cpp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(codekata_cpp ${SOURCE_FILES})

include_directories(leetcode)
add_subdirectory(leetcode)
include_directories(gof)
add_subdirectory(gof)
include_directories(elegant_callback)
add_subdirectory(elegant_callback)

target_link_libraries(codekata_cpp LeetCode_lib GoF_lib elegant_callback_lib)

# -------------- unit tests -------------

set(
        UT_SOURCE_FILES
        tests/leetcode_test.cpp
)

enable_testing()
# add google tests
include(FetchContent)
FetchContent_Declare(
        gtest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
if (WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif ()
FetchContent_MakeAvailable(gtest)

include_directories(leetcode_test PRIVATE src)
add_executable(leetcode_test ${UT_SOURCE_FILES})
target_link_libraries(
        leetcode_test
        gtest_main
        gmock_main
        LeetCode_lib
)
include(GoogleTest)
gtest_discover_tests(leetcode_test)

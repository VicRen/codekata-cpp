cmake_minimum_required(VERSION 3.17)
project(codekata-cpp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(
        ${PROJECT_NAME}
        ${SOURCE_FILES}
)

# -------------- unit tests -------------
set(
        UT_SOURCE_FILES
        main_test.cpp
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

set(TEST_PROJECT_NAME unit-test-cpp)

include_directories(
        ${TEST_PROJECT_NAME} PRIVATE
        src
)
add_executable(
        ${TEST_PROJECT_NAME}
        ${UT_SOURCE_FILES}
)
target_link_libraries(
        ${TEST_PROJECT_NAME}
        gtest_main
        gmock_main
)
include(GoogleTest)
gtest_discover_tests(${TEST_PROJECT_NAME})

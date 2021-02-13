project(LeetCode_lib)

set(HEADER_FILES
        leetcode.h
        )

set(SOURCE_FILES
        leetcode.cpp
        )

add_library(LeetCode_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
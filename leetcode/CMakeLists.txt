project(LeetCode_lib)

set(HEADER_FILES
        leetcode.h
        fsm.h
        doubly_linked_list.h)

set(SOURCE_FILES
        leetcode.cpp
        )

add_library(LeetCode_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
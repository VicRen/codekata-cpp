project(FSM_lib)

set(HEADER_FILES
        fsmtype.h
        state.h
        )

set(SOURCE_FILES
        )

add_library(FSM_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
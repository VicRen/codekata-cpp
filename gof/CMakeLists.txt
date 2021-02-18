project(GoF_lib)

set(HEADER_FILES
        product.h
        factory.h)

set(SOURCE_FILES
        product.cpp
        factory.cpp)

add_library(GoF_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
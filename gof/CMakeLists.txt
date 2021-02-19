project(GoF_lib)

set(HEADER_FILES
        product.h
        factory.h
        bridge/shape.h
        bridge/circle.h)

set(SOURCE_FILES
        product.cpp
        factory.cpp
        bridge/shape.cpp
        bridge/circle.cpp)

add_library(GoF_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
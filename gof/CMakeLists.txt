project(GoF_lib)

set(HEADER_FILES
        product.h
        factory.h
        bridge/shape.h
        bridge/circle.h
        bridge/square.h
        bridge/color.h
        adapter/adapter.h)

set(SOURCE_FILES
        product.cpp
        factory.cpp
        bridge/shape.cpp
        bridge/circle.cpp
        bridge/square.cpp
        bridge/color.cpp
        adapter/adapter.cpp)

add_library(GoF_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
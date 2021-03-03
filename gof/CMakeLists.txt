project(GoF_lib)

set(HEADER_FILES
        product.h
        factory.h
        bridge/shape.h
        bridge/circle.h
        bridge/square.h
        bridge/color.h
        adapter/adapter.h
        composite/component.h
        composite/composite.h
        composite/leaf.h
        flyweight/flyweight.cpp
        facade/facade.h
        proxy/proxy.h
        template/template.h
        strategy/strategy.h
        state/state.h
        )

set(SOURCE_FILES
        product.cpp
        factory.cpp
        bridge/shape.cpp
        bridge/circle.cpp
        bridge/square.cpp
        bridge/color.cpp
        adapter/adapter.cpp
        composite/component.cpp
        composite/composite.cpp
        composite/leaf.cpp
        flyweight/flyweight.cpp
        facade/facade.cpp
        proxy/proxy.cpp
        template/template.cpp
        strategy/strategy.cpp
        state/state.cpp
        )

add_library(GoF_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
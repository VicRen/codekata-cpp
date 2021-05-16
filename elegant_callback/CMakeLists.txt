project(elegant_callback_lib)


set(
        SOURCE_FILES
        test_interface_impl.cpp
)

add_library(elegant_callback_lib STATIC ${SOURCE_FILES})
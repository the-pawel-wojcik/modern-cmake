cmake_minimum_required(VERSION 3.30)
project(Dependecies LANGUAGES CXX)

add_library(one none.cpp)
# seems like set_target_properties quietly fails
# set_target_properties(one PROPERTIES INTERFACE_LIB_VERSION 4)
set_property(TARGET one PROPERTY INTERFACE_LIB_VERSION 4)
set_property(TARGET one
    APPEND PROPERTY
    COMPATIBLE_INTERFACE_STRING LIB_VERSION
)

add_library(two none.cpp)
# set_target_properties(one PROPERTIES INTERFACE_LIB_VERSION 5)
# set_property(TARGET two PROPERTY INTERFACE_LIB_VERSION 5)
set_property(TARGET two PROPERTY INTERFACE_LIB_VERSION 4)

add_executable(app none.cpp)
target_link_libraries(app PRIVATE one two)

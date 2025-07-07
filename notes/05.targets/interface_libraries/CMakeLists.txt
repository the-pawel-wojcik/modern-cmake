cmake_minimum_required(VERSION 3.30)
project(InterfaceLibraries LANGUAGES CXX)

add_library(warning_properties INTERFACE)
target_compile_options(warning_properties INTERFACE
    -Wall -Wextra -Wpedantic
)

add_executable(app none.cpp)
target_link_libraries(app PRIVATE warning_properties)

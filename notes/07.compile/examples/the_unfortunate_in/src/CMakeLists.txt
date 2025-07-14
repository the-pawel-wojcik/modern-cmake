cmake_minimum_required(VERSION 3.30)
project(MyDefinitions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_define define.cpp)

set(ENABLE_IN_FILES OFF)
set(DISABLE_IN_FILES ON)
set(VARIABLE "my text")
set(NUMBER 20)
configure_file(configure.h.in configured/configure.h)
target_include_directories(my_define PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

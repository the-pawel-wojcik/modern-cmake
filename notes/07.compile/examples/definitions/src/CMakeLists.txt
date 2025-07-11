cmake_minimum_required(VERSION 3.30)
project(MyDefinitions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VAR 9)
add_executable(my_define define.cpp)
target_compile_definitions(my_define PRIVATE VARIABLE "NUMBER=${VAR}")

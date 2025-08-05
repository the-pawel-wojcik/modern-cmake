cmake_minimum_required(VERSION 4.0.3)
project(one_definition_rule LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
add_executable(odr one.cpp two.cpp)

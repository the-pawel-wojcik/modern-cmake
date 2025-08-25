cmake_minimum_required(VERSION 3.25)
project(GTestTest LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(CTest)
add_subdirectory(src bin)
add_subdirectory(test)

cmake_minimum_required(VERSION 3.25)
project(TestingWithGMock LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(CTest)
add_subdirectory(src bin)
add_subdirectory(test)

cmake_minimum_required(VERSION 3.25)
project(NoFrameworkTest LANGUAGES CXX)

include(CTest)
add_subdirectory(src bin)
add_subdirectory(test)

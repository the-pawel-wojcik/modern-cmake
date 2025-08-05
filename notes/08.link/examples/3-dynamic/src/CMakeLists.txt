cmake_minimum_required(VERSION 4.0.3)
project(duplicated_symbols LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_library(a SHARED one.cpp)
add_library(b SHARED two.cpp)

add_executable(main_ab main.cpp)
target_link_libraries(main_ab a b)

add_executable(main_ba main.cpp)
target_link_libraries(main_ba b a)

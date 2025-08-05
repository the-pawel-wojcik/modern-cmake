cmake_minimum_required(VERSION 4.0.3)
project(unresolved LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_library(outer outer.cpp)
add_library(nested nested.cpp)
add_executable(main main.cpp)
# target_link_libraries(main nested outer)  # fails
target_link_libraries(main outer nested)

cmake_minimum_required(VERSION 3.30)
project(CompileIntermediates LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(debug vec.cpp)
target_compile_options(debug PRIVATE -save-temps=obj)

cmake_minimum_required(VERSION 3.30)
project(precompiled_headers LANGUAGES CXX)

add_executable(main main.cpp)
target_precompile_headers(main PRIVATE <iostream>)

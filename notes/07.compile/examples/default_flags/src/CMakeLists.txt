cmake_minimum_required(VERSION 3.30)
project(test LANGUAGES CXX)

message("CMAKE_CXX_FLAGS_DEBUG=${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE=${CMAKE_CXX_FLAGS_RELEASE}")

add_executable(asserted asserted.cpp)

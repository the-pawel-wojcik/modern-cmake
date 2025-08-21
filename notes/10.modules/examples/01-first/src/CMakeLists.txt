cmake_minimum_required(VERSION 4.0.3)
project(CXXModules LANGUAGES CXX)

set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(math)
target_sources(math
    PUBLIC FILE_SET CXX_MODULES FILES math.cxx
)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE math)

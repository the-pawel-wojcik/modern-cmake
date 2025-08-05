cmake_minimum_required(VERSION 4.0.3)
project(FindingZlib LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${FindingZlib_SOURCE_DIR}/cmake/module")
find_package(zlib REQUIRED)
add_executable(main main.cpp)

# classic approach
# target_link_libraries(main PRIVATE ${zlib_LIBRARIES})
# target_include_directories(main PRIVATE ${zlib_INCLUDE_DIRS})

# modernized
target_link_libraries(main PRIVATE zlib::zlib)

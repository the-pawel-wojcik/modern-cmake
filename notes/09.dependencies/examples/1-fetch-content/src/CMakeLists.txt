cmake_minimum_required(VERSION 4.0)
project(fetch-content-yaml LANGUAGES CXX)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "")

add_executable(welcome main.cpp)
configure_file(config.yaml config.yaml COPYONLY)
include(FetchContent)
FetchContent_Declare(external-yaml-cpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
    GIT_TAG 0.8.0
)
FetchContent_MakeAvailable(external-yaml-cpp)
target_link_libraries(welcome PRIVATE yaml-cpp::yaml-cpp)

include(CMakePrintHelpers)
cmake_print_properties(
    TARGETS yaml-cpp::yaml-cpp
    PROPERTIES TYPE SOURCE_DIR
)

cmake_minimum_required(VERSION 3.30)
project(StandardizedProject LANGUAGES CXX)

if(PROJECT_BINARY_DIR STREQUAL PROJECT_SOURCE_DIR)
  message(
    FATAL_ERROR
      "In-source build is disabled.\nUse `cmake -S <source> -B <build>`.")
else()
  message(STATUS "Out-of-source build")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

try_run(
    run_result compile_result
    ${PROJECT_BINARY_DIR}/feature_test
    ${PROJECT_SOURCE_DIR}/feature_test.cpp
    RUN_OUTPUT_VARIABLE output
)

message(STATUS "feature test run result: ${run_result}")
message(STATUS "feature test compile result: ${compile_result}")
message(STATUS "feature test output: ${output}")

include(CheckIPOSupported)
check_ipo_supported(RESULT ipo_supported)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ${ipo_supported})

message(STATUS "c++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "c++ standard requried: ${CMAKE_CXX_STANDARD_REQUIRED}")
message(STATUS "c++ compiler extensions: ${CMAKE_CXX_EXTENSIONS}")
message(
  STATUS "interprocedural optimization: ${CMAKE_INTERPROCEDURAL_OPTIMIZATION}")

add_library(run STATIC calc.cpp run.cpp rng_mt19937.cpp)
target_include_directories(run PUBLIC .)
if (CMAKE_BUILD_TYPE STREQUAL Debug) 
    target_compile_options(run PRIVATE --coverage)
    target_link_options(run PUBLIC --coverage)
    add_custom_command(
        TARGET run PRE_BUILD COMMAND
        find ${CMAKE_BINARY_DIR} -type f 
        -name '*.gcda' -exec rm {} +
    )
endif()

add_executable(bootstrap bootstrap.cpp)
target_link_libraries(bootstrap PRIVATE run)

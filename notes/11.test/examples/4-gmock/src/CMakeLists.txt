add_library(run STATIC calc.cpp run.cpp rng_mt19937.cpp)
target_include_directories(run PUBLIC .)

add_executable(bootstrap bootstrap.cpp)
target_link_libraries(bootstrap PRIVATE run)

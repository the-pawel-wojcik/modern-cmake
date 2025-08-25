add_library(run STATIC run.cpp calc.cpp)
target_include_directories(run PUBLIC .)
add_executable(bootstrap bootstrap.cpp)
target_link_libraries(bootstrap run)

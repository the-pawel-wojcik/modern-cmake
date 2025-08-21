cmake_minimum_required(VERSION 3.25)
add_executable(
    unit_tests
    unit_tests.cpp
    calc_tests.cpp
    run_test.cpp
)
target_link_libraries(unit_tests PRIVATE run)
target_include_directories(unit_tests PRIVATE ../src)
add_test(NAME test_add COMMAND unit_tests 1)
add_test(NAME test_times COMMAND unit_tests 2)
set_tests_properties(test_times PROPERTIES WILL_FAIL ON)
add_test(NAME test_run COMMAND unit_tests 3)

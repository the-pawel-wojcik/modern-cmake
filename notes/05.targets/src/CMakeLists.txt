cmake_minimum_required(VERSION 3.30)
project(Targets LANGUAGES CXX)

add_executable(gui gui.cpp)
add_executable(tui tui.cpp)
target_link_libraries(gui calc draw)
target_link_libraries(tui calc)

add_library(calc calc.cpp)
add_library(draw draw.cpp)

add_custom_target(checksum ALL
    COMMAND sh -c "cksum gui >gui.ck"
    COMMAND sh -c "cksum tui >tui.ck"
    BYPRODUCTS tui.ck gui.ck
    COMMENT "Checking the sums"
)
add_dependencies(checksum gui tui)

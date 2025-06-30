cmake_minimum_required(VERSION 3.30)
project(Physics
    VERSION 0.1.0
    DESCRIPTION "A computer simulation of the physical world."
    HOMEPAGE_URL "www.the-internet.com"
    LANGUAGES CXX
)


add_subdirectory(solvers)
add_executable(Physics main.cpp)
target_link_libraries(Physics PRIVATE hamiltonian)

cmake_minimum_required(VERSION 3.30)
project(Solvers
    VERSION 0.1.0
    DESCRIPTION "Solvers of the physics equations."
    LANGUAGES CXX
)

add_library(hamiltonian OBJECT hamiltonian.cpp)
target_include_directories(hamiltonian PUBLIC .)

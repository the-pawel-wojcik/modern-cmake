cmake_minimum_required(VERSION 3.30)
# run this scritp with `cmake -P <script name>`
message("Hello world!")
file(WRITE hw.cpp [[#include <iostream>

int main() {
    std::cout << "Hello world!" << std::endl;
}]])

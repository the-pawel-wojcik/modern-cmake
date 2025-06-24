cmake_minimum_required(VERSION 3.5)  # sets CMP0010
set(regular_variable 3.1415)
set("white spaced name" allowed)
set("new-line
in-the-name" still-good)
message(${regular_variable})
message(${white\ spaced\ name})
message(${new-line\nin-the-name})

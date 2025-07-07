cmake_minimum_required(VERSION 3.30)
project(TargetHook LANGUAGES CXX)

add_executable(main main.cpp)

add_custom_command(
    TARGET main POST_BUILD
    COMMAND cksum
    ARGS "$<TARGET_FILE:main>" > "main.ck"
)

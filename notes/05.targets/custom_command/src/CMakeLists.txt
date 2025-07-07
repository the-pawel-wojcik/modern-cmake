cmake_minimum_required(VERSION 3.30)
project(CustomCommand LANGAUGES CXX)

add_custom_command(
    OUTPUT person.pb.h person.pb.cc
    COMMAND protoc ARGS person.proto
    DEPENDS person.proto
)

add_executable(serializer serializer.cpp person.pb.cc)

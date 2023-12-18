cmake_minimum_required(VERSION 3.5)
project(protobuf)
set(CMAKE_BUILD_TYPE Release)

find_package(Protobuf REQUIRED)
message(STATUS "Protobuf ${PROTOBUF_INCLUDE_DIRS}")
include_directories(proto)

add_executable(main main.cpp proto/bbox.pb.cc)
target_link_libraries(main ${PROTOBUF_LIBRARIES})
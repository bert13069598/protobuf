cmake_minimum_required(VERSION 3.5)
project(protobuf)
set(CMAKE_BUILD_TYPE Release)

find_package(Protobuf REQUIRED)
message(STATUS "Protobuf ${PROTOBUF_INCLUDE_DIRS}")
include_directories(proto)

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS proto/bbox.proto)
message(STATUS "PROTO_SRCS                  ${PROTO_SRCS}")
message(STATUS "PROTO_HDRS                  ${PROTO_HDRS}")
add_executable(main main.cpp ${PROTO_SRCS})
target_link_libraries(main ${PROTOBUF_LIBRARIES})
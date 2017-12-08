cmake_minimum_required(VERSION 2.6)
project(demo)

# compile proto files
set(PROTO_IN  ${CMAKE_SOURCE_DIR}/pbb/news.proto)
set(PROTO_SRC ${CMAKE_SOURCE_DIR}/pbb/news.pb.cc)
set(PROTO_OUT ${CMAKE_SOURCE_DIR}/pbb/news.pb.h ${CMAKE_SOURCE_DIR}/pbb/news.pb.cc)

add_custom_command(
    OUTPUT ${PROTO_OUT}
    COMMAND protoc -I=${CMAKE_SOURCE_DIR}/pbb --cpp_out=${CMAKE_SOURCE_DIR}/pbb  ${PROTO_IN}
    DEPENDS ${PROTO_IN}
)
add_custom_target(proto DEPENDS ${PROTO_OUT})

find_package(Protobuf REQUIRED)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_VERBOSE_MAKEFILE on)

include_directories(${CMAKE_SOURCE_DIR})
add_library(demolib
  ${CMAKE_SOURCE_DIR}/pbb/news.pb.cc
)

add_executable(demo demo.cpp)
add_dependencies(demo proto)
target_link_libraries(demo demolib)
target_link_libraries(demo protobuf)

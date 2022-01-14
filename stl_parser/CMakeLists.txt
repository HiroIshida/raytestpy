cmake_minimum_required(VERSION 2.6)

SET(EXTRA_CXX_COMPILE_FLAGS "-std=c++11 -pedantic -Werror -Wall")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${EXTRA_CXX_COMPILE_FLAGS}")
add_library(stl_parser STATIC parse_stl.cpp)
include_directories(stl_parser)

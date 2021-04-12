cmake_minimum_required(VERSION 3.19)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

set(GCC_OPTIMIZE_SIZE "-Os")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_OPTIMIZE_SIZE}" )

add_executable(Chess Driver.cpp)
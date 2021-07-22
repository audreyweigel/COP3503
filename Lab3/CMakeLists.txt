cmake_minimum_required(VERSION 3.19)
project(Lab3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lab3 cmake-build-debug/main.cpp cmake-build-debug/leaker.cpp cmake-build-debug/leaker.h cmake-build-debug/ABQ.h)
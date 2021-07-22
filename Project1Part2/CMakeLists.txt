cmake_minimum_required(VERSION 3.19)
project(Project1Part2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project1Part2 cmake-build-debug/main.cpp cmake-build-debug/LinkedList.h cmake-build-debug/leaker.cpp cmake-build-debug/leaker.h)
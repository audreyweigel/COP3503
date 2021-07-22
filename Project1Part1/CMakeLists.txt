cmake_minimum_required(VERSION 3.19)
project(Project1Part1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project1Part1 cmake-build-debug/main.cpp cmake-build-debug/leaker.cpp cmake-build-debug/leaker.h cmake-build-debug/LinkedList.h)
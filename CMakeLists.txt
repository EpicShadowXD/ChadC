cmake_minimum_required(VERSION 3.26)
project(chadc_v2)

set(CMAKE_CXX_STANDARD 23)

add_executable(chadc_v2 main.cpp
        compiler.cpp
        compiler.h)

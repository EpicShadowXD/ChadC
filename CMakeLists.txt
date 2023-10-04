cmake_minimum_required(VERSION 3.26)
project(chad_compiler)

set(CMAKE_CXX_STANDARD 23)

add_executable(chad_compiler main.cpp
        tokenizer.hpp
        tokenizer_backup.h
        tokenizer.h
        grammar.h
)

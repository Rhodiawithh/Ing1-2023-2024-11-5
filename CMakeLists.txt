cmake_minimum_required(VERSION 3.26)
project(TetS C)

set(CMAKE_C_STANDARD 23)

add_executable(TetS main.c
        SP.c
        SP.h)

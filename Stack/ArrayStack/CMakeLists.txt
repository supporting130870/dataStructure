cmake_minimum_required(VERSION 3.28)
project(ArrayStack C)

set(CMAKE_C_STANDARD 11)

add_executable(ArrayStack Test_ArrayStack.c
        ArrayStack.c
        ArrayStack.h)

cmake_minimum_required(VERSION 3.28)
project(Calculator C)

set(CMAKE_C_STANDARD 11)

add_executable(Calculator main.c
        Calculator.c
        Calculator.h
        LinkedListStack.c)

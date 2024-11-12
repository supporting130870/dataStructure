cmake_minimum_required(VERSION 3.28)
project(LinkedListStack C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkedListStack main.c
        LinkedListStack.c
        LinkedListStack.h)

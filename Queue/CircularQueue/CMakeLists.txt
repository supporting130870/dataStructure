cmake_minimum_required(VERSION 3.28)
project(CircularQueue C)

set(CMAKE_C_STANDARD 11)

add_executable(CircularQueue Test_CircularQueue.c
        CircularQueue.c
        CircularQueue.h)

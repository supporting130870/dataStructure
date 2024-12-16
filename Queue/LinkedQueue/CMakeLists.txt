cmake_minimum_required(VERSION 3.28)
project(LinkedQueue C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkedQueue Test_LinkedQueue.c
        LinkedQueue.c
        LinkedQueue.h)

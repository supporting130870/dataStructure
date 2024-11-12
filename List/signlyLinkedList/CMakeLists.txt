cmake_minimum_required(VERSION 3.28)
project(signlyLinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(signlyLinkedList Test_LinkedList.c
        LinkedList.h
        LinkedList.c)

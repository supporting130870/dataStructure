cmake_minimum_required(VERSION 3.28)
project(CircularDoublyLinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(CircularDoublyLinkedList Test_CircularDoublyLinkedList.c
        CircularDoublyLinkedList.c
        CircularDoublyLinkedList.h)

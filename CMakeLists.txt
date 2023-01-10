cmake_minimum_required(VERSION 3.23)
project(C_LIBARY C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C_LIBARY
        LinearLinkedList.h
        CircularLinearLinkedList
        )

cmake_minimum_required(VERSION 3.23)
project(C_LIBARY C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C_LIBARY
        definesLib.h
        functions.h
        LinearLinkedList.h
        LinearLinkedList.c
        main.c
        matrix.h
        stringL.h
        TicTacToeArrayV.c)

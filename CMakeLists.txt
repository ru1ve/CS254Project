cmake_minimum_required(VERSION 3.27)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 mainTest.c
        student.c
        student.h
        node.h
        node.c
        list.c
        list.h
        utils.h
        utils.c
        utils.c
        main.c
)

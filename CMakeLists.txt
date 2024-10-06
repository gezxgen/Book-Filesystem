cmake_minimum_required(VERSION 3.28)
project(books C)

set(CMAKE_C_STANDARD 11)

add_executable(books main.c
        buchfunktionen.c
        buchfunktionen.h)

cmake_minimum_required(VERSION 3.28)
project(mos6502 C)

set(CMAKE_C_STANDARD 99)

add_library(mos6502 STATIC library.c
        main.c)

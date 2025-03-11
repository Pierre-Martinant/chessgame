cmake_minimum_required(VERSION 3.30)
project(Project C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet main.c
        board.c
        piece.c
        board.h
        piece.h)

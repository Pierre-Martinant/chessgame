cmake_minimum_required(VERSION 3.30)
project(Project C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet main.c
        board.c
        piece.c
        knight.c
        King.c
        Echec.c
        EchecetMat.c
        Bishop.c
        pawn.c
        Queen.c
        Rook.c
        board.h
        piece.h
        knight.h
        King.h
        Bishop.h
        pawn.h
        Queen.h
        Rook.h
        Echec.h
        EchecetMat.h


)

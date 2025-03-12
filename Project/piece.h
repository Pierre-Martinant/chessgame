//
// Created by jeanm on 24/01/2025.
//

#ifndef PIECE_H
#define PIECE_H

#include <stdbool.h>


typedef enum {
    EMPTY,
    WHITE_PAWN,
    WHITE_KING,
    WHITE_QUEEN,
    WHITE_BISHOP,
    WHITE_KNIGHT,
    WHITE_ROOK,

    BLACK_PAWN,
    BLACK_KING,
    BLACK_QUEEN,
    BLACK_BISHOP,
    BLACK_KNIGHT,
    BLACK_ROOK,
} Piece;
char pieceToString(Piece piece);
bool canAttack(Piece** board[8][8], int fromX, int fromY, int toX, int toY);
bool isInsideBoard(int x, int y);


#endif //PIECE_H

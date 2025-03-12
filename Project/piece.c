//
// Created by cavyh on 11/03/2025.
//

#include "piece.h"
#include <stdbool.h>
#include <stdlib.h>

// Function to get a character representation of a piece
char pieceToString(Piece piece) {
    switch (piece) {
        case WHITE_PAWN:
            return 'p';
        case WHITE_KING:
            return 'k';
        case WHITE_QUEEN:
            return 'q';
        case WHITE_BISHOP:
            return 'b';
        case WHITE_KNIGHT:
            return 'n';
        case WHITE_ROOK:
            return 'r';
        case BLACK_PAWN:
            return 'P';
        case BLACK_KING:
            return 'K';
        case BLACK_QUEEN:
            return 'Q';
        case BLACK_BISHOP:
            return 'B';
        case BLACK_KNIGHT:
            return 'N';
        case BLACK_ROOK:
            return 'R';
        case EMPTY:
            default:
                return '.';
    }
}

// Checks if a position is within the board limits
bool isInsideBoard(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
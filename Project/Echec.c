//
// Created by cavyh on 07/03/2025.
//
#include <stdbool.h>
#include "piece.h"

bool isInCheck(Piece** board[8][8], char kingColor) {
    int kingX = -1, kingY = -1;

    // Locate the king on the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].type == 'K' && board[i][j].color == kingColor) {
                kingX = i;
                kingY = j;
                break;
            }
        }
    }

    // If the king is not found, return false
    if (kingX == -1 || kingY == -1) {
        return false;
    }

    // Check if any opposing piece can attack the king
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].color != kingColor && board[i][j].color != ' ') {
                if ((board, i, j, kingX, kingY)) {
                    return true;
                }
            }
        }
    }

    return false;
}

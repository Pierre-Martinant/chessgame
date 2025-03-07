//
// Created by cavyh on 07/03/2025.
//
#include <stdbool.h>

#define SIZE 8

bool isInCheck(Piece board[SIZE][SIZE], char kingColor) {
    int kingX = -1, kingY = -1;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].type == 'K' && board[i][j].color == kingColor) {
                kingX = i;
                kingY = j;
                break;
            }
        }
    }

    if (kingX == -1 || kingY == -1) {
        return false;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].color != kingColor && board[i][j].color != ' ') {
                if (canAttack(board, i, j, kingX, kingY)) {
                    return true;
                }
            }
        }
    }

    return false;
}

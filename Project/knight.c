//
// Created by cavyh on 11/03/2025.
//

#include "knight.h"
#include <stdio.h>

// Déplacements possibles du cavalier
int knightMoves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// Vérifie si une position est valide sur l'échiquier
bool isValidMove(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

// Vérifie si un déplacement du cavalier est valide
bool isKnightMoveValid(int startX, int startY, int endX, int endY) {
    for (int i = 0; i < 8; i++) {
        if (startX + knightMoves[i][0] == endX && startY + knightMoves[i][1] == endY) {
            return true;
        }
    }
    return false;
}

// Affiche tous les déplacements possibles du cavalier depuis une position donnée
void printPossibleMoves(int startX, int startY) {
    printf("Déplacements possibles depuis (%d, %d):\n", startX, startY);
    for (int i = 0; i < 8; i++) {
        int newX = startX + knightMoves[i][0];
        int newY = startY + knightMoves[i][1];
        if (isValidMove(newX, newY)) {
            printf("(%d, %d)\n", newX, newY);
        }
    }
}

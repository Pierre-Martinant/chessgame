//
// Created by cavyh on 02/03/2025.
//
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

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

int main() {
    int startX, startY, endX, endY;

    printf("Entrez la position de départ du cavalier (x y) : ");
    scanf("%d %d", &startX, &startY);

    if (!isValidMove(startX, startY)) {
        printf("Position de départ invalide !\n");
        return 1;
    }

    printPossibleMoves(startX, startY);

    printf("\nEntrez la position de destination (x y) : ");
    scanf("%d %d", &endX, &endY);

    if (!isValidMove(endX, endY)) {
        printf("Position de destination invalide !\n");
        return 1;
    }

    if (isKnightMoveValid(startX, startY, endX, endY)) {
        printf("Le déplacement est valide !\n");
    } else {
        printf("Le déplacement est invalide !\n");
    }

    return 0;
}

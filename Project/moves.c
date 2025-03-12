//
// Created by there on 12/03/2025.
//

#include "moves.h"
#include <stdio.h>
#include <stdlib.h>

//BISHOP

// Implementation of the bishopMove function
bool bishopMove(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (dx == dy);
}

//KING

// Implementation of the kingMove function
bool kingMove(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (dx <= 1 && dy <= 1);
}

//KNIGHT

// Possible knight moves
int knightMoves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// Check if a position is valid on the chessboard
bool isValidMove(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// Check if a knight's move is valid
bool isKnightMoveValid(int startX, int startY, int endX, int endY) {
    for (int i = 0; i < 8; i++) {
        if (startX + knightMoves[i][0] == endX && startY + knightMoves[i][1] == endY) {
            return true;
        }
    }
    return false;
}

// Display all possible knight moves from a given position
void printPossibleMoves(int startX, int startY) {
    printf("Possible moves from (%d, %d):\n", startX, startY);
    for (int i = 0; i < 8; i++) {
        int newX = startX + knightMoves[i][0];
        int newY = startY + knightMoves[i][1];
        if (isValidMove(newX, newY)) {
            printf("(%d, %d)\n", newX, newY);
        }
    }
}

//PAWN

// Implementation of the pawnMove function
bool pawnMove(int x1, int y1, int x2, int y2, bool firstMove) {
    int dy = y2 - y1;
    int dx = abs(x2 - x1);

    // The pawn moves one square forward or two squares if it's its first move
    if (dx == 0 && ((dy == 1) || (firstMove && dy == 2))) {
        return true;
    }

    // The pawn captures diagonally by one square
    if (dx == 1 && dy == 1) {
        return true;
    }

    return false;
}

//QUEEN

// Implementation of the queenMove function
bool queenMove(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (x1 == x2 || y1 == y2 || dx == dy); // Queen can move horizontally, vertically, or diagonally
}

//ROOK

// Implementation of the rookMove function
bool rookMove(int x1, int y1, int x2, int y2) {
    return (x1 == x2 || y1 == y2); // Rook can move either horizontally or vertically
}
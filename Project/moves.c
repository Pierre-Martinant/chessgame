#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a position is within the chessboard bounds
bool isValidMove(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// BISHOP MOVEMENT
bool bishopMove(int x1, int y1, int x2, int y2) {
    if (!isValidMove(x1, y1) || !isValidMove(x2, y2)) return false;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (dx == dy); // Bishop moves diagonally
}

// KING MOVEMENT
bool kingMove(int x1, int y1, int x2, int y2) {
    if (!isValidMove(x1, y1) || !isValidMove(x2, y2)) return false;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (dx <= 1 && dy <= 1); // King moves one square in any direction
}

// KNIGHT MOVEMENT
int knightMoves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

bool isKnightMoveValid(int startX, int startY, int endX, int endY) {
    if (!isValidMove(startX, startY) || !isValidMove(endX, endY)) return false;

    for (int i = 0; i < 8; i++) {
        if (startX + knightMoves[i][0] == endX && startY + knightMoves[i][1] == endY) {
            return true;
        }
    }
    return false;
}

// PAWN MOVEMENT
bool pawnMove(int x1, int y1, int x2, int y2, bool firstMove) {
    if (!isValidMove(x1, y1) || !isValidMove(x2, y2)) return false;

    int dy = y2 - y1;
    int dx = abs(x2 - x1);

    // Pawn moves forward one square or two squares if it's the first move
    if (dx == 0 && ((dy == 1) || (firstMove && dy == 2))) {
        return true;
    }

    // Pawn captures diagonally by one square
    if (dx == 1 && dy == 1) {
        return true;
    }

    return false;
}

// QUEEN MOVEMENT
bool queenMove(int x1, int y1, int x2, int y2) {
    if (!isValidMove(x1, y1) || !isValidMove(x2, y2)) return false;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (x1 == x2 || y1 == y2 || dx == dy); // Queen can move like a rook or bishop
}

// ROOK MOVEMENT
bool rookMove(int x1, int y1, int x2, int y2) {
    if (!isValidMove(x1, y1) || !isValidMove(x2, y2)) return false;

    return (x1 == x2 || y1 == y2); // Rook moves vertically or horizontally
}

// FUNCTION TO PRINT ALL VALID KNIGHT MOVES FROM A GIVEN POSITION
void printKnightMoves(int startX, int startY) {
    if (!isValidMove(startX, startY)) {
        printf("Invalid starting position: (%d, %d)\n", startX, startY);
        return;
    }

    printf("Possible moves from (%d, %d):\n", startX, startY);
    for (int i = 0; i < 8; i++) {
        int newX = startX + knightMoves[i][0];
        int newY = startY + knightMoves[i][1];
        if (isValidMove(newX, newY)) {
            printf("(%d, %d)\n", newX, newY);
        }
    }
}
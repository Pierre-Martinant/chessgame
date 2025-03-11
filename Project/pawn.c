//
// Created by cavyh on 11/03/2025.
//

#include "pawn.h"
#include <stdlib.h>

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

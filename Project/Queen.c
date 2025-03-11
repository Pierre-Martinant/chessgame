//
// Created by cavyh on 11/03/2025.
//

#include "Queen.h"
#include <stdlib.h>

// Implementation of the queenMove function
bool queenMove(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (x1 == x2 || y1 == y2 || dx == dy); // Queen can move horizontally, vertically, or diagonally
}

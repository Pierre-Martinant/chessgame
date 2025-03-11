//
// Created by cavyh on 11/03/2025.
//

#include "Rook.h"

// Implementation of the rookMove function
bool rookMove(int x1, int y1, int x2, int y2) {
    return (x1 == x2 || y1 == y2); // Rook can move either horizontally or vertically
}

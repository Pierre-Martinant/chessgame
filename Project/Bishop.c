//
// Created by cavyh on 11/03/2025.
//

#include "bishop.h"
#include <stdlib.h>

// Implémentation de la fonction bishopMove
bool bishopMove(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (dx == dy);
}

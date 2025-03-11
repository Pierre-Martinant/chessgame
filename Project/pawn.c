//
// Created by cavyh on 11/03/2025.
//

#include "pawn.h"
#include <stdlib.h>

// Implémentation de la fonction pawnMove
bool pawnMove(int x1, int y1, int x2, int y2, bool firstMove) {
    int dy = y2 - y1;
    int dx = abs(x2 - x1);

    // Le pion avance d'une case vers l'avant ou deux cases si c'est son premier coup
    if (dx == 0 && ((dy == 1) || (firstMove && dy == 2))) {
        return true;
    }

    // Le pion capture en diagonale d'une case
    if (dx == 1 && dy == 1) {
        return true;
    }

    return false;
}

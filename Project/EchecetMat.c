//
// Created by cavyh on 07/03/2025.
//

#include <stdbool.h>
#include "piece.h"
#include "Echec.h"

bool checkmate(Piece** board, char kingColor) {
    // Check if the king is in check
    if (!isInCheck(board, kingColor)) {
        return false; // Not in check, so not checkmate
    }

    // Check if there is a legal move to escape the check
    if (legalmoovpossible(board, kingColor)) {
        return false; // A legal move exists, so not checkmate
    }

    // No legal moves and the king is in check -> checkmate
    return true;
}

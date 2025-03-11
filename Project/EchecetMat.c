//
// Created by cavyh on 07/03/2025.
//

#include <stdbool.h>
#include "piece.h"
#include "Echec.h"


bool checkmate(Piece** board, char kingColor) {
    // Vérifier si le roi est en échec
    if (!isInCheck(board, kingColor)) {
        return false; // Pas d'échec, donc pas d'échec et mat
    }

    // Vérifier s'il existe un mouvement légal pour sortir de l'échec
    if (legalmoovpossible(board, kingColor)) {
        return false; // Un mouvement légal existe, donc pas d'échec et mat
    }

    // Aucun mouvement légal et le roi est en échec -> échec et mat
    return true;
}

//
// Created by cavyh on 07/03/2025.
//

#include <stdbool.h>

#define SIZE 8

bool estEchecEtMat(Piece board[SIZE][SIZE], char kingColor) {
    // Vérifier si le roi est en échec
    if (!estEnEchec(board, kingColor)) {
        return false; // Pas d'échec, donc pas d'échec et mat
    }

    // Vérifier s'il existe un mouvement légal pour sortir de l'échec
    if (mouvementLegalPossible(board, kingColor)) {
        return false; // Un mouvement légal existe, donc pas d'échec et mat
    }

    // Aucun mouvement légal et le roi est en échec -> échec et mat
    return true;
}

#include "piece.h"


bool isInCheck(Piece board[8][8], char kingColor) {
    int kingX = -1, kingY = -1;

    // Localiser la position du roi
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((kingColor == 'W' && board[i][j] == WHITE_KING) ||
                (kingColor == 'B' && board[i][j] == BLACK_KING)) {
                kingX = i;
                kingY = j;
                break; // Le roi est trouvé
                }
        }
        if (kingX != -1) break; // Sortir pour éviter une double vérification inutile
    }

    // Si le roi n'a pas été trouvé
    if (kingX == -1 || kingY == -1) {
        return false; // Roi introuvable — aucune "Échec" détectée
    }

    // Vérifier si une pièce adverse attaque le roi
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != EMPTY) { // Si la case contient une pièce
                if (isAttacking(board, i, j, kingX, kingY)) {
                    return true; // Pièce adverse attaque le roi
                }
            }
        }
    }

    return false; // Pas de pièces qui attaquent le roi
}
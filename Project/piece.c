#include "piece.h"
#include <stdbool.h>
#include <stdlib.h>

char pieceToString(Piece piece) {
    switch (piece) {
        case WHITE_PAWN:
            return 'p';
        case WHITE_KING:
            return 'k';
        case WHITE_QUEEN:
            return 'q';
        case WHITE_BISHOP:
            return 'b';
        case WHITE_KNIGHT:
            return 'n';
        case WHITE_ROOK:
            return 'r';
        case BLACK_PAWN:
            return 'P';
        case BLACK_KING:
            return 'K';
        case BLACK_QUEEN:
            return 'Q';
        case BLACK_BISHOP:
            return 'B';
        case BLACK_KNIGHT:
            return 'N';
        case BLACK_ROOK:
            return 'R';
        case EMPTY:
            default:
                return '.';
    }
}

// Vérifie si une case est dans les limites du plateau
bool isInsideBoard(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// Fonction pour vérifier si une pièce peut attaquer une autre
bool canAttack(Piece** board[8][8], int fromX, int fromY, int toX, int toY) {
    Piece** piece = board[fromX][fromY];

    switch (piece.type) {
        case 'K': // Roi
            return (abs(fromX - toX) <= 1 && abs(fromY - toY) <= 1);

        case 'Q': // Reine
            if (fromX == toX || fromY == toY) { // Mouvement horizontal ou vertical
                for (int i = 1; i < abs(fromX - toX) || i < abs(fromY - toY); i++) {
                    if (board[fromX + i * ((toX - fromX) > 0 ? 1 : -1)][fromY + i * ((toY - fromY) > 0 ? 1 : -1)].type != ' ') {
                        return false;
                    }
                }
                return true;
            } else if (abs(fromX - toX) == abs(fromY - toY)) { // Diagonale
                for (int i = 1; i < abs(fromX - toX); i++) {
                    if (board[fromX + i * ((toX - fromX) > 0 ? 1 : -1)][fromY + i * ((toY - fromY) > 0 ? 1 : -1)].type != ' ') {
                        return false;
                    }
                }
                return true;
            }
            break;

        case 'R': // Tour
            if (fromX == toX) { // Mouvement vertical
                for (int i = 1; i < abs(fromY - toY); i++) {
                    if (board[fromX][fromY + i * ((toY - fromY) > 0 ? 1 : -1)].type != ' ') {
                        return false;
                    }
                }
                return true;
            } else if (fromY == toY) { // Mouvement horizontal
                for (int i = 1; i < abs(fromX - toX); i++) {
                    if (board[fromX + i * ((toX - fromX) > 0 ? 1 : -1)][fromY].type != ' ') {
                        return false;
                    }
                }
                return true;
            }
            break;

        case 'B': // Fou
            if (abs(fromX - toX) == abs(fromY - toY)) { // Diagonale
                for (int i = 1; i < abs(fromX - toX); i++) {
                    if (board[fromX + i * ((toX - fromX) > 0 ? 1 : -1)][fromY + i * ((toY - fromY) > 0 ? 1 : -1)].type != ' ') {
                        return false;
                    }
                }
                return true;
            }
            break;

        case 'N': // Cavalier
            if ((abs(fromX - toX) == 2 && abs(fromY - toY) == 1) || (abs(fromX - toX) == 1 && abs(fromY - toY) == 2)) {
                return true;
            }
            break;

        case 'P': // Pion
            // Les pions attaquent en diagonale d'une case devant eux
            if (piece.color == 'w' && fromX - toX == 1 && abs(fromY - toY) == 1) {
                return true;
            }
            if (piece.color == 'b' && toX - fromX == 1 && abs(fromY - toY) == 1) {
                return true;
            }
            break;

        default:
            return false; // Cas non pris en charge
    }

    return false;
}
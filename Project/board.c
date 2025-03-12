//
// Created by jeanm on 24/01/2025.
//
#include "board.h"
#include "piece.h"
#include "Echec.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void deleteBoard(Piece **board) {
    // Free all row before board
    for (int y = 0; y < 8; y++) {
        free(board[y]);
        board[y] = NULL;
    }
    free(board);
    board = NULL;
}

void placePiece(Piece **board, Column x, int y, Piece piece) {
    board[x - 1][y - 1] = piece;
}

char columnToString(Column column) {
    switch (column) {
        case A:
            return 'a';
        case B:
            return 'b';
        case C:
            return 'c';
        case D:
            return 'd';
        case E:
            return 'e';
        case F:
            return 'f';
        case G:
            return 'g';
        case H:
            return 'h';
        default:
            return '.';
    }
}


void displayBoard(Piece **board) {
    printf("  +---+---+---+---+---+---+---+---+\n");

    for (int i = 7; i >= 0; i--) {
        printf("%d |", i + 1);

        for (int j = 0; j < 8; j++) {
            printf(" %c |", pieceToString(board[j][i]));
        }

        printf("\n  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    A   B   C   D   E   F   G   H\n");
}

void resetBoardPiece(Piece **board) {
    // Just placing at right position all pieces
    for (Column i = A; i <= H; i++) {
        placePiece(board, i, 7, BLACK_PAWN);
        placePiece(board, i, 2, WHITE_PAWN);
    }

    placePiece(board, A, 1, WHITE_ROOK);
    placePiece(board, H, 1, WHITE_ROOK);
    placePiece(board, A, 8, BLACK_ROOK);
    placePiece(board, H, 8, BLACK_ROOK);

    placePiece(board, B, 1, WHITE_KNIGHT);
    placePiece(board, G, 1, WHITE_KNIGHT);

    placePiece(board, B, 8, BLACK_KNIGHT);
    placePiece(board, G, 8, BLACK_KNIGHT);

    placePiece(board, C, 8, BLACK_BISHOP);
    placePiece(board, F, 8, BLACK_BISHOP);
    placePiece(board, C, 1, WHITE_BISHOP);
    placePiece(board, F, 1, WHITE_BISHOP);

    placePiece(board, D, 8, BLACK_QUEEN);
    placePiece(board, E, 8, BLACK_KING);
    placePiece(board, D, 1, WHITE_QUEEN);
    placePiece(board, E, 1, WHITE_KING);
}

Piece **generateEmptyBoard() {
    Piece **board = malloc(sizeof(Piece *) * 8);
    for (int i = 0; i < 8; i++) {
        Piece *row = malloc(sizeof(Piece) * 8);
        for (int j = 0; j < 8; j++) {
            row[j] = EMPTY;
        }
        board[i] = row;
    }

    return board;
}

// Vérifie si une position est valide sur l'échiquier (dans les limites)
bool isValidPosition(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

// Vérifie s'il existe un mouvement légal
bool legalmoovpossible(Piece** board, char kingColor) {
    int kingX = -1, kingY = -1;

    // Trouver la position du roi
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((kingColor == 'W' && board[i][j] == WHITE_KING) ||
                (kingColor == 'B' && board[i][j] == BLACK_KING)) {
                kingX = i;
                kingY = j;
                break;
            }
        }
        if (kingX != -1) break; // Stopper la recherche après avoir trouvé le roi
    }

    // Si le roi n'existe pas ou est introuvable, aucun mouvement légal
    if (kingX == -1 || kingY == -1) return false;

    // Liste des directions possibles pour les mouvements du roi
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    // Vérifier chaque direction
    for (int d = 0; d < 8; d++) {
        int newX = kingX + directions[d][0];
        int newY = kingY + directions[d][1];

        // Vérifier si la case est valide
        if (!isValidPosition(newX, newY)) continue;

        Piece target = board[newX][newY];

        // Vérifier si la case est vide ou contient une pièce ennemie
        if ((kingColor == 'W' && (target == EMPTY || (target >= BLACK_PAWN && target <= BLACK_ROOK))) ||
            (kingColor == 'B' && (target == EMPTY || (target >= WHITE_PAWN && target <= WHITE_ROOK)))) {
            // Simuler le mouvement pour vérifier si le roi reste en échec
            Piece originalPosition = board[newX][newY];  // Sauvegarder la case cible
            board[newX][newY] = board[kingX][kingY];     // Déplacer le roi temporairement
            board[kingX][kingY] = EMPTY;

            // Vérifier si le roi est toujours en échec après ce mouvement
            if (!isInCheck(board, kingColor)) {
                // Restaurer les positions originales
                board[kingX][kingY] = board[newX][newY];
                board[newX][newY] = originalPosition;
                return true; // Un mouvement légal a été trouvé
            }

            // Restaurer les positions originales
            board[kingX][kingY] = board[newX][newY];
            board[newX][newY] = originalPosition;
        }
    }

    // Aucun mouvement légal trouvé
    return false;
}

#include <stdbool.h>
#include <stdlib.h>
#include "piece.h"

// Vérifie si une pièce est ennemie
bool isEnemyPiece(Piece piece, char kingColor) {
    return (kingColor == 'W' && piece >= BLACK_PAWN && piece <= BLACK_ROOK) ||
           (kingColor == 'B' && piece >= WHITE_PAWN && piece <= WHITE_ROOK);
}

// Vérifier si une pièce ennemie à (i, j) peut attaquer la position (kingX, kingY)
bool isAttacking(Piece board[8][8], int i, int j, int kingX, int kingY) {
    Piece attackingPiece = board[i][j]; // Récupérer la pièce d'attaque

    // Si la case est vide ou contient une pièce alliée, elle ne peut pas attaquer
    if (attackingPiece == EMPTY || !isEnemyPiece(attackingPiece, board[kingX][kingY] == WHITE_KING ? 'W' : 'B'))
        return false;

    // Calculer les déplacements (différence en x et y)
    int dx = abs(kingX - i);
    int dy = abs(kingY - j);

    // Déterminer si la pièce attaque en fonction de son type
    switch (attackingPiece) {
        case WHITE_PAWN:
        case BLACK_PAWN:
            if (board[kingX][kingY] == WHITE_KING) {
                // Pions noirs attaquent en diagonale vers le bas
                return (kingX == i + 1 && (kingY == j + 1 || kingY == j - 1));
            } else if (board[kingX][kingY] == BLACK_KING) {
                // Pions blancs attaquent en diagonale vers le haut
                return (kingX == i - 1 && (kingY == j + 1 || kingY == j - 1));
            }
            break;

        case WHITE_KNIGHT:
        case BLACK_KNIGHT:
            // Cavalières : mouvements en "L"
            return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);

        case WHITE_BISHOP:
        case BLACK_BISHOP:
            // Fous : mouvements en diagonale
            if (dx == dy) {
                // Vérifier qu'il n'y a pas d'obstacles entre la pièce et la cible
                int stepX = (kingX > i) ? 1 : -1;
                int stepY = (kingY > j) ? 1 : -1;
                for (int k = 1; k < dx; k++) {
                    if (board[i + k * stepX][j + k * stepY] != EMPTY) {
                        return false; // Obstacle trouvé
                    }
                }
                return true;
            }
            break;

        case WHITE_ROOK:
        case BLACK_ROOK:
            // Tours : mouvements en ligne droite (horizontale ou verticale)
            if (dx == 0 || dy == 0) {
                int stepX = (dx == 0) ? 0 : (kingX > i ? 1 : -1);
                int stepY = (dy == 0) ? 0 : (kingY > j ? 1 : -1);
                for (int k = 1; k < (dx == 0 ? dy : dx); k++) {
                    if (board[i + k * stepX][j + k * stepY] != EMPTY) {
                        return false; // Obstacle trouvé
                    }
                }
                return true;
            }
            break;

        case WHITE_QUEEN:
        case BLACK_QUEEN:
            // Reines : combinaison des mouvements de fou et de tour
            if (dx == dy) { // Diagonale (comme un fou)
                int stepX = (kingX > i) ? 1 : -1;
                int stepY = (kingY > j) ? 1 : -1;
                for (int k = 1; k < dx; k++) {
                    if (board[i + k * stepX][j + k * stepY] != EMPTY) {
                        return false; // Obstacle trouvé
                    }
                }
                return true;
            } else if (dx == 0 || dy == 0) { // Ligne droite (comme une tour)
                int stepX = (dx == 0) ? 0 : (kingX > i ? 1 : -1);
                int stepY = (dy == 0) ? 0 : (kingY > j ? 1 : -1);
                for (int k = 1; k < (dx == 0 ? dy : dx); k++) {
                    if (board[i + k * stepX][j + k * stepY] != EMPTY) {
                        return false; // Obstacle trouvé
                    }
                }
                return true;
            }
            break;

        case WHITE_KING:
        case BLACK_KING:
            // Roi : se déplace d'une case dans toute direction
            return dx <= 1 && dy <= 1;

        default:
            break;
    }

    return false; // Si aucune condition n'est remplie, la pièce n'attaque pas
}
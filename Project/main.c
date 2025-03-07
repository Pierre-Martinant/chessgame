#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "piece.h"
#include "board.h"

char play1[50];
char play2[50];
char color1[5];
char color2[5];

char players ();
int isDraw(Piece **board[8][8]);

int main() {
    Piece **board = generateEmptyBoard();
    //resetBoardPiece(board);
    placePiece(board, E, 8, BLACK_KING);
    displayBoard(board);
    players();
    isDraw(board);
    deleteBoard(board);
    printf("it's show %s", play1);
    return 0;
}


char players() {
    printf("Player 1: ");
    scanf("%49s", play1);
    printf("Player 2: ");
    scanf("%49s", play2);
    // Demande à l'utilisateur de choisir une couleur
    printf("Choisissez votre couleur (black ou white) : ");
    scanf("%5s", color1); // "%5s" pour éviter un dépassement de buffer

    // Vérification et attribution de l'autre couleur
    if (strcmp(color1, "black") == 0) {
        strcpy(color2, "white");
    }
    else if (strcmp(color1, "white") == 0) {
        strcpy(color2, "black");
    }
    else {
        printf("Couleur invalide ! Veuillez entrer 'black' ou 'white'.\n");
        return 1; // Quitte le programme avec un code d'erreur
    }
    printf("L'autre joueur jouera avec : %s\n", color2);
    return 0;
    }

int isDraw(Piece **board[8][8]) {
    int WKing = 0, BKing = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] = WHITE_KING) {
                WKing = 1;
            }
            if (board[i][j] = BLACK_KING) {
                BKing = 1;
            }
        }
    }
    // If one of the kings is missing, the game is a draw
    if ("R" == 0 || "r" == 0) {
        printf("One of the King is missing\n");
        return 1;  // Draw
    }

    return 0;  // The game continues
}

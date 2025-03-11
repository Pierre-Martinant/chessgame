#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "piece.h"
#include "board.h"
#include "Bishop.h"
#include "King.h"
#include "Rook.h"
#include "knight.h"
#include "pawn.h"
#include "Queen.h"
#include "Echec.h"
#include "EchecetMat.h"


char play1[50];
char play2[50];
char color1[5];
char color2[5];

char players ();
int isDraw(Piece **board[8][8]);
void game (Piece **board[8][8]);

int main() {
    Piece **board = generateEmptyBoard();
    resetBoardPiece(board);
    displayBoard(board);
    players();
    game(board);
    deleteBoard(board);
    return 0;
}


char players() {
    printf("Player 1: ");
    scanf("%49s", play1);
    printf("Player 2: ");
    scanf("%49s", play2);
    // Demande à l'utilisateur de choisir une couleur
    printf("Choose your color (black or white) : ");
    scanf("%5s", color1); // "%5s" pour éviter un dépassement de buffer

    // Vérification et attribution de l'autre couleur
    if (strcmp(color1, "black") == 0) {
        strcpy(color2, "white");
    }
    else if (strcmp(color1, "white") == 0) {
        strcpy(color2, "black");
    }
    else {
        printf("Invalid color! Please enter 'black' or 'white'.\n");
        return 1; // Quitte le programme avec un code d'erreur
    }
    printf("The other player will play with : %s\n", color2);
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
        //deleteBoard(board);
    }
    // If one of the kings is missing, the game is a draw
    if ("R" == 0 || "r" == 0) {
        printf("One of the King is missing\n");
        return 1;  // Draw
        //deleteBoard(board);
    }

    return false;  // The game continues
}

void game (Piece **board[8][8]) {
    while (isDraw(board) == false) {
        printf("Player %s: %s\n", play1, color1);
        if (color1 == "white") {
        }
        printf("Player %s: %s\n", play2, color2);
    }
}
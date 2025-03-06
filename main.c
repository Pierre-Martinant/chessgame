#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "piece.h"
#include "board.h"

char play1[50];
char play2[50];
char color1[5];
char color2[5];

char players ();
int isDraw(Piece **board[8][8]);
void deleteplayerinfo ();

int main() {
    Piece **board = generateEmptyBoard();
    //resetBoardPiece(board);
    placePiece(board, E, 8, BLACK_KING);
    placePiece(board, E, 1, WHITE_KING);
    displayBoard(board);
    players();
    isDraw(board);
    deleteBoard(board);
    deleteplayerinfo();
    printf("it's show %s", play1);
    return 0;
}


char players() {
    printf("Player 1: ");
    scanf("%49s", play1);
    printf("Player 2: ");
    scanf("%49s", play2);
    printf("black or white: ");
    scanf("%5s", color1);
    if (color1 == "black") {
        char color2 = "white";
    }
    else if (color1 == "white") {
        char color2 = "black";
    }
    printf("%s is : %s\n", play1, color1);
    printf("%s is : %s\n", play2, color2);
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

void deleteplayerinfo () {
    // Free all row before board
    free(play1);
    free(play2);
    free(color1);
    free(color2);
}
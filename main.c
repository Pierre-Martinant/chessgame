#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "piece.h"
#include "board.h"

void knight_moves ();
char players ();

int main() {
    Piece **board = generateEmptyBoard();
    resetBoardPiece(board);
    displayBoard(board);
    players();
    deleteBoard(board);
    return 0;
}

void knight_moves() {
}


char players() {
    char play1[50];
    char play2[50];
    printf("Player 1: ");
    scanf("%49s", play1);
    printf("Player 2: ");
    scanf("%49s", play2);
    printf("Joueur 1 : %s\n", play1);
    printf("Joueur 2 : %s\n", play2);
}
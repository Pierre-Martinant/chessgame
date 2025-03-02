#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "piece.h"
#include "board.h"

void knight_moves ();
void game ();

int main() {
    Piece **board = generateEmptyBoard();
    resetBoardPiece(board);
    displayBoard(board);
    game();
    deleteBoard(board);
    return 0;
}

void knight_moves() {
}

void game () {
    char* play1;
    char* play2;
    printf("Player 1: " );
    scanf("Player 1: %s", play1);
    printf("Player 2: " );
    scanf("Player 2: %s", play2);
    printf("%s", play1);
}
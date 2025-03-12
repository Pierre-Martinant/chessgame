#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piece.h"
#include "board.h"
#include "moves.h"

char play1[50];
char play2[50];
char color1[5];
char color2[5];
int turns = 0;

int players();
int isDraw(Piece board[8][8]);
void game(Piece board[8][8]);
int turn(const char *beginning, const char *end, Piece board[8][8]);
void parsePosition(const char *pos, int *row, int *col);

int main() {
    Piece **board = generateEmptyBoard();
    resetBoardPiece(board);
    displayBoard(board);
    players();
    game(board);
    deleteBoard(board);
    return 0;
}

int players() {printf("Player 1: ");
    scanf("%49s", play1);
    printf("Player 2: ");
    scanf("%49s", play2);
    // Ask the user to choose a color
    printf("Choose your color (black or white) : ");
    scanf("%5s", color1); // "%5s" to prevent buffer overflow

    // Check and assign the other color
    if (strcmp(color1, "black") == 0) {
        strcpy(color2, "white");
    }
    else if (strcmp(color1, "white") == 0) {
        strcpy(color2, "black");
    }
    else {
        printf("Invalid color! Please enter 'black' or 'white'.\n");
        return 1; // Exit the program with an error code
    }
    printf("The other player will play with: %s\n", color2);
    // Display assigned roles
    printf("%s will play as %s, %s will play as %s.\n", play1, color1, play2, color2);
}

void game(Piece board[8][8]) {
    while (true) {
        char beginning[3] = "";
        char end[3] = "";

        // Display the current player's name and color based on the turn
        if (turns % 2 == 0) {
            printf("%s's Turn (%s):\n", play1, color1);
        } else {
            printf("%s's Turn (%s):\n", play2, color2);
        }

        // Prompt the player to enter their move
        printf("Enter move (e.g., c1 d5): ");
        if (scanf("%2s %2s", beginning, end) != 2) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Process the move
        if (!turn(beginning, end, board)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Update the board
        displayBoard(board);

        // Check for draw condition
        if (isDraw(board)) {
            printf("The game is a draw!\n");
            break;
        }

        // Increment the turn counter to switch to the next player
        turns++;
    }
}

// Other functions (turn, isDraw, etc.) remain unchanged

int turn(const char *beginning, const char *end, Piece board[8][8]) {
    int fromRow, fromCol, toRow, toCol;

    // Convert positions from chess notation to array indices
    parsePosition(beginning, &fromRow, &fromCol);
    parsePosition(end, &toRow, &toCol);

    // Debugging: Print indices to verify correctness
    printf("Move from [%d][%d] to [%d][%d]\n", fromRow, fromCol, toRow, toCol);

    // Check if the positions are valid and within the board
    if (fromRow < 0 || fromRow >= 8 || toRow < 0 || toRow >= 8 ||
        fromCol < 0 || fromCol >= 8 || toCol < 0 || toCol >= 8) {
        printf("Invalid move: Out of bounds.\n");
        return 0;
        }

    // Check if there is a piece at the source
    if (board[fromRow][fromCol] == EMPTY) {
        printf("Invalid move: No piece at the source.\n");
        return 0;
    }

    // Move the piece and update the board
    board[toRow][toCol] = board[fromRow][fromCol]; // Place piece at the destination
    board[fromRow][fromCol] = EMPTY;               // Clear the source position

    printf("Piece moved successfully.\n");
    displayBoard(board);
    return 1; // Move successful
}

int isDraw(Piece board[8][8]) {
    int kingCount = 0;

    // Iterate through the board to count kings
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Piece piece = board[row][col]; // Get the current piece

            if (piece == WHITE_KING || piece == BLACK_KING) {
                kingCount++; // Increment king count for each king found
            } else if (piece != EMPTY) {
                // If any piece other than a king is found, it's not a draw
                return 0; // Game cannot be a draw
            }
        }
    }

    // Check if there are exactly two kings on the board
    if (kingCount == 2) {
        printf("Draw detected: King vs King.\n");
        return 1; // It's a draw
    }

    return 0; // Game is not a draw
}

void parsePosition(const char *pos, int *row, int *col) {
    *col = pos[0] - 'a';          // Convert column ('a' to 'h') to 0-7
    *row = 8 - (pos[1] - '0');    // Convert row ('1' to '8') to 0-7
}
#include <stdbool.h>
#include <stdlib.h>

// Enum for piece types
typedef enum {
    WHITE_PAWN,
    WHITE_KING,
    WHITE_QUEEN,
    WHITE_BISHOP,
    WHITE_KNIGHT,
    WHITE_ROOK,
    BLACK_PAWN,
    BLACK_KING,
    BLACK_QUEEN,
    BLACK_BISHOP,
    BLACK_KNIGHT,
    BLACK_ROOK,
    EMPTY
} PieceType;

// Enum for piece colors
typedef enum {
    WHITE,
    BLACK,
    NONE // Used for an empty square
} PieceColor;

// Piece structure
typedef struct {
    PieceType type;
    PieceColor color;
} Piece;

// Function to get a string representation of a piece
char pieceToString(Piece piece) {
    switch (piece.type) {
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

// Checks if a square is within the bounds of the board
bool isInsideBoard(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// Function to check if a piece can attack another
bool canAttack(Piece board[8][8], int fromX, int fromY, int toX, int toY) {
    Piece piece = board[fromX][fromY];

    switch (piece.type) {
        case WHITE_KING:
        case BLACK_KING:
            return (abs(fromX - toX) <= 1 && abs(fromY - toY) <= 1);

        case WHITE_QUEEN:
        case BLACK_QUEEN:
            if (fromX == toX || fromY == toY) { // Horizontal or vertical move
                for (int i = 1; i < abs(fromX - toX) || i < abs(fromY - toY); i++) {
                    if (board[fromX + i * ((toX - fromX) > 0 ? 1 : -1)][fromY + i * ((toY - fromY) > 0 ? 1 : -1)].type != EMPTY) {
                        return false;
                    }
                }
                return true;
            } else if (abs(fromX - toX) == abs(fromY - toY)) { // Diagonal move
                for (int i = 1; i < abs(fromX - toX); i++) {
                    if (board[fromX + i * ((toX - fromX) > 0 ? 1 : -1)][fromY + i * ((toY - fromY) > 0 ? 1 : -1)].type != EMPTY) {
                        return false;
                    }
                }
                return true;
            }
            break;

        case WHITE_ROOK:
        case BLACK_ROOK:
            if (fromX == toX) { // Vertical move
                for (int i = 1; i < abs(fromY - toY); i++) {
                    if (board[fromX][fromY + i * ((toY - fromY) > 0 ? 1 : -1)].type != EMPTY) {
                        return false;
                    }
                }
                return true;
            } else if (fromY == toY) { // Horizontal move
                for (int i = 1; i < abs(fromX - toX); i++) {
                    if (board[fromX + i * ((toX - fromX) > 0 ? 1 : -1)][fromY].type != EMPTY) {
                        return false;
                    }
                }
                return true;
            }
            break;

        case WHITE_BISHOP:
        case BLACK_BISHOP:
            if (abs(fromX - toX) == abs(fromY - toY)) { // Diagonal move
                for (int i = 1; i < abs(fromX - toX); i++) {
                    if (board[fromX + i * ((toX - fromX) > 0 ? 1 : -1)][fromY + i * ((toY - fromY) > 0 ? 1 : -1)].type != EMPTY) {
                        return false;
                    }
                }
                return true;
            }
            break;

        case WHITE_KNIGHT:
        case BLACK_KNIGHT:
            if ((abs(fromX - toX) == 2 && abs(fromY - toY) == 1) || (abs(fromX - toX) == 1 && abs(fromY - toY) == 2)) {
                return true;
            }
            break;

        case WHITE_PAWN:
        case BLACK_PAWN:
            if (piece.color == WHITE && fromX - toX == 1 && abs(fromY - toY) == 1) {
                return true;
            }
            if (piece.color == BLACK && toX - fromX == 1 && abs(fromY - toY) == 1) {
                return true;
            }
            break;

        default:
            return false; // Unsupported case
    }

    return false;
}

//
// Created by there on 12/03/2025.
//

#ifndef MOVES_H
#define MOVES_H

#include <stdbool.h>

bool bishopMove(int x1, int y1, int x2, int y2);
bool kingMove(int x1, int y1, int x2, int y2);
bool isValidMove(int x, int y);
bool isKnightMoveValid(int startX, int startY, int endX, int endY);
void printPossibleMoves(int startX, int startY);
bool pawnMove(int x1, int y1, int x2, int y2, bool firstMove);
bool queenMove(int x1, int y1, int x2, int y2);
bool rookMove(int x1, int y1, int x2, int y2);


#endif //MOVES_H

//
// Created by cavyh on 11/03/2025.
//

#ifndef KNIGHT_H
#define KNIGHT_H

#include <stdbool.h>

#define BOARD_SIZE 8

bool isValidMove(int x, int y);
bool isKnightMoveValid(int startX, int startY, int endX, int endY);
void printPossibleMoves(int startX, int startY);

#endif

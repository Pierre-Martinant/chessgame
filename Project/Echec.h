//
// Created by there on 11/03/2025.
//

#ifndef ECHEC_H
#define ECHEC_H

#include <stdbool.h>
#include "piece.h"

bool isAttacking(Piece board[8][8], int i, int j, int kingX, int kingY);
bool isInCheck(Piece** board[8][8], char kingColor);

#endif

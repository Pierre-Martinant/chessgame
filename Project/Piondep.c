#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction pour vérifier si le déplacement du pion est valide
bool pawnMove(int x1, int y1, int x2, int y2, bool firstMove) {
    int dy = y2 - y1;
    int dx = abs(x2 - x1);

    // Le pion avance d'une case vers l'avant ou deux cases si c'est son premier coup
    if (dx == 0 && ((dy == 1) || (firstMove && dy == 2))) {
        return true;
    }

    // Le pion capture en diagonale d'une case
    if (dx == 1 && dy == 1) {
        return true;
    }

    return false;
}

int main() {
    int x1, y1, x2, y2;
    char firstMove;

    printf("Enter the pawn's starting coordinates (x y): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the pawn's destination coordinates (x y): ");
    scanf("%d %d", &x2, &y2);

    printf("Is it the pawn's first move? (y/n): ");
    scanf(" %c", &firstMove);

    if (pawnMove(x1, y1, x2, y2, firstMove == 'y' || firstMove == 'Y')) {
        printf("Valid pawn move.\n");
    } else {
        printf("Invalid pawn move.\n");
    }

    return 0;
}

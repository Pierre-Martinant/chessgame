#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction pour vérifier si le déplacement de la tour est valide
bool rookMove(int x1, int y1, int x2, int y2) {
    // La tour ne peut se déplacer qu'horizontalement ou verticalement
    return (x1 == x2 || y1 == y2);
}

int main() {
    int x1, y1, x2, y2;

    printf("Enter the rook's starting coordinates (x y): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the rook's destination coordinates (x y): ");
    scanf("%d %d", &x2, &y2);

    if (rookMove(x1, y1, x2, y2)) {
        printf("Valid rook move.\n");
    } else {
        printf("Invalid rook move.\n");
    }

    return 0;
}

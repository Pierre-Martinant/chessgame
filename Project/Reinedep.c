#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction pour vérifier si le déplacement de la dame est valide
bool queenMove(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // La dame peut se déplacer horizontalement, verticalement ou en diagonale
    return (x1 == x2 || y1 == y2 || dx == dy);
}

int main() {
    int x1, y1, x2, y2;

    printf("Enter the queen's starting coordinates (x y): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the queen's destination coordinates (x y): ");
    scanf("%d %d", &x2, &y2);

    if (queenMove(x1, y1, x2, y2)) {
        printf("Valid queen move.\n");
    } else {
        printf("Invalid queen move.\n");
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction pour vérifier si le déplacement du fou est valide
bool bishopMove(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // Le fou ne peut se déplacer qu'en diagonale
    return (dx == dy);
}

int main() {
    int x1, y1, x2, y2;

    printf("Enter the bishop's starting coordinates (x y): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the bishop's destination coordinates (x y): ");
    scanf("%d %d", &x2, &y2);

    if (bishopMove(x1, y1, x2, y2)) {
        printf("Valid bishop move.\n");
    } else {
        printf("Invalid bishop move.\n");
    }

    return 0;
}

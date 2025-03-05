#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction pour vérifier si le déplacement du fou est valide
bool deplacementFou(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // Le fou ne peut se déplacer qu'en diagonale
    return (dx == dy);
}

int main() {
    int x1, y1, x2, y2;

    printf("Entrez les coordonnées de départ du fou (x y) : ");
    scanf("%d %d", &x1, &y1);

    printf("Entrez les coordonnées d'arrivée du fou (x y) : ");
    scanf("%d %d", &x2, &y2);

    if (deplacementFou(x1, y1, x2, y2)) {
        printf("Déplacement valide du fou.\n");
    } else {
        printf("Déplacement invalide du fou.\n");
    }

    return 0;
}

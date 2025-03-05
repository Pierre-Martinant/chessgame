#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction pour vérifier si le déplacement de la dame est valide
bool deplacementDame(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // La dame peut se déplacer horizontalement, verticalement ou en diagonale
    return (x1 == x2 || y1 == y2 || dx == dy);
}

int main() {
    int x1, y1, x2, y2;

    printf("Entrez les coordonnées de départ de la dame (x y) : ");
    scanf("%d %d", &x1, &y1);

    printf("Entrez les coordonnées d'arrivée de la dame (x y) : ");
    scanf("%d %d", &x2, &y2);

    if (deplacementDame(x1, y1, x2, y2)) {
        printf("Déplacement valide de la dame.\n");
    } else {
        printf("Déplacement invalide de la dame.\n");
    }

    return 0;
}


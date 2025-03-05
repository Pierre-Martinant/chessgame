
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction pour vérifier si le déplacement du roi est valide
bool deplacementRoi(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // Le roi peut se déplacer d'une case dans toutes les directions
    return (dx <= 1 && dy <= 1);
}

int main() {
    int x1, y1, x2, y2;

    printf("Entrez les coordonnées de départ du roi (x y) : ");
    scanf("%d %d", &x1, &y1);

    printf("Entrez les coordonnées d'arrivée du roi (x y) : ");
    scanf("%d %d", &x2, &y2);

    if (deplacementRoi(x1, y1, x2, y2)) {
        printf("Déplacement valide du roi.\n");
    } else {
        printf("Déplacement invalide du roi.\n");
    }

    return 0;
}

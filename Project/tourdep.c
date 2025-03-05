#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction pour vérifier si le déplacement de la tour est valide
bool deplacementTour(int x1, int y1, int x2, int y2) {
    // La tour ne peut se déplacer qu'horizontalement ou verticalement
    return (x1 == x2 || y1 == y2);
}

int main() {
    int x1, y1, x2, y2;
    
    printf("Entrez les coordonnées de départ de la tour (x y) : ");
    scanf("%d %d", &x1, &y1);
    
    printf("Entrez les coordonnées d'arrivée de la tour (x y) : ");
    scanf("%d %d", &x2, &y2);
    
    if (deplacementTour(x1, y1, x2, y2)) {
        printf("Déplacement valide de la tour.\n");
    } else {
        printf("Déplacement invalide de la tour.\n");
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction pour vérifier si le déplacement du pion est valide
bool deplacementPion(int x1, int y1, int x2, int y2, bool premierCoup) {
    int dy = y2 - y1;
    int dx = abs(x2 - x1);

    // Le pion avance d'une case vers l'avant ou deux cases si c'est son premier coup
    if (dx == 0 && ((dy == 1) || (premierCoup && dy == 2))) {
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
    char premierCoup;

    printf("Entrez les coordonnées de départ du pion (x y) : ");
    scanf("%d %d", &x1, &y1);

    printf("Entrez les coordonnées d'arrivée du pion (x y) : ");
    scanf("%d %d", &x2, &y2);

    printf("Est-ce le premier coup du pion ? (o/n) : ");
    scanf(" %c", &premierCoup);

    if (deplacementPion(x1, y1, x2, y2, premierCoup == 'o' || premierCoup == 'O')) {
        printf("Déplacement valide du pion.\n");
    } else {
        printf("Déplacement invalide du pion.\n");
    }

    return 0;
}

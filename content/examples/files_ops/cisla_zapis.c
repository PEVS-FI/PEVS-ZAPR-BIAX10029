/*
 * Načítanie počtu a hodnôt čísel z textového súboru.
 */

#include <stdio.h>

int main() {
    int pocet, *pole;

    FILE *f = fopen("cisla.txt", "r");
    fscanf(f, "%d\n", &pocet);
    pole = new int [pocet];

    for (int i = 0; i < pocet; i++) {
        fscanf(f, "%d\n", &pole[i]);
        printf("%d ", pole[i]);
    }

    return 0;
}

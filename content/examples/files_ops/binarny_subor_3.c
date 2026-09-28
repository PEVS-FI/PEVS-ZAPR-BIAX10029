/*
 * Porovnanie alokácie malloc a new pri práci s binárnym súborom.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    int pocet;
    double *pole;
    double *pole2;

    printf("Zadaj pocet prvkov pola: ");
    scanf("%d", &pocet);

    if ((pole = (double *) malloc(sizeof(double) * pocet)) == NULL) {
        printf("nemam pamat");
    } else {
        for (int i = 0; i < pocet; i++) {
            printf("zadaj prvok pole[%d]: ", i);
            scanf("%lf", &pole[i]);
        }

        f = fopen("bin_pole.dat", "wb+");
        fwrite(pole, sizeof(double), pocet, f);
        printf("pozicia v subore je: %ld \n", ftell(f));

        fseek(f, 0, SEEK_SET);
        printf("pozicia v subore je: %ld \n", ftell(f));

        if ((pole2 = new double[pocet]) == NULL) {
            printf("nemam pamat pre pole2");
        } else {
            pocet = fread(pole2, sizeof(double), pocet, f);
            printf("pocet nacitanych poloziek je %d \n", pocet);

            for (int j = 0; j < pocet; j++) {
                printf("pole2[%d]: = %lf ", j, pole2[j]);
            }
        }
        fclose(f);
    }
}
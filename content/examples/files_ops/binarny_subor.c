/*
 * Základný zápis a čítanie premenných do binárneho súboru.
 */

#include <stdio.h>

int main() {
    FILE *f;
    int i;
    double d;

    int i2;
    double d2;

    printf("zadaj i: ");
    scanf("%d", &i);

    printf("zadaj d: ");
    scanf("%lf", &d);

    f = fopen("pokus.dat", "wb+");

    fwrite(&i, sizeof(int), 1, f);
    fwrite(&d, sizeof(d), 1, f);

    printf("sizeof(int) je %d, sizeof(d) je %d a teda pozicia v subore je: %ld \n", sizeof(int), sizeof(d), ftell(f));

    fseek(f, 0, SEEK_SET);

    fread(&i2, sizeof(i), 1, f);
    fread(&d2, sizeof(double), 1, f);

    printf("i2 = %d, d2 = %lf", i2, d2);

    fclose(f);
}
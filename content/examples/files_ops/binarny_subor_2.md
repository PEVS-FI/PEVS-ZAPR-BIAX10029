---
date: '2026-09-28'
title: 'Binárny súbor – pole desatinných čísel'
weight: 1
---


Zápis a čítanie poľa double do binárneho súboru.

```c
#include <stdio.h>

int main() {
    FILE *f;
    int pocet;
    double *pole;
    double *pole2;

    printf("Zadaj pocet prvkov pola: ");
    scanf("%d", &pocet);

    if ((pole = new double[pocet]) == NULL) {
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
```

[Stiahnuť zdrojový kód](../binarny_subor_2.c)

### Vysvetlenie

Program alokuje pole desatinných čísel, načíta hodnoty od používateľa a zapíše ich do binárneho súboru pomocou funkcie
`fwrite`. Následne pomocou `fseek` presunie pozíciu na začiatok súboru a prečíta dáta späť do druhého poľa funkciou
`fread`.

Príklad ilustruje prácu s binárnymi súbormi a sledovanie aktuálnej pozície v súbore funkciou `ftell`.

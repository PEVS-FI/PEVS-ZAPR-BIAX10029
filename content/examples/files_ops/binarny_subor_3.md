---
date: '2026-09-28'
title: 'Binárny súbor – malloc a new'
weight: 1
---


Porovnanie alokácie malloc a new pri práci s binárnym súborom.

```c
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
```

[Stiahnuť zdrojový kód](../binarny_subor_3.c)

### Vysvetlenie

Tento príklad je funkčne rovnaký ako predchádzajúci, ale mieša alokáciu pomocou `malloc` a `new`. Ukazuje, že oba
spôsoby alokácie pamäte možno v rámci jedného programu kombinovať, hoci sa to v čistom C neodporúča.

Zápis a čítanie dát do binárneho súboru prebieha rovnako pomocou `fwrite` a `fread`, pričom pozícia v súbore sa
kontroluje funkciou `ftell`.

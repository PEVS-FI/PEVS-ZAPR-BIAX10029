---
date: '2026-09-28'
title: 'Čítanie a spracovanie čísel zo súboru'
weight: 1
---


Extrakcia a sčítanie čísel obsiahnutých v textovom súbore.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fr, *fo;
    if ((fr = fopen("nieco.txt", "r")) != NULL) {
        fo = fopen("Kopia.txt", "w");

        int n, i = 0;
        int c;

        while ((c = getc(fr)) != EOF) {
            if (c >= '0' && c <= '9') {
                ungetc(c, fr);
                fscanf(fr, "%d", &n);
                i++;
            }
        }
        fclose(fr);

        fr = fopen("nieco.txt", "r");
        int *pole = (int *) malloc(i * sizeof(int));

        i = 0;
        while ((c = getc(fr)) != EOF) {
            if (c >= '0' && c <= '9') {
                ungetc(c, fr);
                fscanf(fr, "%d", &pole[i]);
                i++;
            }
        }
        fclose(fr);

        printf("v subore je %d cisel \n", i);
        fprintf(fo, "v subore je %d cisel \n", i);
        int suma = 0;
        for (int j = 0; j < i; j++) {
            printf("n[%d] = %d ", j, pole[j]);
            suma = suma + pole[j];
            fprintf(fo, "%d\n", pole[j]);
        }
        fprintf(fo, "%d je ich suma\n", suma);
        fclose(fo);
    } else {
        printf("najskor vytvor subor nieco.txt, inak nerobim!!!\n");
    }
    return 0;
}
```

[Stiahnuť zdrojový kód](../citanie_suboru.c)

### Vysvetlenie

Program prečíta textový súbor `nieco.txt`, nájde v ňom všetky čísla a uloží ich do dynamického poľa. Používa funkciu
`getc` na čítanie znakov a `ungetc` na vrátenie znaku späť, keď narazí na číslicu.

Následne vypočíta a vypíše súčet čísel, pričom výsledky zapíše aj do nového súboru `Kopia.txt`. Príklad kombinuje
čítanie, spracovanie a zápis do súboru.

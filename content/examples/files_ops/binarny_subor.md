---
date: '2026-09-28'
title: 'Binárny súbor – zápis a čítanie'
weight: 1
---


Základný zápis a čítanie premenných do binárneho súboru.

```c
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
```

[Stiahnuť zdrojový kód](../binarny_subor.c)

### Vysvetlenie

Program načíta celé číslo a desatinné číslo, zapíše ich do binárneho súboru `pokus.dat` a následne ich zo súboru načíta
späť do iných premenných. Využíva funkcie `fwrite` a `fread`, ktoré ukladajú dáta v binárnej podobe.

Príklad tiež prezentuje funkcie `fseek` (nastavenie pozície) a `ftell` (zistenie aktuálnej pozície) a porovnáva veľkosť
uložených typov.

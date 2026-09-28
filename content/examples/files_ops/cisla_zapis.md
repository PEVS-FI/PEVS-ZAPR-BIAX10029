---
date: '2026-09-28'
title: 'Čítanie čísel zo súboru'
weight: 1
---


Načítanie počtu a hodnôt čísel z textového súboru.

```c
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

```

[Stiahnuť zdrojový kód](../cisla_zapis.c)

### Vysvetlenie

Program otvorí textový súbor `cisla.txt`, načíta z neho počet čísel a následne samotné čísla do dynamického poľa
alokovaného pomocou `new`. Načítané hodnoty priebežne vypisuje na obrazovku.

Príklad demonštruje čítanie formátovaných dát z textového súboru pomocou funkcie `fscanf` a dynamickú alokáciu poľa
podľa načítaného počtu prvkov.

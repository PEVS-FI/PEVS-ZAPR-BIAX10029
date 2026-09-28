---
date: '2026-09-28'
title: 'Dynamické pole (calloc)'
weight: 1
---


Alokácia poľa funkciou calloc, ktorá pamäť vynuluje.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dyn_pole, pocet;

    printf("zadaj pocet prvkov pola ");
    scanf("%d", &pocet);

    printf("velkost int je %d\n", sizeof(int));

    if ((dyn_pole = (int *) calloc(pocet, sizeof(int))) != NULL) {
        for (int i = 0; i < pocet; i++) {
            printf("zadaj dyn_pole[%d] ", i);
            scanf("%d", &dyn_pole[i]);
        }

        for (int i = 0; i < pocet; i++) {
            printf("dyn_pole[%d] = %d (teda %d) a je na adrese %p\n", i, dyn_pole[i], *(dyn_pole + i), dyn_pole + i);
        }
        free((void *) dyn_pole);
    } else {
        printf("nemam dost pamati");
    }
}
```

[Stiahnuť zdrojový kód](../dynamicke_pole_3.c)

### Vysvetlenie

Príklad je variantom dynamického poľa, tentoraz alokovaného funkciou `calloc`. Funkcia `calloc` na rozdiel od `malloc`
prijíma počet prvkov a ich veľkosť oddelene a navyše celú alokovanú pamäť nastaví na nulu.

Program načíta prvky, vypíše ich hodnoty aj adresy a na záver pamäť uvoľní volaním `free`. Slúži na porovnanie rôznych
spôsobov alokácie dynamickej pamäte.

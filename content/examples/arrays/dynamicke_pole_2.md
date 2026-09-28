---
date: '2026-09-28'
title: 'Dynamické pole (malloc)'
weight: 1
---


Korektná alokácia dynamického poľa funkciou malloc s uvoľnením pamäte.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dyn_pole, pocet;

    printf("zadaj pocet prvkov pola ");
    scanf("%d", &pocet);

    printf("velkost int je %d\n", sizeof(int));

    if ((dyn_pole = (int *) malloc(pocet * sizeof(int))) != NULL) {
        for (int i = 0; i < pocet; i++) {
            printf("zadaj dyn_pole[%d] ", i);
            scanf("%d", dyn_pole + i);
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

[Stiahnuť zdrojový kód](../dynamicke_pole_2.c)

### Vysvetlenie

Tento príklad je ekvivalentom predchádzajúceho, avšak pamäť alokuje pomocou funkcie `malloc` zo štandardnej knižnice
`stdlib.h`. Pred načítaním prvkov program skontroluje, či alokácia uspela, a pri neúspechu vypíše chybové hlásenie.

Na rozdiel od `new` tu program po skončení práce s poľom uvoľňuje alokovanú pamäť volaním `free`, čo je správny spôsob
práce s dynamickou pamäťou v jazyku C. Program zároveň vypíše veľkosť typu `int`.

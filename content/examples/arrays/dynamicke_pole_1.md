---
date: '2026-09-28'
title: 'Dynamické pole (new)'
weight: 1
---


Alokácia dynamického poľa pomocou operátora new.

```c
#include <stdio.h>

int main() {
    int *dyn_pole, pocet;

    printf("zadaj pocet prvkov pola ");
    scanf("%d", &pocet);

    dyn_pole = new int[pocet];

    for (int i = 0; i < pocet; i++) {
        printf("zadaj dyn_pole[%d] ", i);
        scanf("%d", dyn_pole + i);
    }

    for (int i = 0; i < pocet; i++) {
        printf("dyn_pole[%d] = %d (teda %d) a je na adrese %p\n", i, dyn_pole[i], *(dyn_pole + i), dyn_pole + i);
    }
}
```

[Stiahnuť zdrojový kód](../dynamicke_pole_1.c)

### Vysvetlenie

Program načíta počet prvkov poľa a pomocou operátora `new` alokuje pamäť pre pole celých čísel požadovanej veľkosti.
Veľkosť poľa je teda určená až za behu programu, na rozdiel od statických polí.

Naplnenie aj výpis pracujú s pointerovou aritmetikou: na adresu prvku sa odkazuje zápisom `dyn_pole + i` a ekvivalentne
`*(dyn_pole + i)`, čím príklad demonštruje vzťah medzi poľom a pointerom.

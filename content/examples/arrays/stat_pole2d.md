---
date: '2026-09-28'
title: 'Statické dvojrozmerné pole'
weight: 1
---


Práca so statickým dvojrozmerným poľom pevnej veľkosti.

```cpp
#include <stdio.h>

int main() {
    int st_pole[3][4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("zadaj st_pole[%d][%d] ", i, j);
            scanf("%d", st_pole[i] + j);
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%p\n", st_pole[i]);
        for (int j = 0; j < 4; j++)
            printf("st_pole[%d][%d] = %d a je na adrese %p \n", i, j, st_pole[i][j], &st_pole[i][j]);
        printf("\n");
    }
}
```

[Stiahnuť zdrojový kód](../Stat_pole2D.cpp)

### Vysvetlenie

Program pracuje so statickým dvojrozmerným poľom `st_pole[3][4]`, ktoré má dopredu známu veľkosť. Načíta hodnoty do
všetkých prvkov a následne ich vypíše spoločne s ich adresami v pamäti.

Pri výpise adresy prvku vidno, ako je dvojrozmerné pole uložené v pamäti po riadkoch súvisle za sebou. Príklad pomáha
pochopiť adresovanie statických polí.

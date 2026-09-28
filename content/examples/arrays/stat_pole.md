---
date: '2026-09-28'
title: 'Statické pole'
weight: 1
---


Práca so statickým jednorozmerným poľom pevnej veľkosti.

```cpp
#include <stdio.h>

int main() {
    int st_pole[5];

    for (int i = 0; i < 5; i++) {
        printf("zadaj st_pole[%d] ", i);
        scanf("%d", st_pole + i);
    }

    for (int i = 0; i < 5; i++) {
        printf("st_pole[%d] = %d (teda %d) a je na adrese %p (teda %p) \n", i, st_pole[i], *(st_pole + i), st_pole[i],
               &(*(st_pole + i)));
    }
}
```

[Stiahnuť zdrojový kód](../Stat_pole.cpp)

### Vysvetlenie

Príklad ukazuje jednorozmerné statické pole pevnej veľkosti 5 prvkov. Program načíta hodnoty a pri výpise ku každému
prvku zobrazí jeho hodnotu a adresu, ku ktorej sa dostane troma rôznymi spôsobmi (indexom, pointerovou aritmetikou a
operátorom adresy).

Slúži ako základ na pochopenie vzťahu medzi poľom, pointerom a adresou prvku v pamäti.

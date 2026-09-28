---
date: '2025-11-05T23:23:07+01:00'
title: 'Úloha 6.7'
weight: 7
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý definuje statické pole ľubovolnej veľkosti typu
`int[]` a následne vypíše všetky jeho elementy odzadu, t.j. od posledného k prvému, t.j. od _indexu <dĺžka poľa> - 1_ po
_index 0_. Každý element poľa je vypísaný do nového riadku.

### Príklady vstupov / výstupov programu

Pre pole `[9,8,5,1,3]` program vypíše:

```text
3
1
5
8
9
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int main() {
    // Definícia statického poľa
    int array[] = {10, 20, 30, 40, 50}; // Ľubovoľné hodnoty
    int size = sizeof(array) / sizeof(array[0]); // Počet prvkov v poli

    // Výpis prvkov poľa odzadu
    printf("Array elements in reverse order:\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d\n", array[i]);
    }

    return 0;
}
```

#### Vysvetlenie

1. Definícia poľa:
    * Pole array[] je inicializované s ľubovoľnými hodnotami, napr. {10, 20, 30, 40, 50}.

2. Výpočet veľkosti poľa:
    * sizeof(array) vráti celkovú veľkosť poľa v bajtoch.
    * sizeof(array[0]) vráti veľkosť jedného prvku poľa.
    * size sa vypočíta ako počet prvkov v poli: sizeof(array) / sizeof(array[0]).

3. Iterácia cez pole odzadu:
    * Cyklus for iteruje od posledného indexu (size - 1) po prvý index (0).
    * Prvky sa vypisujú pomocou printf na samostatné riadky.

#### Príklad výstupu

Pri inicializácii poľa int array[] = {10, 20, 30, 40, 50}; bude výstup nasledovný:

```text
Array elements in reverse order:
50
40
30
20
10
```

-->

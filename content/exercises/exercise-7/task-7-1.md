---
date: '2025-11-12T23:19:03+01:00'
title: 'Úloha 7.1'
weight: 1
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý vypýta na vstupe od používateľa číslo `int n`
a následne alokuje pamäť _n_ blokov každý o veľkosti typu `int`.

Po alokácií program vypíše jednotlivé hodnoty čísle v alokovanej pamäti.

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Požiadanie používateľa o zadanie čísla
    printf("Enter the number of integers to allocate memory for: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of blocks.\n");
        return 1;
    }

    // Dynamická alokácia pamäte pre n prvkov typu int
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Inicializácia alokovanej pamäte a výpis hodnôt
    printf("Allocated memory values:\n");
    for (int i = 0; i < n; i++) {
        array[i] = i; // Inicializácia na 0 (voliteľné)
        printf("Value at index %d: %d\n", i, array[i]);
    }

    // Uvoľnenie alokovanej pamäte
    free(array);

    return 0;
}
```

#### Vysvetlenie

1. Vstup od používateľa:
    * Používateľ zadá počet blokov pamäte, ktoré sa majú alokovať (n).

2. Dynamická alokácia pamäte:
    * malloc(n * sizeof(int)) alokuje pamäť pre n prvkov typu int.
    * Funkcia malloc vráti pointer na začiatok alokovanej pamäte, alebo NULL, ak alokácia zlyhá.

3. Kontrola úspešnosti alokácie:
    * Ak malloc vráti NULL, program vypíše chybové hlásenie a ukončí sa.

4. Inicializácia a výpis:
    * Cyklus inicializuje hodnoty na 0 a vypisuje ich (hodnoty sú defaultne nešpecifikované, takže ich inicializácia je
      voliteľná).

5. Uvoľnenie pamäte:
    * free(array) uvoľní dynamicky alokovanú pamäť, aby sa predišlo úniku pamäte.

#### Príklad výstupu

Vstup: `Enter the number of integers to allocate memory for: 5`

Výstup:

```text
Allocated memory values:
Value at index 0: 0
Value at index 1: 0
Value at index 2: 0
Value at index 3: 0
Value at index 4: 0
```

-->

---
date: '2025-11-05T23:23:08+01:00'
title: 'Úloha 6.8'
weight: 8
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý zoradí hodnoty staticky definovaného pola typu
`int[]`
od najmenšej hodnoty po najväčšiu. Elementy poľa sú zoraďované v definovanom poli, **nevytvárajte** nové pole.
Po zoradení program vypíše postupne všetky elementy poľa za sebou v jednom riadku.

> [!TIP]
> Pre prehodenie dvoch čísel je potrebná tretia pomocná premenná.

### Príklady vstupov / výstupov programu

Pre pole `[9,8,5,1,3]` program vypíše:

```text
1, 3, 5, 8, 9
```

### Pomôcka

Skúste najprv prísť na implementáciu bez tejto pomoci. Ak by ste sa však nevedeli
pohnúť [obrázok na tomto odkaze opisuje algoritmus zoradenia](https://www.w3resource.com/w3r_images/c-pointer-exercise-14-image.png).

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int main() {
    // Definícia a inicializácia statického poľa
    int array[] = {34, 7, 23, 32, 5, 62};
    int size = sizeof(array) / sizeof(array[0]); // Veľkosť poľa

    // Bubble sort na zoradenie poľa
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Výmenná operácia
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Výpis zoradeného poľa
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
```

#### Vysvetlenie

1. Definícia poľa:
    * Pole array[] je inicializované s ľubovoľnými hodnotami, napr. {34, 7, 23, 32, 5, 62}.

2. Výpočet veľkosti poľa:
    * sizeof(array) určuje veľkosť poľa v bajtoch.
    * sizeof(array[0]) určuje veľkosť jedného prvku poľa.
    * Veľkosť poľa je teda size = sizeof(array) / sizeof(array[0]).

3. Bubble sort algoritmus:
    * Dvojitý cyklus iteruje cez pole.
    * Ak je aktuálny prvok väčší ako nasledujúci, hodnoty sa vymenia.
    * Tento proces sa opakuje, až kým pole nie je zoradené.

4. Výpis poľa:
    * Po zoradení sa prvky poľa vypisujú v jednom riadku oddelené medzerami.

#### Príklad výstupu

Pri inicializácii poľa int array[] = {34, 7, 23, 32, 5, 62}; bude výstup:

```text
Sorted array: 5 7 23 32 34 62
```

-->

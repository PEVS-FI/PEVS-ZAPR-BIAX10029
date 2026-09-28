---
date: '2025-11-05T23:23:01+01:00'
title: 'Úloha 6.5'
weight: 5
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý definuje pole typu `int[]` o veľkosti _5_.
Prvky poľa definujte pri jeho inicializácii (tzv. statické pole).

Program postupne vypíše všetky prvky pola, kde pre každý prvok vypíše na štandardný výstup reťazec:

`<index prvku>. element of the array <adresa poľa> has address <adresa prvku> with value <hodnota prvku>`

### Príklady vstupov / výstupov programu

Pre pole `[9,8,5,1,3]` program vypíše:

```text
0. element of the array 0x7ffda2eeeec1 has address 0x7ffda2eeeec0 with value 9
1. element of the array 0x7ffda2eeeec1 has address 0x7ffda2eeeec4 with value 8
2. element of the array 0x7ffda2eeeec1 has address 0x7ffda2eeeec8 with value 5
3. element of the array 0x7ffda2eeeec1 has address 0x7ffda2eeeecc with value 1
4. element of the array 0x7ffda2eeeec1 has address 0x7ffda2eeeed0 with value 3
```

> [!NOTE]
> Všimnite si, že adresy elementov poľa ídu v sekvencií za sebou a adresa 0. elementu je taktiež adresa poľa.

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int main() {
    // Definícia a inicializácia poľa
    int array[5] = {10, 20, 30, 40, 50};

    // Prechádzanie poľa a výpis požadovaných informácií
    for (int i = 0; i < 5; i++) {
        printf("%d. element of the array %p has address %p with value %d\n", i, array, &array[i], array[i]);
    }

    return 0;
}
```

#### Vysvetlenie

1. Definícia a inicializácia poľa:
    * Pole array je staticky definované s veľkosťou 5 a inicializované hodnotami {10, 20, 30, 40, 50}.

2. Iterácia cez pole:
    * for cyklus prechádza všetky indexy poľa od 0 po 4.

3. Výpis informácií:
    * Pre každý prvok poľa sa vypíše:
        * Index prvku (i).
        * Adresa samotného poľa (array).
        * Adresa konkrétneho prvku (&array[i]).
        * Hodnota prvku (array[i]).

4. Formátovanie:
    * %d sa používa na hodnoty typu int.
    * %p na výpis adries. Adresy sa pretypujú na (void *) pre kompatibilitu so štandardom %p.

-->

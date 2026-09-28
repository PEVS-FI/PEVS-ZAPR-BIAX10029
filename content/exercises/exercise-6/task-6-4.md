---
date: '2025-11-05T23:23:00+01:00'
title: 'Úloha 6.4'
weight: 4
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý obsahuje funkciu ,ktorá spočíta dve čísla.
Funkciu implementujte tak aby prijímala ako argumenty dva pointre typu `int*` (t.j. volanie referenciou - call by
reference) a vrátila číslo typu _int_ (pozor nie pointer!).

Funkciu následne zavolajte s rôznymi vstupmi.

### Príklady vstupov / výstupov programu

- pre čísla 5 a 6 program vypíše:

```text
Function called with pointer <adresa> with value 5 and pointer <adresa> with value 6.
The sum of the numbers is 11.
```

- pre čísla 74 a -23 program vypíše:

```text
Function called with pointer <adresa> with value 74 and pointer <adresa> with value -23.
The sum of the numbers is 51.
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

// Funkcia na spočítanie dvoch čísel pomocou pointerov
int addNumbers(int *a, int *b) {
    // Výpis adries a hodnôt argumentov
    printf("Function called with pointer %p with value %d and pointer %p with value %d.\n", a, *a, b, *b);

    // Návrat súčtu hodnôt, na ktoré ukazujú pointery
    return *a + *b;
}

int main() {
    // Premenné na testovanie
    int num1 = 5, num2 = 6;
    int num3 = 74, num4 = -23;

    // Prvé volanie funkcie
    int sum1 = addNumbers(&num1, &num2);
    printf("The sum of the numbers is %d.\n\n", sum1);

    // Druhé volanie funkcie
    int sum2 = addNumbers(&num3, &num4);
    printf("The sum of the numbers is %d.\n", sum2);

    return 0;
}
```

#### Vysvetlenie

1. Funkcia addNumbers:
    * Funkcia prijíma dva pointery typu int*.
    * Vypisuje adresy a hodnoty, na ktoré ukazujú pointery.
    * Vracia súčet hodnôt, na ktoré ukazujú pointery.

2. Hlavný program:
    * Definované sú premenné num1, num2, num3, a num4.
    * Volanie funkcie addNumbers s adresami premenných pomocou operátora &.
    * Výstup obsahuje informácie o pointeroch, hodnotách a výslednom súčte.

3. Dôležité:
    * Operátor & sa používa na získanie adresy premenných.
    * Dereferencovanie * vráti hodnotu na adrese, na ktorú ukazuje pointer.

#### Príklad výstupu

Pri spustení programu bude výstup nasledovný:

```text
Function called with pointer 0x7ffcd3b9b41c with value 5 and pointer 0x7ffcd3b9b418 with value 6.
The sum of the numbers is 11.

Function called with pointer 0x7ffcd3b9b414 with value 74 and pointer 0x7ffcd3b9b410 with value -23.
The sum of the numbers is 51.
```

-->

---
date: '2026-09-28'
title: 'Faktoriál pomocou rekurzie'
weight: 1
---


Rekurzívny výpočet faktoriálu čísla.

```c
#include <stdio.h>

int fak(int n) {
    if (n == 0) { return 1; } else { return n * fak(n - 1); }
}

int main() {
    int i, j;
    printf("zadaj i ");
    scanf("%d", &i);
    j = fak(i);
    printf("fak(%d) = %d", i, j);
}
```

[Stiahnuť zdrojový kód](../faktorial_funkcie.c)

### Vysvetlenie

Funkcia `fak` počíta faktoriál čísla rekurzívne: faktoriál nuly je 1 a pre ostatné n vracia súčin `n * fak(n-1)`.
Program načíta číslo od používateľa a vypíše jeho faktoriál.

Príklad je najjednoduchšou ukážkou rekurzie – funkcie, ktorá volá samú seba, až kým nedosiahne ukončovaciu podmienku.

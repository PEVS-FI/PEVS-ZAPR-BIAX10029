---
date: '2026-09-28'
title: 'Smerník – základ'
weight: 1
---


Základná práca so smerníkom na premennú.

```c
#include <stdio.h>

int main() {
    int i, *p_i;

    printf("zadaj i: ");
    scanf("%d", &i);

    p_i = &i;

    printf("i = %d, *p_i = %d, &i = %p a p_i = %p, &p_i = %p", i, *p_i, &i, p_i, &p_i);

    return 0;
}
```

[Stiahnuť zdrojový kód](../pointer_1.c)

### Vysvetlenie

Program načíta celé číslo, priradí adresu premennej do smerníka `p_i` a vypíše hodnotu premennej, hodnotu cez smerník,
adresu premennej, obsah smerníka aj adresu samotného smerníka.

Ukazuje základné operátory pre prácu so smerníkmi: `&` pre získanie adresy a `*` pre dereferencovanie.

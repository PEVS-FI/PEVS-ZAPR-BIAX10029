---
date: '2026-09-28'
title: 'Smerník na smerník'
weight: 1
---


Práca so smerníkom na smerník (viacúrovňový pointer).

```c
#include <stdio.h>

int main() {
    int i, j, *p_i, **ppi;

    printf("zadaj i: ");
    scanf("%d", &i);

    p_i = &i;

    printf("i = %d, *p_i = %d, &i = %p a p_i = %p\n", i, *p_i, &i, p_i);

    printf("zadaj j: ");
    scanf("%d", &j);

    p_i = &j;

    printf("i = %d, *p_i = %d, &i = %p a p_i = %p, j = %d, &j = %p\n", i, *p_i, &i, p_i, j, &j);


    ppi = &p_i;

    printf("&p_i = %p, ppi = %p, *ppi = %p, **ppi = %d\n", &p_i, ppi, *ppi, **ppi);


    p_i = &i;

    **ppi = i + j;

    printf("i = %d, j = %d", i, j);

    return 0;
}
```

[Stiahnuť zdrojový kód](../pointer_2.c)

### Vysvetlenie

Program rozširuje základnú prácu so smerníkom o smerník na smerník `ppi`. Postupne ilustruje presmerovanie smerníka na
inú premennú, dereferencovanie viacerých úrovní a zápis hodnoty cez dvojité dereferencovanie.

Vypisy ukazujú vzťah medzi adresami a hodnotami na každej úrovni, čo pomáha pochopiť viacúrovňové smerníky.

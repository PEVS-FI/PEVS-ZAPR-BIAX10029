---
date: '2026-09-28'
title: 'Jednoduché pole a príkaz goto'
weight: 1
---


Ukážka viacúrovňového dynamického poľa s použitím príkazu goto.

```cpp
#include <stdio.h>

int main() {
    int i = 0, j = 0;
    int **pole;

    pole = new int *[3];
    int po[3];
    int po2[2];

    int *pole1 = new int[3];
    pole[1] = pole1;
    int max;
    int horna;
    printf("zadaj hornu hranica \n");
    scanf("%d", &horna);
    printf("zadaj max \n");
    scanf("%d", &max);

    for (j = 0; j < horna; j++) {
        for (i = 0; i <= j; printf("i", i++));
        if (i == max) goto a;
        printf("\n");
    }
a:
    printf("pokracovanie programu \n");
    return 0;
}
```

[Stiahnuť zdrojový kód](../simple_array.cpp)

### Vysvetlenie

Príklad demonštruje prácu s viacúrovňovým dynamickým poľom vytvoreným pomocou `new` a zároveň ilustruje použitie príkazu
`goto` na preskočenie časti cyklu.

Program podľa zadanej hornej hranice vypisuje postupnosť indexov, pričom po dosiahnutí zadaného maxima preskočí na
označenie `a` a pokračuje ďalšou časťou programu. Príklad ukazuje, že použitie `goto` je síce možné, ale zhoršuje
čitateľnosť kódu.

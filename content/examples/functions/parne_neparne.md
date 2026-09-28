---
date: '2026-09-28'
title: 'Vzájomná rekurzia (párne/nepárne)'
weight: 1
---

Dve funkcie, ktoré sa vzájomne volajú (vzájomná rekurzia).

```c
#include <stdio.h>

int odd(int n);

int even(int n) {
    // predpoklad: n >= 0
    if (n == 0) return 1;
    else if (n == 1) return 0;
    else return odd(n - 1);
}

int odd(int n) {
    // predpoklad: n >= 0
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return even(n - 1);
}

int main() {
    int i, j;
    printf("zadaj i ");
    scanf("%d", &i);
    j = even(i);
    printf("even(%d) = %d", i, j);
}
```

[Stiahnuť zdrojový kód](../parne_neparne.c)

### Vysvetlenie

Program definuje dve funkcie `even` a `odd`, ktoré určujú, či je číslo párne alebo nepárne. Navzájom sa volajú s
argumentom zmenšeným o 1, čím vzniká vzájomná (mutuálna) rekurzia.

Ukazuje, ako možno dve funkcie riešiť rekurzívne tak, že si vzájomne odovzdávajú výpočet až po základný prípad.

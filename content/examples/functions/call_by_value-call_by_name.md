---
date: '2026-09-28'
title: 'Volanie hodnotou a odkazom'
weight: 1
---


Správne použitie volania hodnotou a volania odkazom.

```c
#include <stdio.h>

void zvacsio(int *a, int n) {
    *a = *a + n;
}

int cbv(int a) {
    a = a + 1;
    return a;
}

int main() {
    int n;

    printf("zadaj n");
    scanf("%d", &n);

    n = cbv(n);
    printf("n = %d\n", n);
    zvacsio(&n, 5);
    printf("n = %d\n", n);
}
```

[Stiahnuť zdrojový kód](../call_by_value-call_by_name.c)

### Vysvetlenie

Program demonštruje dve funkcie: `cbv` (call by value), ktorá pracuje s kópiou argumentu a výsledok vracia návratovou
hodnotou, a `zvacsio` (call by reference), ktorá prijíma smerník a mení pôvodnú premennú.

Porovnaním správania oboch funkcií je vidieť, kedy je vhodné hodnotu predať kópiou a kedy je potrebné poslať adresu, aby
sa zmena prejavila vo volajúcom prostredí.

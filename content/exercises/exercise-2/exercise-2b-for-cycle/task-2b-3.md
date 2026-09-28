---
date: '2025-10-01T23:53:38+02:00'
title: 'Úloha 2b.3'
weight: 3
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý pre vstupný parameter _n_ vráti tzv. súčet štvorcov
pomocou vzorca _1^2 + 2^2 + 3^2 + ... + n^2_ pričom tento súčet vypočítajte pomocou for-cyklu. Hodnotu parametru _n_ zadá
používateľ cez štandardný vstup.

### Príklady vstupov / výstupov programu

- Program pre **n = 3** vypíše hodnotu **14**, pretože **14 = 1^2 + 2^2 + 3^2**
- Program pre **n = 5** vypíše hodnotu **55**, pretože **55 = 1^2 + 2^2 + 3^2 + 4^2 + 5^2**

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int main() {
    int n;

    printf("Zadajte číslo: ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    printf("%d", sum);

    return 0;
}
```

-->

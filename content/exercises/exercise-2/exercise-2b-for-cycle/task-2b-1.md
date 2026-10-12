---
date: '2025-10-01T23:53:30+02:00'
title: 'Úloha 2b.1'
weight: 1
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý vypíše na obrazovku čísla _od 1 po N_.
Hodnotu _N_ zadaná používateľ cez štandardný vstup.

### Príklady vstupov / výstupov programu

Pre číslo **10** na vstupe program vypíše postupnosť **1 2 3 4 5 6 7 8 9 10**.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main() {
    int n;

    printf("Zadajte číslo: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }

    return 0;
}
```

{{< /details >}}

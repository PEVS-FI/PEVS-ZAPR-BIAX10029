---
date: '2025-10-01T23:53:36+02:00'
title: 'Úloha 2b.2'
weight: 2
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý vypíše na obrazovku prvých _N_ párnych čísiel,
začínajúc dvojkou. Počet čísiel na vypísanie určuje používateľ zo štandardného vstupu.

### Príklady vstupov / výstupov programu

- Pre zadanie **N = 1** vypíše program na obrazovku číslo **2**.
- Pre zadanie **N = 5** vypíše program na obrazovku čísla **2 4 6 8 10**, každé na nový riadok.
- Pre zadanie **N = 10** vypíše program na obrazovku čísla **2 4 6 8 10 12 14 16 18 20**, každé na nový riadok

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main() {
    int n;

    printf("Zadajte číslo: ");
    scanf("%d", &n);

    for (int i = 1; i <= n * 2; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
```

{{< /details >}}


---
date: '2025-10-09T10:01:55+02:00'
title: 'Úloha 3.3'
weight: 3
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Definujte funkciu **_int minimum_dvoch (int a, int b)_** s 2 parametrami, číslami _a_ a _b_. Funkcia vráti minimum z
týchto 2 čísiel.

### Príklady vstupov / výstupov programu

- Volanie `minimum_dvoch(2,5)` vráti hodnotu 2
- Volanie `minimum_dvoch(5,5)` vráti hodnotu 5
- Volanie `minimum_dvoch(-2,-105)` vráti hodnotu -105

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int minimum_dvoch(int a, int b) {
    if (a < b) return a;
    return b;
}

int main() {

    printf("%d\n", minimum_dvoch(2,5));
    printf("%d\n", minimum_dvoch(5,5));
    printf("%d\n", minimum_dvoch(-2,-105));

    return 0;
}
```

{{< /details >}}

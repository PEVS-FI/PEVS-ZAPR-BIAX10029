---
date: '2025-10-09T10:01:52+02:00'
title: 'Úloha 3.2'
weight: 2
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Upravte funkciu **_double priemer_troch (int a, int b, int c)_** z predošlej úlohy tak, aby vrátila aritmetický priemer
týchto
3 parametrov, teda hodnotu _(a+b+c)/3_.

### Príklady vstupov / výstupov programu

- Volanie funkcie `priemer_troch(1,2,3)` vráti hodnotu 2.0, pretože (1+2+3)/3 = 2.0.
- Volanie funkcie `priemer_troch(1,2,4.5)` vráti hodnotu 2.5, pretože (1+2+4.5)/3 = 2.5.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

float priemer_troch(float a, float b, float c) {
    return (a + b + c) / 3.0;
}

int main() {

    printf("%.2f\n", priemer_troch(1, 2, 3));
    printf("%.2f\n", priemer_troch(1, 2, 4.5));

    return 0;
}
```

{{< /details >}}

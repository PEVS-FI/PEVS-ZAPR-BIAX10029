---
date: '2025-10-01T23:16:39+02:00'
title: 'Úloha 2a.2'
weight: 2
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý rozhodne či zadané číslo je pozitívne, negatívne
alebo nula.
Čísla môže zadať používateľ štandardným vstupom. Program po zadaní vstupu vypíše či je číslo pozitívne, negatívne alebo
je presne nula.

### Príklady vstupov / výstupov programu

Ak používateľ zadá ako vstup číslo **-5** program vypíše **negatívne**, pre číslo **98** vypíše program **pozitívne**
a pre vstup **0** vypíše **nula**.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main() {
    int cislo;

    printf("Zadajte číslo: ");
    scanf("%d", &cislo);

    if (cislo < 0) {
        printf("negatívne", cislo);
    } else if (cislo > 0) {
        printf("pozitívne", cislo);
    } else if (cislo == 0) {
        printf("nula", cislo);
    }
    return 0;
}
```

{{< /details >}}

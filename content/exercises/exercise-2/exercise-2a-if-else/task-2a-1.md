---
date: '2025-10-01T23:16:11+02:00'
title: 'Úloha 2a.1'
weight: 1
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý nájde maximum z dvoch zadaných čísel.
Čísla môže zadať používateľ štandardným vstupom. Program vypíše svoje zistenie používateľovi.

### Príklady vstupov / výstupov programu

Ak používateľ zadá ako vstup čísla **5** a **8** tak program vypíše číslo **8** ako maximum.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main() {
    int a, b;

    printf("Zadajte dve čísla oddelené medzerou: ");
    scanf("%d %d", &a, &b);
    if (a < b) {
        printf("%d", b);
    } else {
        printf("%d", a);
    }

    return 0;
}
```

{{< /details >}}

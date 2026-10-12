---
date: '2025-10-01T23:53:44+02:00'
title: 'Úloha 2b.6'
weight: 6
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý vyžiada od používateľa cez štandardný vstup
2 parametre _a_ a _b_. Môžete predpokladať, že _a_ aj _b_ sú kladné celé čísla. Funkcia vráti súčin _a*b_.
Program implementujte bez použitia operátora *, t.j. bez násobenia!

> [!IMPORTANT]
> Zamyslite sa, ako je možné realizovať násobenie len pomocou opakovaného pripočítavania!

### Príklady vstupov / výstupov programu

Spustenie programu s parametrami 2 a 5 vráti hodnotu 10.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main() {
    int a, b;

    printf("Zadajte dve čísla oddelené medzerou: ");
    scanf("%d %d", &a, &b);

    int r = 0;
    for (int i = 0; i < b; i++) {
        r += a;
    }
    printf("%d", r);

    return 0;
}
```

{{< /details >}}

---
date: '2025-10-01T23:53:48+02:00'
title: '✨ Úloha 2b.8'
weight: 8
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý implementuje mocninu.
Používateľ zadá na vstupe dve kladné čísla _n_ a _k_. Program vypíše _k-tu_ mocninu čísla _n_, t.j. _n^k_.
Program implementujte bez použitia operátora * (násobenie) a bez použitia operátora ** (umocnenie).

> [!IMPORTANT]
> Zamyslite sa, ako je možné realizovať násobenie len pomocou opakovaného pripočítavania.

### Príklady vstupov / výstupov programu

- Spustenie programu so vstupnými číslami 1 a 5 vypíše hodnotu 1.
- Spustenie programu so vstupnými číslami 2 a 5 vypíše hodnotu 32.
- Spustenie programu so vstupnými číslami 3 a 4 vypíše hodnotu 81.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main(void) {
    int n, k;

    if (scanf("%d %d", &n, &k) != 2) return 1;

    if (k == 0) {
        printf("1\n");
        return 0;
    }

    int result = 1;
    for (int i = 0; i < k; ++i) {
        int prev = result;
        int acc = 0;
        for (int j = 0; j < n; ++j) {
            acc += prev;          // násobenie iba opakovaným pripočítavaním
        }
        result = acc;             // result *= n; (bez použitia *)
    }

    printf("%d\n", result);
    return 0;
}
```

{{< /details >}}

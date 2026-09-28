---
date: '2025-10-09T10:02:11+02:00'
title: '✨ Úloha 3.9'
weight: 9
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Definujte funkciu **_int delitelnost(int a, int d)_** so vstupnými parametrami kladnými celými číslami _a_ a _d_.
Funkcia vráti hodnotu **1** ak _d_ delí _a_, inak vráti hodnotu **0**. V tejto úlohe nemusíte ošetrovať
korektnosť parametrov _a_ a _d_.

> [!NOTE]
> Číslo d delí číslo a vtedy, ak zvyšok a po delení d je rovný nule.

### Príklady vstupov / výstupov programu

- Volanie `delitelnost(6,3)` vráti hodnotu 1, pretože 3 delí 6.
- Volanie `delitelnost(7,3)` vráti hodnotu 0, pretože 3 nedelí 7.

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

// Funkcia delitelnost:
// Vráti 1, ak d delí a, inak 0.
int delitelnost(int a, int d) {
    if (a % d == 0)
        return 1;
    else
        return 0;
}

int main(void) {
    int a, d;
    printf("Zadajte dve kladné celé čísla a a d: ");
    scanf("%d %d", &a, &d);

    int vysledok = delitelnost(a, d);
    if (vysledok == 1)
        printf("%d delí %d.\n", d, a);
    else
        printf("%d nedelí %d.\n", d, a);

    return 0;
}
```

-->

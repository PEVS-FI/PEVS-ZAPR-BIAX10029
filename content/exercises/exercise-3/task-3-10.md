---
date: '2025-10-09T10:02:14+02:00'
title: '✨ Úloha 3.10'
weight: 10
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Definujte funkciu **_int je_prvocislo(int a)_** so vstupným parametrom kladným číslom _a_, ktorá vráti hodnotu
1, ak je parameter _a_ prvočíslo. Ak je a zložené číslo, funkcia vráti hodnotu 0. Môžete
predpokladať, že _a_ bude mať vždy hodnotu aspoň 2. V implementácii funkcie je_prvocislo(a)
využite funkciu delitelnost() z predošlej úlohy!

> [!NOTE]
> Celé číslo a > 2 je prvočíslo, ak pre všetky čísla od 2 po a-1 platí, že nedelia číslo a. Číslo 2 je prvočíslo
> automaticky.

### Príklady vstupov / výstupov programu

- Volanie `je_prvocislo(7)` vráti hodnotu True, pretože 7 je prvočíslo, pretože ho nedelí žiadne z čísiel
  2,3,4,5,6.
- Volanie `je_prvocislo(8)` vráti hodnotu False, pretože 8 nie je prvočíslo. Z čísiel 2,3,4,5,6,7 ho delia
  čísla 2 a 4.
- Volanie `je_prvocislo(2)` vráti hodnotu True, pretože 2 je prvočíslo.

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

// Funkcia je_prvocislo:
// Vráti 1, ak je číslo a prvočíslo, inak 0.
int je_prvocislo(int a) {
    if (a == 2)
        return 1; // 2 je prvočíslo

    for (int i = 2; i < a; i++) {
        if (delitelnost(a, i)) // ak i delí a
            return 0;          // a nie je prvočíslo
    }
    return 1; // žiadne číslo nedelí a -> prvočíslo
}

int main(void) {
    int a;
    printf("Zadajte celé číslo väčšie alebo rovné 2: ");
    scanf("%d", &a);

    if (je_prvocislo(a))
        printf("%d je prvočíslo.\n", a);
    else
        printf("%d nie je prvočíslo.\n", a);

    return 0;
}
```

-->

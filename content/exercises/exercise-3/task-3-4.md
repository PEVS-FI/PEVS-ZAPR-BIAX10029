---
date: '2025-10-09T10:01:58+02:00'
title: 'Úloha 3.4'
weight: 4
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Definujte funkciu **_int pocet_rovnakych(int a, int b, int c)_** s 3 parametrami, číslami _a,b,c_.

- Funkcia vráti číslo 3, ak sú všetky tri čísla _a,b,c_ rovnaké.
- Vráti číslo 2 ak sú dve z čísel a,b,c rovnaké a tretie číslo je iné.
- Vráti číslo 0, ak sú všetky tri čísla rôzne.

### Príklady vstupov / výstupov programu

- Volanie `pocet_rovnakych(2,5,8)` vráti hodnotu 0.
- Volanie `pocet_rovnakych(1,2,1)` vráti 2
- Volanie `pocet_rovnakych(10,10,10)` vráti 3.

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int pocet_rovnakych(int a, int b, int c){
    if(a != b && a != c && b != c) return 0;
    if(a == b && b == c) return 3;
    if(a == b || a == c || b == c) return 2;
}

int main() {

    printf("%d\n", pocet_rovnakych(2,5,8));
    printf("%d\n", pocet_rovnakych(1,2,1));
    printf("%d\n", pocet_rovnakych(10,10,10));

    return 0;
}
```
-->

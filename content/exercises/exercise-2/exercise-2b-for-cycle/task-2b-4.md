---
date: '2025-10-01T23:53:40+02:00'
title: 'Úloha 2b.4'
weight: 4
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý má 3 vstupné parametre _a0, d a N_, v tomto
poradí. Program vypíše prvých _N_ členov aritmetickej postupnosti, ktorej prvý člen má hodnotu _a0_ a
diferencia postupnosti je daná parametrom _d_. Pri riešení úlohy použite for-cyklus.

> [!NOTE]
> Ak neviete, čo je to aritmetická postupnosť, môžete sa to dočítať napr.
> tu: [https://sk.wikipedia.org/wiki/Aritmetick%C3%A1_postupnos%C5%A5](https://sk.wikipedia.org/wiki/Aritmetick%C3%A1_postupnos%C5%A5).
> V skratke, aritmetická postupnosť je postupnosť čísiel, v ktorej je člen postupnosti rovný súčtu
> predošlého člena postupnosti a diferencie _d_. Ak by _ai_ a _ai+1_ boli 2 po sebe idúce členy postupnosti,
> potom _ai+1 = ai + d_.

### Príklady vstupov / výstupov programu

Volanie programu s parametrami 1,2,5 vypíše čísla 1 3 5 7 9 (každé na nový riadok).

##### Zdôvodnenie

Argumenty 1,2,5 predstavujú hodnoty parametrov a0 = 1, d = 2, N = 5.
Teda prvý člen postupnosti je a0 = 1, členy postupnosti sa od seba líšia o diferenciu d = 2 a chceme
vypísať N = 5 členov postupnosti. Teda sa vypíšu čísla:

- 1 (lebo prvý člen postupnosti je a0 = 1)
- 3 (lebo druhý člen postupnosti je prvý člen + diferencia = 1 + 2 = 3)
- 5 (lebo tretí člen postupnosti je druhý člen + diferencia = 3 + 2 = 5)
- 7 (lebo štvrtý člen postupnosti je tretí člen + diferencia = 5 + 2 = 7)
- 9 (lebo piaty člen postupnosti je štvrtý člen + diferencia = 7 + 2 = 9)

Keďže N = 5, vypíšeme len 5 členov postupnosti.

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int main() {
    int a0, d, n;

    printf("Zadajte parametre aritmetickej postupnosti a0 d n (čísla musia byť oddelené medzerou): ");
    scanf("%d %d %d", &a0, &d, &n);

    printf("%d\n", a0);
    int previous = a0;
    for (int i = 0; i < n-1; i++) {
        previous += d;
        printf("%d\n", previous);
    }

    return 0;
}
```

-->

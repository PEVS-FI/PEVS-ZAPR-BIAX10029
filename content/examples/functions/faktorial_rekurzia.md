---
date: '2026-09-28'
title: 'Kombinačné číslo pomocou rekurzie'
weight: 1
---


Výpočet kombinačného čísla s využitím rekurzívneho faktoriálu.

```c
#include <stdio.h>

int faktorial(int vstup) {
    if (vstup == 0)
        return 1;
    else
        return vstup * faktorial(vstup - 1);
}

int main() {
    int n, k;
    printf("program na vypocet kombinacneho cisla\n");
    printf("zadaj n: ");
    scanf("%d", &n);

    printf("zadaj k: ");
    scanf("%d", &k);

    if (k < 0 || n < k)
        printf("takyto fak nepocitam");
    else
        printf("%d nad %d = %d", n, k, faktorial(n) / (faktorial(n - k) * faktorial(k)));

    return 0;
}

```

[Stiahnuť zdrojový kód](../faktorial_rekurzia.c)

### Vysvetlenie

Program počíta kombinačné číslo „n nad k“ pomocou rekurzívne definovaného faktoriálu podľa vzorca `n! / (k! * (n-k)!)`.
Od používateľa načíta hodnoty n a k a pred výpočtom skontroluje ich platnosť.

Príklad ukazuje praktické využitie rekurzívnej funkcie na riešenie zloženejšieho matematického problému.

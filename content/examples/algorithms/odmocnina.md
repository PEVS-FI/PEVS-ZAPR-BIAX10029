---
date: '2026-09-28'
title: 'Výpočet odmocniny metódou bisekcie'
weight: 1
---



Približný výpočet druhej odmocniny čísla delením intervalu.

```c
#include <stdio.h>

int main() {
    double x;
    printf("Zadajte x \n");
    scanf("%lf", &x);
    double d = 0;
    double h = x + 1;
    double s = (d + h) / 2;
    double eps = 1.0e-10;
    int i = 1;
    while ((h - d) / s > eps) {
        if (s * s >= x)
            h = s;
        else
            d = s;
        s = (d + h) / 2;

        printf("i  = %d, s = %lf ", i++, s);
    }
    printf("Odmocnina %lf je %lf", x, s);
    return 0;
}
```

[Stiahnuť zdrojový kód](../odmocnina.c)

### Vysvetlenie

Program počíta druhú odmocninu zadaného čísla iteračnou metódou bisekcie (delením intervalu na polovice). Začína s
intervalom od 0 po zadané číslo, pričom v každom kroku spresní hranicu intervalu podľa toho, či je druhá mocnina stredu
väčšia alebo menšia ako hľadané číslo.

Výpočet prebieha, kým relatívna šírka intervalu neklesne pod zadanú presnosť `eps`. Program v každej iterácii vypíše
poradové číslo kroku a aktuálny odhad výsledku, čo umožňuje sledovať postupné spresňovanie.

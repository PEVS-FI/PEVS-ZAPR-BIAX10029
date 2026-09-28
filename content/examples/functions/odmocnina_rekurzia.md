---
date: '2026-09-28'
title: 'Odmocnina pomocou rekurzie'
weight: 1
---


Rekurzívny výpočet odmocniny delením intervalu.

```c
#include <stdio.h>

double delenie_intervalu(double d, double h, double cislo, double presnost) {
    double s = (d + h) / 2;

    if ((h - d) / s > presnost) {
        if (s * s >= cislo)
            h = s;
        else
            d = s;
        return delenie_intervalu(d, h, cislo, presnost);
    } else
        return s;
}

int main() {
    double x;
    printf("Zadajte x \n");
    scanf("%lf", &x);
    double d = 0;
    double h = x + 1;

    double eps = 1.0e-10;
    int i = 1;
    double s = delenie_intervalu(d, h, x, eps);

    printf("Odmocnina %lf je %lf", x, s);
    return 0;
}
```

[Stiahnuť zdrojový kód](../odmocnina_rekurzia.c)

### Vysvetlenie

Funkcia `delenie_intervalu` počíta druhú odmocninu rekurzívnou metódou bisekcie. V každom kroku zúži interval obsahujúci
výsledok a rekurzívne sa zavolá, kým sa nedosiahne požadovaná presnosť.

Príklad porovnáva rekurzívne riešenie s iteračnou verziou rovnakého problému, ktorá sa nachádza v príklade
`odmocnina.c`.

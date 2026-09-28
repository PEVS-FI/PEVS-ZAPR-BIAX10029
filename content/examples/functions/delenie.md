---
date: '2026-09-28'
title: 'Funkcia delenia s ošetrením nuly'
weight: 1
---


Funkcia, ktorá ošetruje delenie nulou.

```c
#include <stdio.h>

double delenie(double citatel, double menovatel) {
    if (menovatel == 0) {
        printf("kedze menovatel bol 0, neviem, co mam vratit, tak zvraciam 0\n");
        return 0.0;
    } else
        return citatel / menovatel;
}

int main() {
    double citatel, menovatel;
    printf("zadaj citatel: ");
    scanf("%lf", &citatel);
    printf("zadaj menovatel: ");
    scanf("%lf", &menovatel);

    printf("vysledok je %lf", delenie(citatel, menovatel));
}
```

[Stiahnuť zdrojový kód](../delenie.c)

### Vysvetlenie

Príklad definuje funkciu `delenie`, ktorá prijíma čitateľa a menovateľa a vracia ich podiel. Pred samotným delením
skontroluje, či menovateľ nie je nula, a v takom prípade vypíše upozornenie a vráti hodnotu 0.

Ukazuje dôležitosť ošetrovania chybových stavov vo funkciách, aby program nehavaroval pri delení nulou.

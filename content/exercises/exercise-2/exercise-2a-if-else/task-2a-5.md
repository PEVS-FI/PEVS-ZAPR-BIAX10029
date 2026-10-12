---
date: '2025-10-01T23:16:46+02:00'
title: 'Úloha 2a.5'
weight: 5
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý vypíše koľko kalendárnych dní má mesiac.
Používateľ cez štandardný vstup zadá číslo mesiaca (1-12) a program používateľovi vypíše koľko kalendárnych dní má
zadaný mesiac.
Pre implementáciu programu **použite maximálne 3 podmienky pre výrazy if a else if** a **použite logické operátory**.

### Príklady vstupov / výstupov programu

Ak používateľ zadá ako vstup **5** program vypíše číslo **31**.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main() {
    int mesiac;

    printf("Zadajte mesiac: ");
    scanf("%d", &mesiac);

    if(mesiac == 1 || mesiac == 3 || mesiac == 5 || mesiac == 7 || mesiac == 8 || mesiac == 10 || mesiac == 11){
        printf("31");
    } else if (mesiac == 4 || mesiac == 6 || mesiac == 9 || mesiac == 11) {
        printf("30");
    } else if (mesiac == 2) {
        printf("28 (v priestupný rok 29)");
    } else {
        printf("nezadali ste platný mesiac");
    }

    return 0;
}
```

{{< /details >}}

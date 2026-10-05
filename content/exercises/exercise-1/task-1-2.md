---
date: '2025-09-24T23:00:00+02:00'
title: 'Úloha 1.2'
weight: 2
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Program obsahuje premenné _strana_a_ a _strana_b_. Do týchto premenných sa priamo v zdrojovom
kóde priradia nejaké číselné hodnoty predstavujúce veľkosti hrán obdĺžnika. Program najprv vypíše
obvod a potom obsah daného obdĺžnika.

### Príklady vstupov / výstupov programu

Ak sa do premenných _strana_a_ a _strana_b_ priradia hodnoty _strana_a = 3_, _strana_b = 8_, potom
obvod takého obdĺžnika je 22 a obsah takého obdĺžnika je 24. Program teda vypíše hodnoty 22 a 24
na obrazovku.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main()
{
    int strana_a = 3;
    int strana_b = 8;
    
    printf("Strany obdĺžníka: a=%d, b=%d\n",strana_a, strana_b);
    printf("Obvod obdĺžníka: %d\n", (2 * strana_a) + (2 * strana_b));
    printf("Obsah obdĺžníka: %d\n", strana_a * strana_b);
    return 0;
}
```

{{< /details >}}

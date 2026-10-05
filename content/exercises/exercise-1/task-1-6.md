---
date: '2025-09-24T23:00:09+02:00'
title: 'Úloha 1.6'
weight: 6
---

Napíšte program, ktorý konvertuje teplotu zadanú v stupňoch Celzia na stupne Fahrenheita a vypíše konvertovanú teplotu.
Vstupná teplota je zadaná používateľom po spustení programu.

Vzorec pre konverziu stupníc teploty vyjadruje vzorec:

```text
fahrenheit = (celsius * 9/5) + 32
```

### Príklady vstupov / výstupov programu

Ak používateľa zadá na vstupe teplotu 20.5 °C výsledná teplota bude vypísaná 68.900002 °F

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main()
{
    float c,f;
    
    printf("Zadajte teplutu v °C: ");
    scanf("%f",&c);
    
    printf("Teplota vo Fahrenhei stupnici: %.2f°F",(c * 9/5)+32);
    
    return 0;
}
```

{{< /details >}}

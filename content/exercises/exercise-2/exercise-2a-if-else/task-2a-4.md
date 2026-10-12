---
date: '2025-10-01T23:16:43+02:00'
title: 'Úloha 2a.4'
weight: 4
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý zistí či zadaný rok je priestupný.
Rok môže zadať používateľ štandardným vstupom. Program vypíše slovom _priestupný_ alebo _nie je priestupný_
používateľovi.

> [!TIP]
> Ak by si si nepamätal ako sa zisťuje priestupný rok, môže pomôcť tento
> odkaz [https://www.calendar-365.com/leap-years.html](https://www.calendar-365.com/leap-years.html).

### Príklady vstupov / výstupov programu

Ak používateľ zadá ako vstup **2016** tak program vypíše **priestupný**, pre zadaný rok **2011** program vypíše **nie je
priestupný**.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main() {
    int rok;

    printf("Zadajte rok: ");
    scanf("%d", &rok);

    if(rok % 4 == 0){
        if(rok % 100 == 0) {
            if(rok % 400 == 0) {
                printf("priestupny");
            } else {
                printf("nepriestupny");
            }
        } else {
            printf("priestupny");
        }
    } else {
        printf("nepriestupny");
    }

    return 0;
}
```

{{< /details >}}

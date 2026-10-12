---
date: '2025-10-01T23:16:51+02:00'
title: '✨ Úloha 2a.7'
weight: 7
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý vypíše názov dňa v týždni pre zadané číslo.
Číslo indexu dňa v týždni zadá používateľ štandardným vstupom. Pre implementáciu **môžte použiť iba jeden if výraz**
a **nesmiete použiť switch výraz**.

> [!TIP]
> Dvojrozmerné statické pole stringov je možné definovať ako `char strings[2][10] = {"Prvy", "Druhy"};`
> a následne pristupovať k jednotlivým reťazcom pomocou indexu napr. `strings[0] == "Prvy"`.

### Príklady vstupov / výstupov programu

Pre vstup **1** od používateľa program vypíše **Utorok**.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

char DAY_OF_WEEK[7][10] = {"Pondelok", "Utorok", "Streda", "Štvrtok", "Piatok", "Sobota", "Nedeľa"};

int main() {
    int day;

    printf("Zadajte poradové číslo dňa (začínajúce 0): ");
    scanf("%d", &day);

    if (day >= 0 && day < 7) {
        printf("%s", DAY_OF_WEEK[day]);
    } else {
        printf("Musíte zadať číslo medzi 0 a 6 vrátane");
    }

    return 0;
}
```

{{< /details >}}

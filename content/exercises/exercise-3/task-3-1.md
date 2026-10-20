---
date: '2025-10-09T10:01:49+02:00'
title: 'Úloha 3.1'
weight: 1
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Definujte funkciu **_int tretia_mocnina (int a)_**, ktorá má 1 vstupný parameter, číslo _a_. Funkcia pre vstupný
parameter a vráti hodnotu tretiu mocninu parametra _a_.

### Príklady vstupov / výstupov programu

- Volanie funkcie so vstupným argumentom hodnoty 1, t.j. volanie `tretia_mocnina(1)`, vráti hodnotu
  1, pretože 1\*1\*1 = 1.
- Volanie funkcie so vstupným argumentom hodnoty 2, t.j. volanie `tretia_mocnina(2)`, vráti hodnotu
  8, pretože 2\*2\*2 = 8.
- Volanie funkcie so vstupným argumentom hodnoty 3, t.j. volanie `tretia_mocnina(3)`, vráti hodnotu
  27, pretože 3\*3\*3 = 27.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int tretia_mocnina(int a) {
    return a * a * a;
}

int main() {

    printf("%d\n", tretia_mocnina(1));
    printf("%d\n", tretia_mocnina(2));
    printf("%d\n", tretia_mocnina(3));

    return 0;
}
```

{{< /details >}}
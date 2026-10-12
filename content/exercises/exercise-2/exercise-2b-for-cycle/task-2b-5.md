---
date: '2025-10-01T23:53:42+02:00'
title: 'Úloha 2b.5'
weight: 5
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý od používateľa vyžiada hodnotu parameter _n_
a vypíše na obrazovku mriežku s _n riadkami_ a _n stĺpcami_ podľa diagramov nižšie.

Pre **n = 2** (mriežka s 2 „riadkami“ a 2 „stĺpcami“) by mriežka vyzerala nasledovne:

```text
+ - - - - + - - - - +
|         |         |
|         |         |
|         |         |
|         |         |
+ - - - - + - - - - +
|         |         |
|         |         |
|         |         |
|         |         |
+ - - - - + - - - - +
```

Pre **n = 3** (mriežka s 3 „riadkami“ a 3 „stĺpcami“) by mriežka vyzerala nasledovne:

```text
+ - - - - + - - - - + - - - - +
|         |         |         |
|         |         |         |
|         |         |         |
|         |         |         |
+ - - - - + - - - - + - - - - +
|         |         |         |
|         |         |         |
|         |         |         |
|         |         |         |
+ - - - - + - - - - + - - - - +
|         |         |         |
|         |         |         |
|         |         |         |
|         |         |         |
+ - - - - + - - - - + - - - - +
```

> [!TIP]
> Pre zalomenie reťazca znakov do nového riadku vo funkcii printf môžte použiť znak `\n`.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main() {
    int n;

    printf("Zadajte veľkosť mriežky: ");
    scanf("%d", &n);

    for (int i = 0; i < n*5; i++) {
        if (i % 5 == 0) {
            for (int j = 0; j < n; j++) {
                printf("+ - - - - ");
            }
            printf("+\n");
        } else {
            for (int j = 0; j < n; j++) {
                printf("|         ");
            }
            printf("|\n");
        }
    }
    for (int j = 0; j < n; j++) {
        printf("+ - - - - ");
    }
    printf("+\n");

    return 0;
}
```

{{< /details >}}

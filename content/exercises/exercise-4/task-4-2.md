---
date: '2025-10-15T23:05:59+02:00'
title: 'Úloha 4.2'
weight: 2
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, v ktorom zapúzdrite funkciu súčtu
z [Úlohy 4.1](/exercises/exercise-4/task-4-1) do
funkcie
`int suma()`. Funkciu zavolajte z hlavnej funkcie `main()`, aby sa spustila. Výsledok, ktorý vráti funkcia vypíšte na
obrazovku používateľovi.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int sum(){
    int sum = 0;
    for (int i = 1; i <= 10; ++i) {
        sum += i;
    }
    printf("sum 1-10 = %d", sum);
}

int main() {
    sum();
    return 0;
}
```

{{< /details >}}

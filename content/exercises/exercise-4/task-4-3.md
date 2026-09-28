---
date: '2025-10-15T23:06:01+02:00'
title: 'Úloha 4.3'
weight: 3
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, v ktorom zovšeobecnite funkciu
z [Úlohy 4.2](/exercises/exercise-4/task-4-2),
tak aby vrátila súčet čísel od 1 po N. Funkciu zavolajte z hlavnej funkcie `main()` s rôznymi hodnotami pre vstupný
parameter.
Výsledky, ktoré vráti funkcia vypíšte na obrazovku používateľovi.

Všimnite si, že pre parameter s hodnotou **10** sa program správa rovnako ako verzia v [Úlohe 4.2](/exercises/exercise-4/task-4-2).

### Príklady vstupov / výstupov programu

- pre **vstup 5** funkcia vráti číslo **15**
- pre **vstup 13** funkcia vráti číslo **91**
- pre **vstup 7** funkcia vráti číslo **28**

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int sum(int limit){
    int sum = 0;
    for (int i = 1; i <= limit; ++i) {
        sum += i;
    }
    printf("sum 1-%d = %d\n", limit, sum);
}

int main() {
    sum(5);
    sum(13);
    sum(7);
    return 0;
}
```

-->

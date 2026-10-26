---
date: '2025-10-15T23:06:03+02:00'
title: 'Úloha 4.4'
weight: 4
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, v ktorom zovšeobecnite funkciu suma
z [Úlohy 4.3](/exercises/exercise-4/task-4-3),
tak aby vrátila súčet K-tych mocnín čísel od 1 po N. Funkciu zavolajte z hlavnej funkcie `main()` s rôznymi hodnotami
pre vstupný parameter.
Výsledky, ktoré vráti funkcia vypíšte na obrazovku používateľovi.

Pre voľbu parametra **k = 1** sa program správa rovnako ako predošlá verzia
z [Úlohy 4.3](/exercises/exercise-4/task-4-3).

### Príklady vstupov / výstupov programu

- pre **vstupy K = 1, N = 7** funkcia vráti číslo **28**
- pre **vstupy K = 3, N = 5** funkcia vráti číslo **225**

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

### Riešenie 1

```C
#include <stdio.h>

int sum(int k, int n) {
    int suma = 0;
    for (int i = 1; i <= n; ++i) {
        int mocnina = 1;
        for (int j = 0; j < k; j++) {
            mocnina *= i;
        }
        suma += mocnina;
    }
    printf("súčet %d-tych mocnín čísel 1-%d = %d\n", k, n, suma);
}

int main() {
    sum(1,7);
    sum(3,5);
    return 0;
}
```

### Riešenie 2

```C
#include <stdio.h>
#include <math.h>

int sum(int k, int n) {
    int suma = 0;
    for (int i = 1; i <= n; ++i) {
        suma += pow(i,k);
    }
    printf("súčet %d-tych mocnín čísel 1-%d = %d\n", k, n, suma);
}

int main() {
    sum(1,7);
    sum(3,5);
    return 0;
}
```

{{< /details >}}

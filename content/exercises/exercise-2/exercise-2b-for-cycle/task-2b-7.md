---
date: '2025-10-01T23:53:45+02:00'
title: 'Úloha 2b.7'
weight: 7
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý od používateľa vyžiada parameter _n_.
Môžete predpokladať, že _n_ je kladné celé číslo. Program vypíše postupne na samostatné riadky čísla _od 1 po n_, s krokom +1,
teda na prvý riadok vypíše 1, na druhý riadok 1 2, na tretí riadok 1 2 3, atď.

### Príklady vstupov / výstupov programu

Spustenie programu s parametrom 5 vypíše:
```text
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int main() {
    int n;

    printf("Zadajte číslo: ");
    scanf("%d", &n);

    for(int i=1; i <= n; i++){
        for(int j=1; j <= i; j++){
            printf("%d ",j);
        }
        printf("\n");
    }

    return 0;
}
```

-->

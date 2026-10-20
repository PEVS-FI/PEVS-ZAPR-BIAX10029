---
date: '2025-10-09T10:02:06+02:00'
title: 'Úloha 3.7'
weight: 7
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Definujte funkciu **_int druhe_najvacsie (int n)_** s parametrom celé číslo _n_. Funkcia načíta n čísiel z
klávesnice a vráti druhé najväčšie načítané číslo (druhé maximum). V prípade, že má parameter _n_
hodnotu menšiu ako 2, funkcia vypíše chybovú hlášku, že hodnota vstupného argumentu funkcie
musí byť aspoň 2 a ukončí program.

### Príklady vstupov / výstupov programu

- Volanie `druhe_najvacsie(1)` vypíše chybu a skončí.
- Volanie `druhe_najvacsie(5)` načíta 5 čísiel z klávesnice. Ak sú tieto čísla napríklad 5,-2,1,2,3
  funkcia vráti číslo 3, pretože -2 ≤ 1 ≤ 2 ≤ 3 ≤ 5
- Volanie `druhe_najvacsie(3)` načíta 3 čísla z klávesnice. Ak sú tieto čísla napríklad -10, -5, 0 funkcia
  vráti číslo -5, pretože -10 ≤ -5 ≤ 0

> [!TIP]
> Pri implementácia môžte použiť knižnicu limits.h. `#include <limits.h>`, ktorá obsahuje konštanty pre maximálne
> a minimálne hodnoty dátových typov.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>
#include <limits.h>

int druhe_najvacsie(int n) {
    if (n < 2) {
        printf("Chyba: hodnota vstupného argumentu musí byť aspoň 2.\n");
        return -1;
    }

    int max1 = INT_MIN;  // Najväčšie číslo
    int max2 = INT_MIN;  // Druhé najväčšie číslo
    int num;

    for (int i = 0; i < n; i++) {
        printf("Číslo %d: ", i + 1);
        scanf("%d", &num);

        // Ak je nové číslo väčšie ako max1, posunieme max1 do max2
        if (num > max1) {
            max2 = max1;
            max1 = num;
        }
            // Ak je nové číslo menšie ako max1, ale väčšie ako max2
        else if (num > max2 && num != max1) {
            max2 = num;
        }
    }

    if (max2 == INT_MIN) {
        printf("Nie je možné určiť druhé najväčšie číslo.\n");
        return -1;
    }

    return max2;
}

int main() {

    int output = druhe_najvacsie(5);
    if (output == -1) return 1;
    else printf("%d\n", output);

    output = druhe_najvacsie(3);
    if (output == -1) return 1;
    else printf("%d\n", output);

    output = druhe_najvacsie(1);
    if (output == -1) return 1;
    else printf("%d\n", output);

    return 0;
}
```

{{< /details >}}

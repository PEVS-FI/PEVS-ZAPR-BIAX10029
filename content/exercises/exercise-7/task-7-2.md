---
date: '2025-11-12T23:19:06+01:00'
title: 'Úloha 7.2'
weight: 2
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý nadväzuje na úlohu 7.1. Do alokovanej pamäte
zapíšte čísla od 1 do _n_.

Následne program vypíše na štandardný výstup adresu alokovanej pamäte a zároveň jednotlivé zapísané hodnoty aj s ich
adresou.

### Príklady vstupov / výstupov programu

Pre vstup 3 bude výpis vyzerať nasledovne:

```text
Adresa alokovanej pamäte: 0x0000475d21a
0. položka: adresa = 0x0000475d21a ; hodnota = 1
1. položka: adresa = 0x0000475d21b ; hodnota = 2
2. položka: adresa = 0x0000475d21c ; hodnota = 3
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Požiadanie používateľa o zadanie počtu prvkov
    printf("Enter the number of integers to allocate memory for: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of blocks.\n");
        return 1;
    }

    // Dynamická alokácia pamäte pre n prvkov typu int
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Výpis adresy alokovanej pamäte
    printf("Adresa alokovanej pamäte: %p\n", array);

    // Zápis čísel od 1 do n do alokovanej pamäte
    for (int i = 0; i < n; i++) {
        array[i] = i + 1; // Hodnoty od 1 do n
    }

    // Výpis jednotlivých hodnôt a ich adries
    for (int i = 0; i < n; i++) {
        printf("%d. položka: adresa = %p ; hodnota = %d\n", i, &array[i], array[i]);
    }

    // Uvoľnenie alokovanej pamäte
    free(array);

    return 0;
}
```

#### Vysvetlenie

1. Vstup od používateľa:
    * Používateľ zadá počet prvkov, pre ktoré sa má alokovať pamäť (n).

2. Dynamická alokácia pamäte:
    * malloc alokuje pamäť pre n prvkov typu int.
    * Adresa alokovanej pamäte sa vypíše na začiatku.

3. Zápis hodnôt do pamäte:
    * Do každého prvku alokovaného poľa sa zapíše hodnota od 1 po n.

4. Výpis hodnôt a ich adries:
    * Iterácia cez alokovanú pamäť vypíše pre každý prvok:
        * Index.
        * Adresu pamäte, kde sa hodnota nachádza.
        * Hodnotu prvku.

5. Uvoľnenie pamäte:
    * Dynamicky alokovaná pamäť sa uvoľní pomocou free na konci programu.

-->

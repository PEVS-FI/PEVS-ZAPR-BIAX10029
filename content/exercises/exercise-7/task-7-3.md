---
date: '2025-11-12T23:19:08+01:00'
title: 'Úloha 7.3'
weight: 3
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý nadväzuje na úlohu 7.1. Do alokovanej program
postupne vyžiada od používateľa jednotlivé čísla, ako prvky dynamického poľa.

Následne program vypíše na štandardný výstup adresu alokovanej pamäte a zároveň jednotlivé zapísané hodnoty aj s ich
adresou.

### Príklady vstupov / výstupov programu

Priebeh programu môže byť nasledovný:

```text
Zadajte počet prvkov: 3
Zadanie 1. prvok: 85
Zadanie 2. prvok: 41
Zadanie 3. prvok: -2
Adresa alokovanej pamäte: 0x000784b111
0. položka: adresa = 0x000784b111 ; hodnota = 85
1. položka: adresa = 0x000784b112 ; hodnota = 41
2. položka: adresa = 0x000784b113 ; hodnota = -2
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Požiadanie používateľa o počet prvkov
    printf("Zadajte počet prvkov: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Počet prvkov musí byť kladné číslo.\n");
        return 1;
    }

    // Dynamická alokácia pamäte pre n prvkov typu int
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Nepodarilo sa alokovať pamäť.\n");
        return 1;
    }

    // Zadanie hodnôt od používateľa
    for (int i = 0; i < n; i++) {
        printf("Zadanie %d. prvok: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Výpis adresy alokovanej pamäte
    printf("Adresa alokovanej pamäte: %p\n", array);

    // Výpis hodnôt a ich adries
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
    * Používateľ zadá počet prvkov (n).
    * Kontrola zabezpečí, že zadané číslo je kladné.

2. Dynamická alokácia pamäte:
    * Pomocou malloc sa alokuje pamäť pre n prvkov typu int.

3. Zadanie hodnôt:
    * Cyklus požaduje od používateľa hodnoty pre jednotlivé prvky dynamického poľa.

4. Výpis hodnôt a ich adries:
    * Pre každý prvok sa vypíše jeho index, adresa a hodnota.

5. Uvoľnenie pamäte:
    * Dynamicky alokovaná pamäť sa uvoľní pomocou free na konci programu.
   
-->

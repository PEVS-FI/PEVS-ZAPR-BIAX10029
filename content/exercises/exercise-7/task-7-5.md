---
date: '2025-11-12T23:19:13+01:00'
title: 'Úloha 7.5'
weight: 5
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý na začiatku alokuje pamäť o veľkosti 5 čísel
(t.j. pole veľkosti `5 * sizeof(int)`). Následne umožní používateľovi pridávať hodnoty to poľa zo štandardného vstupu.
Ak sa pole naplní, zmeňte jeho alokovanú veľkosť na dvojnásobnú aktuálnej veľkosti a umožnite používateľa ďalej zadávať
čísla. Pokračujte načítanie hodnôt pokým používateľ nezadá hodnotu **-1**, ktorý ukonči zadávanie čísel.

Na záver, program vypíše všetky načítané čísla, veľkosť a adresu alokovanej pamäte.

Nezabudnite patrične uvoľniť alokovanú pamäť a ošetriť prípady keď alokácia pamäte zlyhá.

### Príklady vstupov / výstupov programu

Priebeh programu môže byť nasledovný:

```text
Zadajte hodnoty (zadaním -1 ukončíte): 
10
20
30
40
50
60
70
-1
---
Zadané hodnoty: 10 20 30 40 50 60 70
Konečná veľkosť poľa: 10 prvkov
Adresa poľa: 0x000044781dcc
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int initial_size = 5; // Počiatočná veľkosť poľa
    int current_size = initial_size; // Aktuálna veľkosť poľa
    int *array = (int *)malloc(current_size * sizeof(int)); // Alokácia pamäte
    if (array == NULL) {
        printf("Nepodarilo sa alokovať pamäť.\n");
        return 1;
    }

    int input, count = 0;

    printf("Zadajte hodnoty (zadaním -1 ukončíte):\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }

        // Ak pole je plné, zväčšiť veľkosť na dvojnásobok
        if (count == current_size) {
            current_size *= 2;
            int *temp = (int *)realloc(array, current_size * sizeof(int));
            if (temp == NULL) {
                printf("Nepodarilo sa zväčšiť pamäť.\n");
                free(array); // Uvoľnenie pôvodnej pamäte
                return 1;
            }
            array = temp;
        }

        // Uloženie hodnoty do poľa
        array[count++] = input;
    }

    // Výpis načítaných hodnôt
    printf("---\nZadané hodnoty: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Výpis konečnej veľkosti poľa a adresy
    printf("Konečná veľkosť poľa: %d prvkov\n", current_size);
    printf("Adresa poľa: %p\n", array);

    // Uvoľnenie pamäte
    free(array);

    return 0;
}
```

#### Vysvetlenie

1. Počiatočná veľkosť poľa:

* Pamäť je alokovaná na veľkosť 5 * sizeof(int).

2. Pridávanie hodnôt:
    * Používateľ zadáva čísla, ktoré sa ukladajú do poľa.
    * Ak počet prvkov dosiahne aktuálnu veľkosť poľa, veľkosť sa zdvojnásobí pomocou funkcie realloc.

3. Zväčšenie pamäte:
    * realloc zmení veľkosť alokovanej pamäte na dvojnásobok.
      realloc je nákladná operácia a tak sa oplatí radšej alokovať dopredu väčšiu časť pamäte ako alokovať po jednom
      vstupe.
    * Ak alokácia zlyhá, program vypíše chybu a uvoľní existujúcu pamäť.

4. Ukončenie zadávania:
    * Zadanie -1 ukončí zadávanie hodnôt.

5. Výpis výsledkov:
    * Všetky načítané hodnoty sú vypísané spolu s konečnou veľkosťou poľa a adresou.

6. Uvoľnenie pamäte:
    * Alokovaná pamäť je uvoľnená pomocou free.

-->

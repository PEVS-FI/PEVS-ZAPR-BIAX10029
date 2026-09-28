---
date: '2025-10-09T10:02:09+02:00'
title: '✨ Úloha 3.8'
weight: 8
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Definujte všeobecnejšiu verziu funkciu z úlohy 3.5, **_int pocet_delitelnych(int n, int k)_**. Funkcia má 2
vstupné parametre, nezáporné celé číslo _n_ a kladné číslo _k_. Ošetrite situáciu, že by vstupný
argument pre parameter _n_ bolo záporné číslo alebo že by vstupný argument pre parameter _k_ bolo
záporné číslo alebo nula – vždy vypíšte príslušnú chybovú hlášku a funkcia vráti hodnotu -1. V
prípade, že sú vstupné argumenty v poriadku, funkcia načíta n čísiel a vráti počet načítaných čísiel,
ktoré boli deliteľné číslom k.

### Príklady vstupov / výstupov programu

- Volanie `pocet_delitelnych(5,2)` načíta 5 čísiel z klávesnice a vráti koľko z nich je deliteľných 2. Ak
  čísla sú napríklad 5,10,3,4,0 funkcia vráti číslo 3 (pretože 10, 4 a 0 sú deliteľné 2).
- Volanie `pocet_delitelnych(4,0)` vypíše chybovú správu, že hodnota k nie je kladná a vráti -1.
- Volanie `pocet_delitelnych(-1,2)` vypíše chybovú správu, že hodnota n je záporná a vráti -1.
- Volanie `pocet_delitelnych(-1,-2)` vypíše chybovú správu, že hodnota n je záporná a že hodnota k nie
  je kladná a vráti -1.

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

// Funkcia pocet_delitelnych:
// Načíta n čísel a vráti počet tých, ktoré sú deliteľné číslom k.
// Ak n < 0 alebo k <= 0, vypíše chybové hlášky a vráti -1.
int pocet_delitelnych(int n, int k) {
    int pocet = 0;
    int cislo;

    // Ošetrenie chybných vstupov
    int chyba = 0;
    if (n < 0) {
        printf("Chyba: hodnota n je záporná.\n");
        chyba = 1;
    }
    if (k <= 0) {
        printf("Chyba: hodnota k nie je kladná.\n");
        chyba = 1;
    }

    if (chyba)
        return -1;

    // Načítanie n čísel
    printf("Zadajte %d čísel:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cislo);
        if (cislo % k == 0)
            pocet++;
    }

    return pocet;
}

int main(void) {
    int n, k;
    printf("Zadajte hodnoty n a k: ");
    scanf("%d %d", &n, &k);

    int vysledok = pocet_delitelnych(n, k);
    if (vysledok != -1)
        printf("Počet čísel deliteľných %d je: %d\n", k, vysledok);

    return 0;
}
```

-->

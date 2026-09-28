---
date: '2025-10-09T10:02:00+02:00'
title: 'Úloha 3.5'
weight: 5
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Definujte funkciu **_int pocet_delitelnych_5(int n)_**, ktorá má vstupný parameter celé nezáporné číslo _n_.
Funkcia načíta n čísiel z klávesnice (ako vstup od používateľa) a vráti počet načítaných čísiel, ktoré boli deliteľné
číslom 5.
Ošetrite situáciu, ak by bola funkcia volaná so záporným vstupom! V takom prípade nech funkcia
vypíše, že vstupný argument musí byť nezáporné číslo a vráti hodnotu -1.

### Príklady vstupov / výstupov programu

- Volanie `pocet_delitelnych_5(5)` načíta 5 čísiel z klávesnice. Ak čísla sú napríklad 5,10,3,4,0 funkcia
  vráti číslo 3 (pretože 5, 10 a 0 sú deliteľné 5).
- Volanie `pocet_delitelnych_5(4)` načíta 4 čísla z klávesnice. Ak čísla sú napríklad 1,2,3,4 funkcia
  vráti číslo 0 (pretože ani jedno z čísiel nie je deliteľné 5).
- Volanie `pocet_delitelnych_5(-3)` vypíše, že vstupný argument musí byť nezáporné číslo a vráti číslo
  -1.

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int pocet_delitelnych_5(int n) {
    if (n < 0) {
        printf("Vstupný argument n musí byť nezáporné číslo\n");
        return -1;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        printf("Zadajte ľubovolné číslo: ");
        int input;
        scanf("%d", &input);
        if (input % 5 == 0) count++;
    }
    return count;
}

int main() {

    printf("%d\n", pocet_delitelnych_5(5));
    printf("%d\n", pocet_delitelnych_5(4));
    printf("%d\n", pocet_delitelnych_5(-3));

    return 0;
}
```

-->

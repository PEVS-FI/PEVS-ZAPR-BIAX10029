---
date: '2025-11-05T23:23:04+01:00'
title: 'Úloha 6.6'
weight: 6
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý definuje funkciu pre výpočet dĺžky reťazca.
Funkcia má jeden argument typu `char*` , ktorý vyjadruje reťacez znakov. Funkcia vracia hodnotu typu `int`, ktorá sa
rovná počtu znakov vo vstupnom reťazci.
Pre implementáciu **nepoužite** knižnicu `<string.h>` ani žiadnu inú okrem `<stdio.h>`.

Pri implementácií použitie inkrementáciu pointrov, resp. pričítanie čísla (_int_) k pointru.

> [!WARNING]
> Pamätajte, že každý reťazec je ukončený znakom `\0`.

### Príklady vstupov / výstupov programu

- pre vstupný reťacez "Milan" funkcia vráti 5
- pre vstupný reťacez "Cvicenie6" funkcia vráti 9
- pre vstupný reťacez "" funkcia vráti 0

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

// Funkcia na výpočet dĺžky reťazca
int stringLength(char *str) {
    int length = 0;

    // Inkrementácia pointeru, kým nedosiahne nulový znak '\0'
    while (*str != '\0') {
        length++;
        str++; // Posun pointera na ďalší znak
    }

    return length;
}

int main() {
    // Testovacie reťazce
    char str1[] = "Milan";
    char str2[] = "Cvicenie7";
    char str3[] = "";

    // Výstupy funkcie pre rôzne vstupy
    printf("The length of the string \"%s\" is %d\n", str1, stringLength(str1));
    printf("The length of the string \"%s\" is %d\n", str2, stringLength(str2));
    printf("The length of the string \"%s\" is %d\n", str3, stringLength(str3));

    return 0;
}
```

#### Vysvetlenie

1. Funkcia stringLength:
    * Prijíma jeden argument typu char*, ktorý ukazuje na reťazec znakov.
    * Používa while cyklus na iteráciu cez znaky reťazca.
    * Pointer str sa posúva na ďalšiu pozíciu pomocou str++, kým nedosiahne koncový nulový znak '\0'.
    * Premenná length sa inkrementuje pri každom kroku, čím uchováva počet znakov v reťazci.

2. Hlavný program:
    * Testuje funkciu s rôznymi vstupnými reťazcami vrátane prázdneho reťazca.
    * Výsledky funkcie sa vypisujú na štandardný výstup.

3. Obmedzenia:
    * Funkcia nevyžaduje žiadne externé knižnice okrem <stdio.h>.
    * Reťazec musí byť ukončený nulovým znakom '\0' (čo je štandard pre reťazce v C).

-->

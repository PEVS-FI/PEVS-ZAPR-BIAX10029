---
date: '2025-11-12T23:39:41+01:00'
title: '🗓️ Úloha 8.3'
weight: 3
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý definuje štruktúru na reprezentáciu dátumu s
položkami:

- _deň_ (celé číslo)
- _mesiac_ (celé číslo)
- _rok_ (celé číslo)

Program by mal umožniť používateľovi zadať dva dátumy kde jednotlivé hodnoty dátumov sú
definované v jednom riadku oddelené medzerou
a vypočítať rozdiel medzi nimi. Rozdieľ je vypísaný ako počet dní medzi dátumami.

V programe ošetrite vstup od používateľa aby bolo možné zadať iba správny dátum (napríklad nie je možné zadať 31.2.) a
zohľadňuje priestupné roky.

### Príklady vstupov / výstupov programu

Priebeh programu môže vyzerať nasledovne:

```text
Prvý dátum: 1 1 2023
Druhý dátum: 15 1 2024
---
Rozdiel dátumov: 376 dní
```

```text
Prvý dátum: 28 2 2020
Druhý dátum: 1 3 2020
---
Rozdiel dátumov: 2 dni
```

### Bonus

Skúste upraviť výpis rozdielu dátumov tak aby uviedol pre používateľa rozdiel aj koľko prípadných rokov, mesiacov, či
dní je medzi dátumami. Napríklad:

- vstup: 1.1.2023 a 15.1.2024 -> 1 rok a 15 dní
- vstup: 1.1.2022 a 5.3.2022 -> 2 mesiace a 5 dní

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>

// Štruktúra na reprezentáciu dátumu
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Počet dní v mesiacoch (pre bežné a priestupné roky)
const int daysInMonth[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // Bežný rok
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // Priestupný rok
};

// Funkcia na kontrolu, či je rok priestupný
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Funkcia na validáciu dátumu
int isValidDate(Date date) {
    if (date.year < 1 || date.month < 1 || date.month > 12 || date.day < 1) {
        return 0;
    }
    int leap = isLeapYear(date.year);
    if (date.day > daysInMonth[leap][date.month - 1]) {
        return 0;
    }
    return 1;
}

// Funkcia na prepočet dátumu na počet dní od začiatku referenčného bodu (napr. 1.1.0001)
int dateToDays(Date date) {
    int totalDays = 0;

    // Pridanie dní za celé roky
    for (int i = 1; i < date.year; i++) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }

    // Pridanie dní za celé mesiace v aktuálnom roku
    int leap = isLeapYear(date.year);
    for (int i = 0; i < date.month - 1; i++) {
        totalDays += daysInMonth[leap][i];
    }

    // Pridanie dní v aktuálnom mesiaci
    totalDays += date.day;

    return totalDays;
}

// Funkcia na výpočet rozdielu medzi dvoma dátumami
int calculateDateDifference(Date date1, Date date2) {
    int days1 = dateToDays(date1);
    int days2 = dateToDays(date2);
    return abs(days1 - days2);
}

int main() {
    Date date1, date2;

    // Načítanie prvého dátumu
    printf("Prvý dátum (deň mesiac rok): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);
    if (!isValidDate(date1)) {
        printf("Neplatný dátum! Zadajte správny dátum.\n");
        return 1;
    }

    // Načítanie druhého dátumu
    printf("Druhý dátum (deň mesiac rok): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);
    if (!isValidDate(date2)) {
        printf("Neplatný dátum! Zadajte správny dátum.\n");
        return 1;
    }

    // Výpočet a výpis rozdielu
    int difference = calculateDateDifference(date1, date2);
    printf("---\nRozdiel dátumov: %d dní\n", difference);

    return 0;
}
```

#### Vysvetlenie

1. Štruktúra Date:
    * Reprezentuje dátum s položkami day, month a year.

2. Priestupný rok:
    * Funkcia isLeapYear kontroluje, či je rok priestupný, na základe pravidiel pre gregoriánsky kalendár.

3. Validácia dátumu:
    * Funkcia isValidDate overuje, či zadaný dátum je platný (správny rozsah dní, mesiacov a rokov).

4. Prepočet dátumu na počet dní:
    * Funkcia dateToDays konvertuje dátum na celkový počet dní od referenčného bodu (1.1.0001).
    * Zahŕňa dni za celé roky, mesiace a aktuálny deň.

5. Rozdiel medzi dátumami:
    * Funkcia calculateDateDifference vypočíta rozdiel v počte dní medzi dvoma dátumami.

6. Hlavný program:
    * Používateľ zadá dva dátumy, ktoré sa validujú.
    * Po výpočte rozdielu v dňoch je výsledok vypísaný.

-->

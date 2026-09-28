---
date: '2025-11-12T23:39:37+01:00'
title: 'Úloha 8.1'
weight: 1
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý vytvorí štruktúru na reprezentáciu študenta.

Táto štruktúra by mala obsahovať nasledujúce položky:

- _meno_ (pole znakov)
- _vek_ (celé číslo)
- _priemerný prospech_ (desatinné číslo)

Program by mal načítať údaje študentov, vypočítať priemerný vek a priemerný prospech všetkých študentov a tieto hodnoty
vypísať.

Vstupy programu môžu byť zadané zo štandardného vstupu alebo načítané zo súboru.

### Príklady vstupov / výstupov programu

Pre nasledujúce vstupy programu:

```text
1. Študent
Meno: Ján 
Vek: 20 
Priemerný prospech: 1.5
---
2. Študent
Meno: Petra 
Vek: 22 
Priemerný prospech: 1.8
---
3. Študent
Meno: Milan 
Vek: 19 
Priemerný prospech: 2.0
---
```

Program vypíše na štandardný výstup nasledovný výstup:

```text
Sumár študentov:
Priemerný vek: 20.33 Priemerný prospech: 1.77
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

// Definícia štruktúry pre reprezentáciu študenta
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float averageGrade;
} Student;

int main() {
    int numStudents;
    printf("Zadajte počet študentov: ");
    scanf("%d", &numStudents);

    if (numStudents <= 0) {
        printf("Počet študentov musí byť kladné číslo.\n");
        return 1;
    }

    // Dynamická alokácia poľa študentov
    Student *students = (Student *)malloc(numStudents * sizeof(Student));
    if (students == NULL) {
        printf("Nepodarilo sa alokovať pamäť.\n");
        return 1;
    }

    // Načítanie údajov študentov
    for (int i = 0; i < numStudents; i++) {
        printf("\n%d. Študent\n", i + 1);
        printf("Meno: ");
        scanf(" %49s", students[i].name); // Obmedzenie na MAX_NAME_LENGTH - 1 znakov
        printf("Vek: ");
        scanf("%d", &students[i].age);
        printf("Priemerný prospech: ");
        scanf("%f", &students[i].averageGrade);
    }

    // Výpočet priemerného veku a priemerného prospechu
    float totalAge = 0, totalGrade = 0;
    for (int i = 0; i < numStudents; i++) {
        totalAge += students[i].age;
        totalGrade += students[i].averageGrade;
    }

    float averageAge = totalAge / numStudents;
    float averageGrade = totalGrade / numStudents;

    // Výpis výsledkov
    printf("\nSumár študentov:\n");
    printf("Priemerný vek: %.2f\n", averageAge);
    printf("Priemerný prospech: %.2f\n", averageGrade);

    // Uvoľnenie pamäte
    free(students);

    return 0;
}
```

#### Vysvetlenie

1. Definícia štruktúry:
    * Štruktúra Student obsahuje položky name (pole znakov), age (vek), a averageGrade (priemerný prospech).

2. Načítanie počtu študentov:
    * Používateľ zadáva počet študentov.
    * Pamäť pre pole študentov je dynamicky alokovaná pomocou malloc.

3. Načítanie údajov:
    * V cykle sa načítavajú údaje pre každého študenta.
    * Funkcia scanf obmedzuje dĺžku vstupu pre meno na maximálne 49 znakov (jeden znak je rezervovaný pre \0).

4. Výpočty:
    * Po načítaní údajov sa vypočíta priemerný vek a priemerný prospech pomocou súčtov všetkých hodnôt.

5. Výpis a uvoľnenie pamäte:
    * Priemerné hodnoty sú vypísané s presnosťou na dve desatinné miesta.
    * Dynamicky alokovaná pamäť sa uvoľní pomocou free.

-->

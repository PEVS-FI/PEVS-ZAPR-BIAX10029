---
date: '2025-11-12T23:39:39+01:00'
title: 'Úloha 8.2'
weight: 2
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý vytvorí štruktúru na reprezentáciu zamestnanca.

Štruktúra by mala obsahovať:

- _meno_ (pole znakov)
- _identifikačné číslo_ (celé číslo)
- _plat_ (desatinné číslo)

Program by mal načítať údaje pre niekoľko zamestnancov, zoradiť ich podľa platu zostupne a
vypísať zoznam zamestnancov spolu s ich platmi. Následne program vypíše priemerný plat zamestnancov.

Údaje o zamestnancoch načítajte zo súboru, kde na jednom riadku je definovaný jeden zamestnanec a hodnoty na riadku sú
oddelené medzerou: `ID Meno Plat`

Cestu k súboru načítajte od používateľa zo štandardného vstupu na začiatku programu.

### Príklady vstupov / výstupov programu

Program pre vstupný súbor:

```text
101 Anna 2500.50
102 Peter 3000.75
103 Lucia 2800.00
```

vypíše nasledovný text na výstupe:

```text
102 Peter 3000.75
103 Lucia 2800.00
101 Anna 2500.50
---
Priemerný plat: 2767.08
```

### Bonus

Skúste upraviť výpis tak aby mal formát tabuľky. Nezabudnite na správne zarovnanie stĺpcov. Takýto výstup by mohol
vyzerať nasledovne:

```text
|ID  |Meno  |Plat    |
|----|------|--------|
|102 |Peter |3000.75 |
|103 |Lucia |2800.00 |
|101 |Anna  |2500.50 |
---
Priemerný plat: 2767.08
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMPLOYEES 100

// Definícia štruktúry na reprezentáciu zamestnanca
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float salary;
} Employee;

// Funkcia na porovnanie zamestnancov podľa platu (pre qsort)
int compareBySalaryDescending(const void *a, const void *b) {
    float salaryA = ((Employee *)a)->salary;
    float salaryB = ((Employee *)b)->salary;
    if (salaryA < salaryB) return 1;
    if (salaryA > salaryB) return -1;
    return 0;
}

int main() {
    char filePath[100];
    Employee employees[MAX_EMPLOYEES];
    int count = 0;

    // Načítanie cesty k súboru
    printf("Zadajte cestu k súboru: ");
    scanf("%s", filePath);

    // Otvorenie súboru
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Nepodarilo sa otvoriť súbor.\n");
        return 1;
    }

    // Načítanie údajov zo súboru
    while (fscanf(file, "%d %49s %f", &employees[count].id, employees[count].name, &employees[count].salary) == 3) {
        count++;
        if (count >= MAX_EMPLOYEES) {
            printf("Dosiahnutý maximálny počet zamestnancov (%d).\n", MAX_EMPLOYEES);
            break;
        }
    }
    fclose(file);

    if (count == 0) {
        printf("Súbor neobsahuje žiadne údaje o zamestnancoch.\n");
        return 1;
    }

    // Zoradenie zamestnancov podľa platu zostupne
    qsort(employees, count, sizeof(Employee), compareBySalaryDescending);

    // Výpočet priemerného platu
    float totalSalary = 0;
    for (int i = 0; i < count; i++) {
        totalSalary += employees[i].salary;
    }
    float averageSalary = totalSalary / count;

    // Výpis zamestnancov
    printf("\n");
    for (int i = 0; i < count; i++) {
        printf("%d %s %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    // Výpis priemerného platu
    printf("---\n");
    printf("Priemerný plat: %.2f\n", averageSalary);

    return 0;
}
```

#### Vysvetlenie

1. Definícia štruktúry:
    * Štruktúra Employee obsahuje ID, meno a plat zamestnanca.

2. Načítanie údajov zo súboru:
    * Súbor je otvorený v režime čítania pomocou fopen.
    * Hodnoty sú načítané pomocou fscanf, kde sa očakáva formát ID Meno Plat.

3. Kontrola limitov:
    * Ak súbor neobsahuje údaje alebo je dosiahnutý maximálny počet zamestnancov (MAX_EMPLOYEES), program končí s
      príslušnou správou.

4. Zoradenie:
    * qsort zoradí zamestnancov podľa platu v zostupnom poradí pomocou funkcie compareBySalaryDescending.

5. Výpočet priemerného platu:
    * Priemerný plat sa vypočíta ako súčet platov všetkých zamestnancov delený ich počtom.

6. Výpis výsledkov:
    * Zoradení zamestnanci sú vypísaní spolu s ich ID, menom a platom.
    * Priemerný plat je vypísaný s presnosťou na dve desatinné miesta.

7. Uvoľnenie zdrojov:
    * Súbor je zavretý po načítaní údajov.

-->

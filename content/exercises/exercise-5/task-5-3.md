---
date: '2025-10-22T22:54:57+02:00'
title: 'Úloha 5.3'
weight: 3
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý načíta súbor _vypocty.txt_ a pokračuje v jeho
zapisovaní.

Program na začiatku načíta súbor _vypocty.txt_. Ak súbor neexistuje vytvorí ho. Ak súbor existuje načíta postupne z neho
všetky výpočty
a zvaliduje či sú správne vypočítané, t.j. či z načítanej trojice čísel v riadku súčet prvých dvoch čísiel sa rovná
tretiemu číslu.
Ak kontrola narazí na nesprávny výpočet tak na to upozorní používateľa vypísaním načítaných čísel a chybovou správou,
program však pokračuje ďalej. Keď program načíta všetky existujúce výpočty vypíše koľko výpočtov načítal na obrazovku.

Program následne pokračuje v rovnakej činnosti ako v [úlohe 5.2](/exercises/exercise-5/task-5-2) s opýtaním sa používateľa o dve čísla a vypočíta ich
súčet.
Výpočet potom zapíše na koniec súboru. Existujúce dáta nesmú byť prepísané. Formát súboru _vypocty.txt_ musí byť
zachovaný
ako je v [úlohe 5.2](/exercises/exercise-5/task-5-2).

> [!WARNING]
> Dávajte si pozor na mód pod ktorým otvárate súbor a na zatvorenie súboru pred skončením programu.

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_input(char *message) {
    char input[100];
    printf("%s", message);
    scanf("%s", input);
    if (input[0] == 'q') return INT_MIN;
    return atoi(input);
}

void verify_file(FILE *file) {
    int a, b, result;
    int read = 0;
    int line = 1;
    while ((read = fscanf(file, "%d %d %d\n", &a, &b, &result)) != EOF) {
        if (a + b != result) {
            printf("Chyba na riadku %d. %d + %d != %d (správne %d)\n", line, a, b, result, a + b);
        }
        line++;
    }
    printf("Načítaných %d výpočtov zo súboru\n", line-1);
}

int main() {
    FILE *file = fopen("../vypocty.txt", "a+");
    if (file == NULL) return 1;

    verify_file(file);

    while (1) {
        int a, b, result;
        a = get_input("Zadajte prvé číslo pre súčet: ");
        if (a == INT_MIN) break;
        b = get_input("Zadajte druhé číslo pre súčet: ");
        result = a + b;
        printf("%d + %d = %d\n", a, b, result);
        fprintf(file, "%d %d %d\n", a, b, result);
        printf("-------------\n");
    }

    fclose(file);
    return 0;
}
```
-->

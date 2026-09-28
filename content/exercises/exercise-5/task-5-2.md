---
date: '2025-10-22T22:54:54+02:00'
title: 'Úloha 5.2'
weight: 2
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý zapíše do súboru výpočty, ktoré zadá používateľ.
Program bude sčítavať dve čísla, ktoré zadá používateľ a vypíše ich výsledok na štandardný výstup a zároveň zapíše
výpočet do súboru.
Program si pýta dve čísla pre výpočet v cykle do nekonečna pokiaľ používateľ namiesto prvého čísla nezadá znak _'q'_.

Výpočet je uložený do súboru ako trojica čísel oddelená medzerou. Každý výpočet je uložený do nového riadku.
Výpočty ukladajte do súboru _**vypocty.txt**_ do rovnakého priečinku ako je váš zdrojový súbor `main.c` .
Ak súbor neexistuje, vytvorte ho programom. Ak súbor pri otvorení existuje prepíšte jeho existujúce dáta novými.

> [!WARNING]
> Dávajte si pozor na zatvorenie súboru pred skončením programu.

### Príklady vstupov / výstupov programu

Ak vstupy od používateľa pre výpočty boli v nasledovnom poradí:

- 5 a 3
- 8 a 7
- 21 a 56

Program by mal vytvoriť súbor _vypocty.txt_ s nasledovným obsahom:

```text
5 3 8
8 7 15
21 56 77
```

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

int main() {
    FILE *file = fopen("vypocty.txt", "w+");
    if (file == NULL) return 1;

    while (1) {
        int a, b, result;
        a = get_input("Zadajte prvé číslo pre súčet: ");
        if(a == INT_MIN) break;
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

---
date: '2026-09-28'
title: 'Čítanie a zápis do súboru'
weight: 1
---


Otvorenie súboru pre čítanie aj zápis v režime w+.

```c
#include <stdio.h>

int main() {
    int pocet, stav;
    FILE *f;
    f = fopen("konta.txt", "w+");

    fscanf(f, "%d\n", &pocet);
    printf("pocet = %d\n", pocet);

    /*for (int i = 0; i < pocet; i++)
	{
		fscanf(f, "%d\n", &stav);
		printf("Stav konta %d = %d\n", i, stav);
	}
	*/

    for (int i = 0; i < pocet; i++) {
        printf("zadaj stav konta s poradovym cislom %d: ", i);
        scanf("%d", &stav);
        fprintf(f, "%d\n", stav);
    }

    fclose(f);

    return 0;
}
```

[Stiahnuť zdrojový kód](../citanie_zapis.c)

### Vysvetlenie

Program otvorí súbor `konta.txt` v režime `w+`, ktorý umožňuje čítanie aj zápis. Načíta počet záznamov, potom od
používateľa načíta stav konta pre každý záznam a zapíše ich do súboru pomocou `fprintf`.

Príklad ukazuje kombinovanú prácu so súborom a obsahuje aj zakomentovaný variant čítania hodnôt zo súboru pomocou
`fscanf`.

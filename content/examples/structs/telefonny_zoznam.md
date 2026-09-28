---
date: '2026-09-28'
title: 'Telefónny zoznam (trieda)'
weight: 1
---


Jednoduchý telefónny zoznam implementovaný pomocou triedy.

```cpp
#include <stdio.h>
#include <string.h>

class Zaznam {
public:
    char meno[21], priezvisko[21], cislo[21];
};


Zaznam vloz() {
    Zaznam z;
    printf("Meno: ");
    scanf("%20s", (z).meno);
    printf("Priezvisko: ");
    scanf("%20s", (z).priezvisko);
    printf("Telefonne cislo: ");
    scanf("%20s", (z).cislo);
    return z;
}

void vypis(Zaznam z) {
    printf("%s, %s, %s\n", z.meno, z.priezvisko, z.cislo);
}

int main() {
    Zaznam zoznam[100];
    int pocet = 0, volba, nasiel_som = 0;
    char priezvisko[21];

    do {
        printf("1-zadanie zaznam\n2-hladanie\n3-vypis vsetkych\n");
        scanf("%d", &volba);
        switch (volba) {
            case 1: if (pocet < 100) {
                    zoznam[pocet] = vloz();
                    pocet++;
                } else
                    printf("nedostatok miesta\n");
                break;
            case 2: printf("zadaj priezvisko: ");
                scanf("%20s", priezvisko);
                nasiel_som = 0;
                for (int i = 0; i < pocet; i++) {
                    if (strcmp(priezvisko, zoznam[i].priezvisko) == 0) {
                        vypis(zoznam[i]);
                        nasiel_som = 1;
                    }
                }
                if (!nasiel_som)
                    printf("nemam v zozname priezvisko %s\n", priezvisko);
                break;
            case 3: for (int i = 0; i < pocet; i++)
                    vypis(zoznam[i]);
                break;
        }
    } while (volba == 1 || volba == 2 || volba == 3);


    return 0;
}
```

[Stiahnuť zdrojový kód](../telefonny_zoznam.cpp)

### Vysvetlenie

Príklad definuje triedu `Zaznam`, ktorá predstavuje jeden záznam v telefónnom zozname s menom, priezviskom a telefónnym
číslom. Program umožňuje pridávať záznamy, vyhľadávať ich podľa priezviska a vypisovať celý zoznam.

Ukazuje základ objektovo orientovaného prístupu v C++ – definíciu triedy, jej použitie v poli a volanie metód nad
objektami.

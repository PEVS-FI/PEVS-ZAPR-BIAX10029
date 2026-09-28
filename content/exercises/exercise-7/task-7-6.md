---
date: '2025-11-12T23:19:15+01:00'
title: 'Úloha 7.6'
weight: 6
---

Majme nasledujúci program:

```C
void runMe(){
    int* leakingPtr = (int*) malloc(sizeof(int) * 1024);
    for(int i=0; i < 1024; i++){
        leakingPtr[i] = i + 1000;
    }
}

int main(){
    runMe();
    return 0;
}
```

1. Ako vyzerá alokovaná pamäť program pred a po volaní funkcie `runMe`?
2. Čo je zlé s funkciou `runMe`? (minimálne 2 veci)
3. Prepíšte program tak aby bol korektný.

---

Tu neskôr pribudne príkladné riešenie

<!--

#### Problémy s funkciou

1. Únik pamäte:
    * Alokovaná pamäť pomocou malloc nie je uvoľnená pred ukončením funkcie. Tým sa stráca možnosť k nej pristúpiť, čo
      vedie k úniku pamäte.

2. Žiadna kontrola úspešnosti alokácie:
    * Funkcia malloc môže zlyhať a vrátiť NULL. Program toto nezohľadňuje, čo môže spôsobiť segfault alebo
      nepredvídateľné správanie, ak sa pamäť pokúsi použiť.

#### Opravy

```C
#include <stdio.h>
#include <stdlib.h>

void runMe() {
    // Alokácia pamäte
    int* leakingPtr = (int*) malloc(sizeof(int) * 1024);
    if (leakingPtr == NULL) {
        printf("Nepodarilo sa alokovať pamäť.\n");
        return;
    }

    // Naplnenie pamäte hodnotami
    for (int i = 0; i < 1024; i++) {
        leakingPtr[i] = i + 1000;
    }

    // Použitie alokovaných hodnôt (napr. výpis prvých niekoľkých hodnôt)
    for (int i = 0; i < 5; i++) {
        printf("Value at index %d: %d\n", i, leakingPtr[i]);
    }

    // Uvoľnenie pamäte
    free(leakingPtr);
}

int main() {
    runMe();
    return 0;
}
```

1. Uvoľnenie pamäte:
    * Pridané volanie free(leakingPtr) pred ukončením funkcie runMe zabezpečí, že alokovaná pamäť nebude ponechaná na
      heap.

2. Kontrola úspešnosti malloc:
    * Pred použitím pointera leakingPtr sa kontroluje, či alokácia bola úspešná (leakingPtr != NULL).

#### Príklad výstupu

```text
Value at index 0: 1000
Value at index 1: 1001
Value at index 2: 1002
Value at index 3: 1003
Value at index 4: 1004
```

-->

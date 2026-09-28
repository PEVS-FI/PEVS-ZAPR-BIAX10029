---
date: '2025-11-12T23:19:11+01:00'
title: 'Úloha 7.4'
weight: 4
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý načíta od používateľa počet slov `int n` (_n_ je
zadané od používateľa)
a ich maximálnu dĺžku `int maxLen`. Následne program dynamicky alokuje pole reťazcov. Pre každé slovo alokuje novú
dynamickú pamäť pre samotný reťazec ako prvok poľa. Slovo má maximálne dĺžku definovanú používateľom.

Program postupne od používateľa načíta _n_ slov. Po načítaní všetkách slov vypíše načítané slová a ich dĺžky.

> [!TIP]
> Pre získanie dĺžky reťazcov je možné použiť funkciu `strlen` z knižnice `<string.h>`

### Príklady vstupov / výstupov programu

Priebeh programu môže byť nasledovný:

```text
Zadajte počet slov: 3
Zadajte maximálnu dĺžku slova: 10
Zadajte slová:
ahoj
programovanie
C
---
Slová a ich dĺžky:
ahoj (4 znaky)
programovanie (13 znakov)
C (1 znak)
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, maxLen;

    // Načítanie počtu slov a maximálnej dĺžky slova od používateľa
    printf("Zadajte počet slov: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Počet slov musí byť kladné číslo.\n");
        return 1;
    }

    printf("Zadajte maximálnu dĺžku slova: ");
    scanf("%d", &maxLen);

    if (maxLen <= 0) {
        printf("Maximálna dĺžka slova musí byť kladné číslo.\n");
        return 1;
    }

    // Alokácia poľa pointerov na reťazce
    char **words = (char **)malloc(n * sizeof(char *));
    if (words == NULL) {
        printf("Nepodarilo sa alokovať pamäť pre pole slov.\n");
        return 1;
    }

    // Načítanie slov od používateľa
    printf("Zadajte slová:\n");
    for (int i = 0; i < n; i++) {
        // Alokácia pamäte pre jednotlivé slovo (s miestom pre '\0')
        words[i] = (char *)malloc((maxLen + 1) * sizeof(char));
        if (words[i] == NULL) {
            printf("Nepodarilo sa alokovať pamäť pre slovo %d.\n", i + 1);
            return 1;
        }

        // Načítanie slova
        printf("Slovo %d: ", i + 1);
        scanf("%s", words[i]);
    }

    // Výpis slov a ich dĺžok
    printf("---\nSlová a ich dĺžky:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (%zu znakov)\n", words[i], strlen(words[i]));
    }

    // Uvoľnenie alokovanej pamäte
    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
```

#### Vysvetlenie

1. Vstup od používateľa:
    * Používateľ zadáva počet slov (n) a maximálnu dĺžku slova (maxLen).
    * Oba vstupy sú validované, aby boli kladné.

2. Dynamická alokácia:
    * Pole words je alokované pre n pointerov na reťazce.
    * Pre každý reťazec v poli je alokovaná pamäť veľkosti maxLen + 1 (pre \0).

3. Načítanie slov:
    * Každé slovo je načítané pomocou scanf a uložené v alokovanej pamäti.

4. Výpis slov a ich dĺžok:
    * Funkcia strlen z knižnice <string.h> sa používa na získanie dĺžky reťazca.

5. Uvoľnenie pamäte:
    * Pre každé slovo sa pamäť uvoľní pomocou free, potom sa uvoľní pamäť pre pole pointerov.

-->

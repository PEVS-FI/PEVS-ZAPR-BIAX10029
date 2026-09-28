---
date: '2025-10-22T22:54:51+02:00'
title: 'Úloha 5.1'
weight: 1
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý otvorí existujúci súbor **_data.txt_**,
načíta všetky údaje a vypíše ich na štandardný výstup.

Dáta zo súboru načítajte po riadkoch a každý riadok hneď po načítaní vypíšte. Snažte sa implementáciu spraviť tak aby
v jednom momente bol načítaný len jeden riadok.

> [!TIP]
> Nezabudnite si pred spustením program vytvoriť súbor _data.txt_ v tom istom priečinku ako zdrojový súbor `main.c` .

### Obsah súboru _data.txt_

```text
Na prvé cvičenie prišli všetci.
Na druhé už o niečo menej.
Na tretie už o málo menej.
Na štvrté prišli tí, ktorí sa chcú niečo naučiť. 
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) return 1;

    int character_limit = 100;
    char line[character_limit];
    while (1) {
        char *result = fgets(line, character_limit, file);
        if (result == NULL) break;
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
```

-->

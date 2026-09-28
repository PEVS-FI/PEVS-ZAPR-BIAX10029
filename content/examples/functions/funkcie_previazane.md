---
date: '2026-09-28'
title: 'Deklarácie a definície funkcií'
weight: 1
---


Predbežné deklarácie funkcií vz. ich definície.

```c
#include <stdio.h>

// --- DEFINICIE ---

int druha(int i);

int i = 5;

// --- IMPLEMENTACIA ---

void prva() {
    int i = 3;
    i = druha(i);
}

int druha(int i) {
    printf("tlacenka %d", 2 * i);
    return 2 * i;
}

int main() {
    prva();
}
```

[Stiahnuť zdrojový kód](../funkcie_previazane.c)

### Vysvetlenie

Príklad rozdeľuje kód na deklarácie (prototypy) funkcií a ich definície. Funkcia `prva` volá funkciu `druha`, ktorá je
deklarovaná skôr, než je definovaná, čo umožňuje vzájomné volanie funkcií.

Zároveň ilustruje platnosť lokálnych premenných – globálna premenná `i` a lokálna premenná `i` v tele funkcie sú
odlišné.

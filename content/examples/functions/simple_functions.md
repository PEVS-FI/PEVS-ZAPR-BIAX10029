---
date: '2026-09-28'
title: 'Jednoduché funkcie a prototypy'
weight: 1
---


Základná ukážka volania jednoduchých funkcií.

```c
#include <stdio.h>

void druha();

void prva();

int main() {
    prva();
    return 0;
}

void prva() {
    druha();
}

void druha() {
    printf("foo");
}
```

[Stiahnuť zdrojový kód](../simple_functions.c)

### Vysvetlenie

Príklad definuje dve jednoduché funkcie `prva` a `druha`, ktoré sa vzájomne volajú, a demonštruje ich predbežné
deklarácie (prototypy) pred použitím.

Ide o najzákladnejšiu ukážku štruktúry programu rozdeleného do funkcií – deklarácia, definícia a volanie.

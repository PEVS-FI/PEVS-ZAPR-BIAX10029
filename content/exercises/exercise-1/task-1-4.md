---
date: '2025-09-24T23:00:05+02:00'
title: 'Úloha 1.4'
weight: 4
---

Napíšte program, ktorý prehodí hodnoty medzi dvomi premennými a vypíše ich.
Premenné sú typu **int** a ich hodnota je zadaná používateľov po spustení programu.

### Príklady vstupov / výstupov programu

Ak používateľ zadaná hodnotu prvej premennej _5_ a druhej premennej _8_, po zadaní druhej premennej je vypísaný výstup
po prehodení hodnôt, teda prvá premenná bude mať hodnotu _8_ a druhá premenná hodnotu _5_.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main()
{
    int prva;
    int druha;
    
    printf("Zadajte prvú hodnotu: ");
    scanf("%d",&prva);
    
    printf("Zadajte druhú hodnotu: ");
    scanf("%d",&druha);
    
    int odlozena = prva;
    prva = druha;
    druha = odlozena;
    
    printf("Prehodené hodnoty sú: prvá=%d, druhá=%d",prva, druha);
    
    return 0;
}
```

{{< /details >}}

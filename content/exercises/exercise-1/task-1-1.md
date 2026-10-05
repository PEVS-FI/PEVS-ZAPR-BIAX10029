---
date: '2025-09-24T22:59:46+02:00'
title: 'Úloha 1.1'
weight: 1
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Program obsahuje premennú _strana_a_. Do tejto premennej sa priamo v zdrojovom kóde priradí
nejaká hodnota predstavujúca veľkosť strany štvorca. Program najprv vypíše obvod a potom obsah
daného štvorca.

### Príklady vstupov / výstupov programu

Ak sa do premennej _strana_a_ priradí hodnota 5, potom obvod takého štvorca je 20 a obsah takého
štvorca je 25. Program by teda pre situáciu, že v premennej a je uložená hodnota 5, mal vypísať na
obrazovku čísla 20 a 25.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main()
{
    int strana_a = 5;
    
    printf("Veľkosť strany štvorca: %d\n",strana_a);
    printf("Obvod štvorca: %d\n", 4 * strana_a);
    printf("Obsah štvorca: %d\n", strana_a * strana_a);
    return 0;
}
```

{{< /details >}}

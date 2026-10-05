---
date: '2025-09-24T23:00:03+02:00'
title: 'Úloha 1.3'
weight: 3
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Program obsahuje premennú sekundy. Do tejto premennej sa priamo v zdrojovom kóde priradí
číselná hodnota predstavujúca ubehnutý čas v sekundách. Program vypíše, koľko hodín / minút /
sekúnd predstavuje hodnota v premennej sekundy.

### Príklady vstupov / výstupov programu

1) Ak je v premennej sekundy hodnota 5043, program vypíše:

```shell
   1
   24
   3
```

pretože 5043 sekúnd predstavuje 1 hodinu, 24 minút a 3 sekundy.

2) Ak je v premennej sekundy hodnota 3012, program vypíše:

```shell
   0
   50
   12
```

pretože 3012 sekúnd predstavuje 0 hodín, 50 minút a 12 sekúnd.

3) Ak je v premennej sekundy hodnota 10000, program vypíše:

```shell
   2
   46
   40
```

pretože 10000 sekúnd predstavuje 2 hodiny, 46 minút a 40 sekúnd.

> [!TIP]
> Zvyšok po delení sa dá zistiť pomocou operátora %, t.j. napr. výraz 110 % 4 má hodnotu 2, pretože 110 po delení 4 má
> zvyšok 2.

### Bonus na precvičenie

Skús zapojiť trochu tvorivosti a naformátujte výstup používateľovi v rôznych podobách.
Rôzne špecifikácii formátu môžte nájsť v [tejto dokumentácii](https://cplusplus.com/reference/cstdio/printf/).

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main()
{
    int sekundy = 10000;
    
    int hodiny, minuty, zvysne_sekundy;
    
    hodiny = sekundy / 3600;
    minuty = (sekundy % 3600) / 60;
    zvysne_sekundy = sekundy % 60;
    
    printf("Vstupný počet sekúnd: %d\n",sekundy);
    printf("hodiny: %d\n",hodiny);
    printf("minúty: %d\n", minuty);
    printf("sekundy: %d\n", zvysne_sekundy);
    return 0;
}
```

{{< /details >}}

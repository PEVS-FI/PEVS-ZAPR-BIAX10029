---
date: '2025-11-05T23:22:57+01:00'
title: 'Úloha 6.3'
weight: 3
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý pomocou operátorov `&` a `*` vypíše nižšie
uvedené reťazce.
Program definuje premennú _int m_, _float f_ a _char c_ inicializované na nasledovné hodnoty:

- m = 300
- f = 256.450001
- c = "z"

> [!TIP]
> Pamätajte, že operátor & je na získanie adresy premennej a operátor * na získanie hodnoty uloženej na adrese.

Program by mal vypísať na štandardný výstup nasledovné:

```text
m = <hodnota>
fx = <hodnota> 
cht = <hodnota>

Using & operator : 
----------------------- 
address of m = <adresa>
address of fx = <adresa> 
address of cht = <adresa>

Using & and * operator : 
----------------------------- 
value at address of m = <hodnota>
value at address of fx = <hodnota>
value at address of cht = <hodnota>

Using only pointer variable :
----------------------------------
address of m = <adresa>
address of fx = <adresa> 
address of cht = <adresa>

Using only pointer operator :
----------------------------------
value at address of m = <hodnota>
value at address of fx= <hodnota> 
value at address of cht= <hodnota> 
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int main() {
    // Definícia a inicializácia premenných
    int m = 300;
    float f = 256.450001;
    char c = 'z';

    // Pointery na jednotlivé premenné
    int *p_m = &m;
    float *p_f = &f;
    char *p_c = &c;

    // Výpis hodnôt premenných
    printf("m = %d\n", m);
    printf("fx = %.6f\n", f);
    printf("cht = %c\n\n", c);

    // Použitie operátora &
    printf("Using & operator :\n");
    printf("-----------------------\n");
    printf("address of m = %p\n", &m);
    printf("address of fx = %p\n", &f);
    printf("address of cht = %p\n\n", &c);

    // Použitie operátorov & a *
    printf("Using & and * operator :\n");
    printf("-----------------------------\n");
    printf("value at address of m = %d\n", *(&m));
    printf("value at address of fx = %.6f\n", *(&f));
    printf("value at address of cht = %c\n\n", *(&c));

    // Použitie iba pointerových premenných
    printf("Using only pointer variable :\n");
    printf("----------------------------------\n");
    printf("address of m = %p\n", p_m);
    printf("address of fx = %p\n", p_f);
    printf("address of cht = %p\n\n", p_c);

    // Použitie iba pointerových operátorov
    printf("Using only pointer operator :\n");
    printf("----------------------------------\n");
    printf("value at address of m = %d\n", *p_m);
    printf("value at address of fx = %.6f\n", *p_f);
    printf("value at address of cht = %c\n", *p_c);

    return 0;
}
```

#### Vysvetlenie

1. Premenné a pointery:
    * m, f, a c sú premenné typu int, float, a char inicializované na zadané hodnoty.
    * Pointery p_m, p_f, a p_c uchovávajú adresy týchto premenných.

2. Použitie operátora &:
    * Operátor & sa používa na získanie adresy premenných.

3. Použitie operátorov & a *:
    * Kombinácia & a * umožňuje získať hodnotu na adrese priamo cez ukazovateľ.

4. Použitie pointerových premenných:
    * Použitím samotných pointerov vypisujeme adresy premenných.

5. Použitie pointerových operátorov:
    * Operátor * (dereferencovanie) umožňuje prístup k hodnote na adrese, na ktorú ukazuje pointer.

#### Príklad výstupu

Pri spustení programu môže byť výstup nasledovný (adresy sa môžu líšiť v závislosti od systému):

```text
m = 300
fx = 256.450001
cht = z

Using & operator :
-----------------------
address of m = 0x7ffc7d9d314c
address of fx = 0x7ffc7d9d3150
address of cht = 0x7ffc7d9d3154

Using & and * operator :
-----------------------------
value at address of m = 300
value at address of fx = 256.450001
value at address of cht = z

Using only pointer variable :
----------------------------------
address of m = 0x7ffc7d9d314c
address of fx = 0x7ffc7d9d3150
address of cht = 0x7ffc7d9d3154

Using only pointer operator :
----------------------------------
value at address of m = 300
value at address of fx = 256.450001
value at address of cht = z
```

-->

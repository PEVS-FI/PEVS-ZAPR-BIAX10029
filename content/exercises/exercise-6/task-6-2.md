---
date: '2025-11-05T23:22:56+01:00'
title: 'Úloha 6.2'
weight: 2
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý definuje premennú typu _int m_ a _pointer ab_.
Napíšte program tak aby hodnota premennej _m_ menila tak aby vyhovovala nižšie uvedeným výpisom a aby pointer _ab_
ukazoval na hodnotu premennej _m_.

Program by mal vypísať na štandardný výstup nasledovné:

```text
Address of m : <adresa>
Value of m : 29

Now ab is assigned with the address of m.
Address of pointer ab : <adresa> 
Content of pointer ab : 29 

The value of m assigned to 34 now. 
Address of pointer ab : <adresa> 
Content of pointer ab : 34 

The pointer variable ab is assigned with the value 7 now.
Address of m : <adresa>
Value of m : 7 
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int main() {
    // Definícia premennej a pointeru
    int m;
    int *ab;

    // Nastavenie počiatočnej hodnoty premennej m
    m = 29;
    printf("Address of m : %p\n", &m);
    printf("Value of m : %d\n", m);

    // Nastavenie pointeru ab na adresu premennej m
    ab = &m;
    printf("\nNow ab is assigned with the address of m.\n");
    printf("Address of pointer ab : %p\n", ab);
    printf("Content of pointer ab : %d\n", *ab);

    // Zmena hodnoty m cez pointer
    m = 34;
    printf("\nThe value of m assigned to 34 now.\n");
    printf("Address of pointer ab : %p\n", ab);
    printf("Content of pointer ab : %d\n", *ab);

    // Zmena hodnoty premennej m priamo cez pointer ab
    *ab = 7;
    printf("\nThe pointer variable ab is assigned with the value 7 now.\n");
    printf("Address of m : %p\n", &m);
    printf("Value of m : %d\n", m);

    return 0;
}
```

##### Vysvetlenie

1. Premenné a pointery:
    * m je premenná typu int.
    * ab je pointer na int, ktorý ukazuje na adresu premennej m.

3. Počiatočné hodnoty:
    * Premenná m je inicializovaná hodnotou 29.

3. Pointer priraďuje adresu:
    * Pointer ab je nastavený na adresu premennej m pomocou operátora &.

4. Zmena hodnoty m:
    * Hodnota m je priamo zmenená a výpis potvrdzuje adresu a obsah cez pointer.

5. Zmena cez pointer:
    * Hodnota premennej m je zmenená priamo pomocou pointera ab s použitím operátora dereferencie *.

#### Príklad výstupu

Pri spustení programu môže byť výstup nasledovný (adresy sa môžu líšiť podľa systému):

```text
Address of m : 0x7ffc7d9d314c
Value of m : 29

Now ab is assigned with the address of m.
Address of pointer ab : 0x7ffc7d9d314c
Content of pointer ab : 29

The value of m assigned to 34 now.
Address of pointer ab : 0x7ffc7d9d314c
Content of pointer ab : 34

The pointer variable ab is assigned with the value 7 now.
Address of m : 0x7ffc7d9d314c
Value of m : 7
```

-->

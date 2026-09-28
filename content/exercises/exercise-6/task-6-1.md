---
date: '2025-11-05T23:22:53+01:00'
title: 'Úloha 6.1'
weight: 1
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý definuje premenné typu _int_ _m_, _n_ a _o_ a
pointer _z_, ktorý je pointer na premennú _m_. Premennej m priraďte ľubovolnú hodnotu.

Program by mal vypísať na štandardný výstup následné reťazce:

```text
 z stores the address of m  = <aktuálna adresa>
 *z stores the value of m = <aktuálna hodnota>
 &m is the address of m = <aktuálna adresa>
 &n stores the address of n = <aktuálna adresa>
 &o  stores the address of o = <aktuálna adresa>
 &z stores the address of z = <aktuálna adresa>
```

> [!NOTE]
> Všimnite si, že ak program spustíte opakovane adresy premenných sa menia.

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>

int main() {
    // Definícia premenných
    int m, n, o;
    int *z;

    // Priradenie hodnôt
    m = 42; // Ľubovoľná hodnota
    z = &m; // Pointer z ukazuje na premennú m

    // Výpis požadovaných informácií
    printf("z stores the address of m = %p\n", z);
    printf("*z stores the value of m = %d\n", *z);
    printf("&m is the address of m = %p\n", &m);
    printf("&n stores the address of n = %p\n", &n);
    printf("&o stores the address of o = %p\n", &o);
    printf("&z stores the address of z = %p\n", &z);

    return 0;
}
```

#### Vysvetlenie

1. Premenné a pointery:
    * m, n, a o sú premennej typu int.
    * z je pointer na int, ktorý uchováva adresu premennej m.

2. Priradenie hodnôt:
    * Premennej m priraďujeme hodnotu 42 (môže byť ľubovoľná).
    * Pointer z nastavujeme na adresu premennej m pomocou operátora &.

3. Výpis:
    * Adresy a hodnoty sa vypisujú pomocou formátovacieho reťazca %p (pre pointery) a %d (pre hodnotu typu int).

#### Príklady výstupu

Po spustení program môže byť výstup nasledovný (samozrejme adresy líšia medzi spusteniami):

```text
z stores the address of m = 0x7ffcb5e7914c
*z stores the value of m = 42
&m is the address of m = 0x7ffcb5e7914c
&n stores the address of n = 0x7ffcb5e79148
&o stores the address of o = 0x7ffcb5e79144
&z stores the address of z = 0x7ffcb5e79138
```

-->

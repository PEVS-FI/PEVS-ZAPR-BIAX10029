---
date: '2025-10-09T10:02:03+02:00'
title: 'Úloha 3.6'
weight: 6
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý realizuje nasledovnú činnosť.
Definujte funkciu **_int sucet_nacitanych (int n)_**, ktorá má vstupný parameter nezáporné číslo _n_. Funkcia
načíta n čísiel z klávesnice a vráti súčet načítaných čísiel. V prípade, že _n_ je záporné číslo funkcia
vypíše príslušnú chybovú správu a vráti hodnotu -1. V prípade, že _n_ je nula, funkcia vráti hodnotu 0.

### Príklady vstupov / výstupov programu

- Volanie `sucet_nacitanych(-1)` vypíše chybovú správu, že hodnota n je záporná a vráti -1.
- Volanie `sucet_nacitanych(4)` načíta 4 čísla z klávesnice. Ak by čísla boli napríklad 5, -2, 10, -7,
  funkcia vráti 6, pretože 5 + (-2) + 10 + (-7) = 6.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int sucet_nacitanych(int n) {
    if (n < 0) {
        printf("paramter n nemôže byť záporné číslo\n");
        return -1;
    }
    if (n == 0) return 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int input;
        printf("Zadaj %d. cislo: ", i + 1);
        scanf("%d", &input);
        sum += input;
    }
    return sum;
}

int main() {

    printf("%d\n", sucet_nacitanych(-1));
    printf("%d\n", sucet_nacitanych(4));

    return 0;
}
```

{{< /details >}}
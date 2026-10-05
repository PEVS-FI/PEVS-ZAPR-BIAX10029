---
date: '2025-09-24T23:00:07+02:00'
title: 'Úloha 1.5'
weight: 5
---

Napíšte program, ktorý vypočíta BMI (Body Mass Index) z dát zadaných používateľom a vypíše ho.
BMI je vypočítané podľa vzorca:

```text
BMI = Váha (v kg) / Výška^2 (v metroch)
```

### Príklady vstupov / výstupov programu

Ak používateľ zadá výšku 1.82m a váhu 72kg výsledné vypočítané BMI je 21.736506.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main()
{
    float vaha;
    float vyska;
    
    printf("Zadajte vašu výšku v metroch: ");
    scanf("%f",&vyska);
    
    printf("Zadajte vašu váhu v kilogramoch: ");
    scanf("%f",&vaha);
    
    float bmi = vaha / (vyska * vyska);
    
    printf("Vaše BMI je %.2f",bmi);
    
    return 0;
}
```

{{< /details >}}

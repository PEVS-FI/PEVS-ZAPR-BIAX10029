---
date: '2026-09-28'
title: 'Volanie odkazom (call by reference)'
weight: 1
---


Predávanie argumentu funkcii pomocou smerníka (odkazu).

```c
#include <stdio.h>

void call_bname(int *poi_na_int) {
    *poi_na_int = *poi_na_int + 1;
}

int call_bvalue(int norm_int) {
    norm_int = norm_int - 1;
    return norm_int;
}

int main() {
    int i;
    printf("zadaj i: ");
    scanf("%d", &i);
    call_bname(&i);
    printf("i = %d\n", i);

    call_bvalue(i);
    printf("i = %d\n", i);

    i = call_bvalue(i);
    printf("i = %d\n", i);

    return 0;
}
```

[Stiahnuť zdrojový kód](../call_by_name.c)

### Vysvetlenie

Príklad rozlišuje dva spôsoby volania funkcie. Funkcia `call_bname` prijíma smerník na premennú a mení jej hodnotu
priamo v pamäti, takže zmena sa prejaví aj vo volajúcej funkcii (volanie odkazom).

Funkcia `call_bvalue` prijíma hodnotu a vracia jej upravenú kópiu; bez priradenia návratovej hodnoty sa pôvodná premenná
nezmení (volanie hodnotou). Program jasne ukazuje rozdiel medzi oboma prístupmi.

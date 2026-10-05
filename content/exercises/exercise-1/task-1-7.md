---
date: '2025-09-24T23:00:11+02:00'
title: 'Úloha 1.7'
weight: 7
---

Cyklista si sleduje prejdenú vzdialenosť v kilometroch a čas (v minútach a sekundách), za ktorý
túto vzdialenosť prešiel. Naprogramujte program, ktorý na základe premenných kilometre, minuty,
sekundy vypočíta cyklistovu priemernú rýchlosť v km/h (kilometre za hodinu) a vypíše ju na
obrazovku. Hodnoty premenných vyžiadajte od používateľa po spustení programu.

### Príklady vstupov / výstupov programu

Napríklad ak kilometre = 8.5, minuty = 25 a sekundy = 30, potom priemerná rýchlosť cyklistu bola
20.0 km/h.

Ak kilometre = 9.7, minuty = 29 a sekundy = 55, potom priemerná rýchlosť cyklistu bola približne
19.454 km/h.

---

{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}

```C
#include <stdio.h>

int main()
{
    float km;
    int m,s;
    
    printf("Zadajte prejdenú vzdialenosť v km: ");
    scanf("%f",&km);
    
    printf("Zadajte prejdené minuty: ");
    scanf("%d",&m);
    
    printf("Zadajte prejdené sekundy: ");
    scanf("%d",&s);
    
    float celkovy_cas_v_hodinach = (m/60.0)+(s/3600.0);
    
    printf("Vaša priemerná rýchlosť bola %.2f km/h", km/celkovy_cas_v_hodinach);
    
    return 0;
}
```

{{< /details >}}

---
date: '2026-10-05T20:00:00+02:00'
title: 'Bežné chyby v C: ako čítať hlášky a kde hľadať opravu'
---

Chybové hlášky nie sú útok proti tebe – sú to presné súradnice problému. GCC v drvivej väčšine prípadov povie
*presne*, čo je zle a často aj *ako to opraviť*. Tento návod ťa naučí tie hlášky čítať a na reálnych príkladoch
ukazuje najčastejšie chyby v C. Všetky výpisy tu sú skutočné správy z kompilácie aj z behu programov
(gcc 16 – staršie verzie bývajú o slovo iné, duch sa nemení).

## Ako čítať hlášku od gcc

```text
typo.c:4:20: error: 'pocet2' undeclared (first use in this function); did you mean 'pocet'?
    4 |     printf("%d\n", pocet2);
      |                    ^~~~~~
      |                    pocet
```

| Časť hlášky | Význam |
|-------------|--------|
| `typo.c:4:20` | súbor, riadok, stĺpec – presné miesto, kde si kompilátor všimol problém |
| `error:` / `warning:` / `note:` | error musíš opraviť; warning by si mal opraviť; note obsahuje radu |
| `'pocet2' undeclared` | čo je problém – tu: nepoznáš premennú `pocet2` |
| `did you mean 'pocet'?` | novší gcc navrhuje opravu priamo |
| šípka pod riadkom | ukazuje presne na problémový úsek kódu |

Pri viac súboroch vidíš aj reťazec include-ov:

```text
In file included from twice.c:2:
noguard.h:1:8: error: redefinition of 'struct Bod'
    1 | struct Bod { int x; int y; };
      |        ^~~
In file included from twice.c:1:
noguard.h:1:8: note: originally defined here
```

Povie ti to: `struct Bod` som videl dvakrát – prvý výskyt (pri `note:`) je originál, druhý je duplikát,
aký máš odstrániť.

**Pravidlá čítania:**

1. **Opravuj prvú chybu, nie poslednú.** Jedna chýbajúca bodkočiarka dokáže vyvolať 15 errorov – po jej oprave
   väčšina zmizne.
2. **Chyba na riadku N často znamená chybu na riadku N-1.** Napr. `expected ',' or ';' before 'int'` na riadku 4
   vznikla preto, že riadok 3 nekončí `;`.
3. **Čítaj `note:`.** Často v nej stojí odpoveď priamo („include `<math.h>` or provide a declaration of `sqrt`").
4. **Warning je budúci error.** `gcc -Wall -Wextra` ti ukáže skutočné problémy zadarmo; neignoruj ich.
5. Hlášku hľadaj na internete **v presnom znení** – bez cesty k tvojmu súboru.

## Preklepy a deklarácie

### ❌ Premenná, ktorú gcc nepozná (`undeclared`)

```text
error: 'pocet2' undeclared (first use in this function); did you mean 'pocet'?
```

Premenná neexistuje – buď je preklep, alebo si ju zabudol deklárovať, alebo je v inom rozsahu (lokálna z inej
funkcie). Novší gcc rovno radí opravu.

### ❌ Chýbajúca bodkočiarka

```text
semicolon.c:4:5: error: expected ',' or ';' before 'int'
    4 |     int b = 2
      |     ^~~
```

Tip: bodkočiarku hľadaj na **predchádzajúcom** riadku. Chýbajúca bodkočiarka v `.h` sa často ukáže až
v `.c`, ktoré hlavičku includuje.

### ❌ Duplicitná definícia (`struct` dvakrát)

```text
error: redefinition of 'struct Bod'
note: originally defined here
```

Hlavička bola includnutá dvakrát. Oprava: include guard v každej `.h`:

```c
#ifndef STATISTIKA_H
#define STATISTIKA_H

/* sem patria deklarácie */

#endif
```

## Hlavičky a viac zdrojových súborov

### ❌ Implicitná deklarácia funkcie

```text
implicit.c:3:16: error: implicit declaration of function 'sqrt' [-Wimplicit-function-declaration]
implicit.c:2:1: note: include '<math.h>' or provide a declaration of 'sqrt'
```

Voláš funkciu, ktorej prototyp kompilátor nevidí. Príčiny: chýbajúci `#include` (matika → `<math.h>`,
reťazce → `<string.h>`), preklep v mene, alebo funkcia definovaná až za volaním bez deklarácia. Na starších
gcc je to len warning – a presne takéto varovania vedú k nepochopiteľným výsledkom, lebo si gcc
návratový typ odhadol.

### ❌ `undefined reference`

```text
/usr/bin/ld: main.c:(.text+0xa): undefined reference to `zdvoj'
collect2: error: ld returned 1 exit status
```

Chyba **linkera**, nie kompilátora: prototyp existoval a kompilátor ho videl, ale telo funkcie nikto
nepridal.
Najčastejšie:

- zabudol si pridať druhý `.c` do príkazu (`gcc ... main.c helper.c`, nie len `main.c`),
- chýbajúca knižnica – `-lm` až **za** zdrojovými súbormi (podrobnosti v návode
  [Inštalácia kompilátora GCC](../gcc/)),
- definícia funkcie nie je nigde (iba v hlavičke, alebo vôbec).

### ❌ `multiple definition`

```text
b.c:(.text+0x0): multiple definition of `pocet'; /tmp/cchd8h4e.o:a.c:(.text+0x0): first defined here
```

Funkcia (alebo globálna premenná) je **definovaná** v `.h` súbore a ten sa cez `#include` ocitne vo dvoch `.c`. Definícia
má byť v práve jednom `.c`; v hlavičke je len deklarácia (`int pocet(void);`). Výnimka: `static` funkcia alebo
`static inline`.

## Formátované vstupy a výstupy

### ❌ `scanf` bez `&`

```text
warning: format '%d' expects argument of type 'int *', but argument 2 has type 'int' [-Wformat=]
    5 |     scanf("%d", vek);
```

`scanf` potrebuje **adresu**, kam má písať. Chýbajúce `&` je veľmi častá príčina segfaultu v úlohách z
cvičení. Správne: `scanf("%d", &vek);`.

### ❌ Formát nesedí s typom

```text
warning: format '%d' expects argument of type 'int', but argument 2 has type 'double' [-Wformat=]
    4 |     printf("d = %d\n", d);
      |                 int   double
      |                 %f
```

Novší gcc vypíše rovno aj odporúčaný náhradu formátu (v ukážke pre `double` radí `%f`). Základná tabuľka:

| Formát | Patrí na | Pozor |
|--------|----------|-------|
| `%d` | `int` | – |
| `%f` | `double` | pri **scanf** musí byť `%lf`, pri printf stačí `%f` |
| `%c` | `char` | scanf: `%c` **nepreskakuje** medzery/newline na rozdiel od `%d` a `%s` |
| `%s` | pole znakov (`char*`) | vždy s rozmerom, napr. `%20s` |
| `%p` | pointer | printf – výpis adresy, napr. `&premenna` |
| `%%` | znak `%` | printf |

## Chyby, ktoré ukáže až beh

### ❌ Segmentation fault

```text
bash: line 1: 51673 Segmentation fault         (core dumped) ./program
```

Program siahol mimo svoju pamäť. Typické príčiny: `scanf` bez `&` (hore), dereferencovaný NULL smerník,
neinicializovaný smerník, prístup za koniec poľa, zápis do reťazcového literálu (`char *s = "text"; s[0] = 'x';`).
Cez exit kód: `echo $?` povie 139 (= 128 + signál 11).

Kde hľadať miesto: `gcc ... -g` a `gdb ./program` → `run`, `bt` (backtrace ukáže funkciu aj riadok), alebo
kompilácia s `-fsanitize=address` – tá vypíše presný riadok a typ chyby pamäte. Obe techniky sú v návode
[Inštalácia kompilátora GCC](../gcc/#ladiace-informácie-a-sanitizery).

### ❌ Delenie nulou

```text
bash: line 1: 51690 Floating point exception   (core dumped) ./program
```

Celočínske delenie nulou (`5 / 0`) ukončí program signálom SIGFPE (exit 136). **Reálne** číslo nulou
nedelí – program beží ďalej a dostaneš prekvapivé hodnoty:

```text
printf("%f %f\n", 1.0 / 0.0, 0.0 / 0.0);   /* → inf -nan */
```

Ošetrenie je obyčajné `if` z cvičení: `if (deaths == 0) ...`.

### ❌ Reťazce porovnané cez `==`

```text
warning: comparison with string literal results in unspecified behavior [-Waddress]
```

A aj keby varovanie nebolo – logika je zlá. `odp == "ano"` porovnáva **adresy**, nie obsah; aj keď používateľ
zadá „ano", výstup je `NIE`. Reťazce sa porovnávajú funkciami `strcmp()` / `strncmp()` z `<string.h>`.

### ❌ Neinicializovaná premenná

```text
warning: 'sucet' is used uninitialized [-Wuninitialized]
note: 'sucet' was declared here
```

V premennej je len náhodný zvyšok z pamäte – výsledok vyzerá „takmer správne" a mení sa s každým rebuildom.
Vždy inicializuj: `int sucet = 0;`.

## Ako nájsť miesto problému v kóde

1. **Čítaj od prvej hlášky:** tá je najcennejšia – ďalšie môžu byť len jej dozvuk.
2. **Pozri o riadok vyššie**, než píše kompilátor.
3. **Vynechaj polovicu kódu** – po častiach zistíš, kde sa to rozbilo (alebo pozri `git diff`).
4. **Vypisuj si medzivýsledky:** `printf("i=%d, sucet=%d\n", i, sucet);` je primitívne, ale funkčné ladenie.
5. **Zadaj vstup, o ktorom vieš, že má konkrétny výstup** – potom sa posúvaj od vstupu k chybe.
6. **Nakresli si to** – pri smerníkoch a poliach jeden štvorec s šípkou nahradí 20 riadkov kódu.

## Kde hľadať opravu

V tomto poradí:

1. **Poznámka od gcc** – často obsahuje priamu odpoveď (`did you mean`, `include '<math.h>'`,
   `use option '-std=c99'...`).
2. **`man`** – manualovú stránku máš v termináli: `man 3 scanf`, `man 3 strcmp`. Vysvetlí formáty aj chybové
   stavy.
3. **Príklady na stránke predmetu** – [Príklady](/examples/) obsahujú funkčné ukážky k každej téme (polia,
   smerníky, súbory, rekurzia).
4. **cppreference.com** – najúplnejšia referencia C knižníc; hľadaj podľa názvu funkcie.
5. **Vyhľadávanie** – vlož presný text chyby (bez svojej cesty k súboru) do vyhľadávača.
6. **AI nástroje** – v tomto predmete povolené na inšpiráciu, riešenie problémov a testovanie; **priame
   generovanie riešenia zadania je zakázané** (pozri pravidlá v zadaniach). Pýtať sa AI „prečo táto hláška
   vznikla" je OK; požiadať ju o hotový `main.c` nie.
7. **Cviaci** – MS Teams alebo email; posielaj konkrétnu hlášku a kód, nie „nejako to nefunguje".

## Rýchly referenčný list

| Hláška | Príčina | Oprava |
|--------|---------|--------|
| `undeclared ... did you mean` | preklep / chýba deklarácia | oprav meno, doplň `#include` |
| `expected ',' or ';' before ...` | chýba bodkočiarka o riadok vyššie | dopln `;` |
| `redefinition of 'struct'` | hlavička bez guardu | `#ifndef / #define / #endif` |
| `implicit declaration of function` | chýba `#include` alebo prototyp | pripoj hlavičku, oprav meno |
| `undefined reference` | linker nevidí definíciu | pridaj `.c` do príkazu / `-lm` za súbory |
| `multiple definition of` | definícia v `.h` includnutá 2× | definícia len v jednom `.c` |
| `expects argument of type 'int *'` | `scanf` bez `&` | `scanf("%d", &x)` |
| `expects argument of type 'int', ... 'double'` | `%d` na double | `%f`, pri scanf `%lf` |
| `Segmentation fault (core dumped)` | siahanie mimo pamäť | `-g` + gdb / ASan; skontroluj pointere a medze polí |
| `Floating point exception (core dumped)` | celočíselné delenie nulou | ošetri `if (menovatel == 0)` |
| `comparison with string literal` | reťazec porovnaný cez `==` | `strcmp()` |
| `used uninitialized` | inicializácia chýba | `int x = 0;` |

## Ďalšie zdroje

- Návod [Inštalácia kompilátora GCC](../gcc/) – flags, linkovanie, ladenie, sanitizery
- Návod [Štruktúra C projektu a Makefile](../project_and_makefile/) – viac súborov bez linkerových prekvapení
- [C reference – cppreference.com](https://en.cppreference.com/w/c/language) – jazyk a knižnice dohromady
- [GNU GCC Manual – Invoke GCC](https://gcc.gnu.org/onlinedocs/gcc/invocation.pdf) – prepínače a diagnostika

---
date: '2026-10-05T12:00:00+02:00'
title: 'Inštalácia a používanie C kompilátora GCC (Windows, Linux, macOS)'
---

Všetky príklady a zadania v tomto predmete sa kompilujú kompilátorom **GCC** v štandarde **C17**. Tento návod ťa
provedie inštaláciou GCC na Windows, Linux aj macOS a ukáže, ako s kompilátorom pracovať – od prvého programu po
časté chyby, ktoré pri kompilácii stretneš.

> [!IMPORTANT]
> Kód zadania musí byť skompilovateľný **základnou inštaláciou GCC**. Kompilátor od Microsoftu (`cl.exe` z Visual
> Studio) nie je GCC a správa sa inak. macOS dodáva namiesto GCC kompilátor clang, ktorý ale pozná rovnaké prepínače
> (`-std=c17`, `-Wall`, `-Wextra`) a na účely predmetu je kompatibilný.

## Prečo práve GCC

- Cvičenia aj zadania používajú príkaz `gcc -std=c17 -o program -Wall -Wextra main.c`.
- Hodnotiace pipeline (GitHub Actions) kompilujú tvoj kód najnovšou verziou GCC – čo u teba skompiluješ bez
  varovaní, neprekvapí ani pri hodnotení.
- GCC je svobodný softvér a je dostupný na všetkých troch platformách.

## Inštalácia podľa operačného systému

### Windows

Na Windowse neexistuje oficiálna inštalácia priamo od GNU projektu. Prácu s C (a C++) ti tam umožňuje **MinGW-w64** –
Windows port toolchainu GCC, ktorý poskytuje plnohodnotné `gcc` aj `g++`. Najpohodlnejšia je distribúcia
**WinLibs** – archív len rozbaľ a môžeš kompilovať:

1. Z [winlibs.com](https://winlibs.com/) stiahni najnovší archív (`.zip` alebo `.7z`) pre **64-bit (x86_64)**
   s runtime **UCRT** – v názve hľadaj označenia `x86_64`, `ucrt`, `posix`. (Na Windows 10/11 ber UCRT;
   Runtime: MSVCRT patrí len pre staré Windows.)

2. Archív rozbaľ do adresy bez medzier a diakritiky, napríklad do `C:\` – vytvorí sa zložka `C:\mingw64`
   a v nej `C:\mingw64\bin\gcc.exe`.

3. Pridaj zložku `C:\mingw64\bin` do premennej prostredia **PATH**, aby sa `gcc` dalo volať z PowerShellu/CMD:

   ```powershell
   [Environment]::SetEnvironmentVariable("Path", [Environment]::GetEnvironmentVariable("Path", "User") + ";C:\mingw64\bin", "User")
   ```

   Cez GUI sa dá PATH upraviť aj cez *Nastavenie → Systém → O aplikácii → Upresniť systémové nastavenia →
   Premenné prostredia*. Po úprave reštartuj všetky otvorené okná terminálu.

4. Skontroluj, že GCC funguje – v **novom** okne PowerShell alebo CMD:

   ```powershell
   gcc --version
   ```

**Alternatíva:** buildy s inštalátorom od [niXman/mingw-builds](https://github.com/niXman/mingw-builds-binaries/releases)
(pri inštalácii zvoľ x86_64, threads **posix**, runtime **ucrt** a zaškrtni „Add to PATH“). Vyhni sa starým 32-bitovým
MinGW distribúciám bez podpory C17 a TDM-GCC (nepodporuje niektoré moderné funkcie).

> [!WARNING]
> **Nevytváraj si projekt vo Visual Studiu** a nekompiluj `cl.exe`. Je to iný kompilátor s inými pravidlami a iným
> formátom chýb. Hodnotenie beží na GCC.

### Linux

Na väčšine distribúcií je inštalácia otázkou jedného príkazu:

| Distribúcia     | Príkaz                                                |
|-----------------|-------------------------------------------------------|
| Debian / Ubuntu | `sudo apt update && sudo apt install build-essential` |
| Fedora          | `sudo dnf install gcc`                                |
| Arch / Manjaro  | `sudo pacman -S base-devel`                           |
| openSUSE        | `sudo zypper install gcc`                             |

Balík `build-essential` (Debian/Ubuntu) alebo `base-devel` (Arch) pridá aj `make` a ďalšie nástroje, ktoré sa hodia
neskôr. Overenie:

```bash
gcc --version
```

### macOS

Apple priamo GNU GCC nedodáva – Command Line Tools obsahujú **clang**, ktorý pre tento predmet plne stačí (pozná
`-std=c17`, `-Wall`, `-Wextra`):

```bash
xcode-select --install
```

Príkaz `gcc` potom na Macu existuje, ale volá clang – overíš to výstupom príkazu:

```bash
gcc --version   # vypíše "Apple clang version ..."
```

Ak chceš priamo GNU GCC (napr. pre čo najvernejšie správanie ako pri hodnotení), nainštaluj ho cez
Homebrew:

```bash
brew install gcc
gcc-15 --version   # Homebrew inštaluje verzované príkazy (gcc-15, gcc-14, ...)
```

## Overenie inštalácie

Prvé overenie vždy tvoria tri otázky: *kde* je kompilátor, *ako* sa volá a *aká* je jeho verzia.

```bash
which gcc        # na Windowse (PowerShell/CMD) skús namiesto toho: where.exe gcc
gcc --version
gcc -v
```

Funkčný test – vytvor súbor `main.c` a skompiluj ho:

```c
#include <stdio.h>

int main(void) {
    printf("Ahoj, GCC!\n");
    return 0;
}
```

```bash
gcc -std=c17 -Wall -Wextra -o program main.c
./program        # na Windowse v CMD/PowerShell: program.exe
```

Ak vypíše `Ahoj, GCC!`, máš hotovo.

## Kompilácia: príkaz a jeho časti

Príkaz používaný v cvičeniach rozoberieme na kúsky:

```bash
gcc -std=c17 -o program -Wall -Wextra main.c
│    │        │         │        │       │
│    │        │         │        │       └─ vstupný súbor (zdrojový kód)
│    │        │         │        └─ zvýšená sada varovaní
│    │        │         └─ štandardné varovania
│    │        └─ názov výstupného (spustiteľného) súboru
│    └─ jazykový štandard C17
└─ kompilátor
```

Prehľad najdôležitejších prepínačov:

| Prepínač             | Význam                                                                            |
|----------------------|-----------------------------------------------------------------------------------|
| `-std=c17`           | Kompiluj podľa štandardu C17 (inštrukcie predmetu)                                |
| `-o VYSLEDOK`        | Názov výstupného súboru (inak vznikne `a.out`/`a.exe`)                            |
| `-Wall`              | Povoli bežné varovania                                                            |
| `-Wextra`            | Povoli ďalšie varovania navyše                                                    |
| `-Werror`            | Varovania ber ako chyby (stredne pokročilí)                                       |
| `-g`                 | Pridať ladiace informácie (pre gdb/valgrind)                                      |
| `-O0` / `-O2`        | Optimalizácia: vypnutá (pre ladenie) / bežná                                      |
| `-fsanitize=address` | Za behu kontroluje chyby práce s pamäťou (pozri nižšie)                           |
| `-I ADRESA`          | Hľadať hlavičkové súbory aj v zložke `ADRESA`                                     |
| `-L ADRESA`          | Hľadať knižnice aj v zložke `ADRESA`                                              |
| `-lnazov`            | Linkovať knižnicu `libnazov.a` / `libnazov.so` (napr. `-lm` matematická knižnica) |
| `-E`                 | Iba preprocessor (výstup do .i súboru / stdout)                                   |
| `-S`                 | Iba kompilácia na assembly (.s)                                                   |
| `-c`                 | Iba kompilácia na objektový súbor (.o), bez linkovania                            |

## Čo sa deje pri kompilácii

Príkaz `gcc ... main.c` v skutočnosti spustí štyri kroky – je užitočné vedieť, v ktorom ti čo zlyhalo:

1. **Preprocess** – rozšíri `#include`, makrá, odstráni komentáre.
2. **Kompilácia** – preklad C kódu na assembly (chyby typu "nedefinovaná premenná").
3. **Asemblácia** – assembly na strojový kód (objektový súbor `.o`).
4. **Linkovanie** – spojenie objektových súborov a knižníc do spustiteľného súboru (chyby typu "undefined reference").

Jednotlivé fázy si môžeš pozrieť samostatne:

```bash
gcc -std=c17 -E main.c -o main.i      # preprocessor
gcc -std=c17 -S main.c -o main.s      # assembly
gcc -std=c17 -c main.c -o main.o      # objektový súbor
gcc main.o -o program                 # linkovanie
```

## Viacsoborové programy

Ak máš program rozdelený do viacerých súborov (ako napr. `main.c` a `statistika.c`), zoznam vstupov sa iba predĺži:

```bash
gcc -std=c17 -Wall -Wextra -o program src/main.c src/statistika.c
```

Úspornejšia varianta – najprv skompilovať jednotlivé súbory na `.o` a tie potom spojiť (linkovať) do binárky.
Pri zmene jedného súboru sa potom rekompiluje len on:

```bash
gcc -std=c17 -Wall -Wextra -c src/main.c -o main.o
gcc -std=c17 -Wall -Wextra -c src/statistika.c -o statistika.o
gcc main.o statistika.o -o program
```

## Matematická knižnica (-lm)

Funkcie z `<math.h>` (`sqrt`, `pow`, `sin`, ...) nie sú na Linuxe a macOS štandardne v základnej knižnici. Ak
program používa `sqrt` a nepoužiješ `-lm`, narazíš na chybu linkovania:

```c
#include <math.h>
#include <stdio.h>

int main(void) {
    printf("%f\n", sqrt(2.0));
    return 0;
}
```

```bash
gcc -std=c17 -Wall -Wextra -o program main.c
# /usr/bin/ld: undefined reference to `sqrt'  ❌

gcc -std=c17 -Wall -Wextra -o program main.c -lm
./program   # 1.414214 ✓
```

Pravidlo: **`-lm` patrí až za zdrojové súbory** (`main.c -lm`, nie `-lm main.c`), lebo gcc berie knižnice
v poradí, v akom sú zadané – hľadá v nich definície doteraz nevyriešených symbolov. Na Windowse (MinGW-w64)
`sqrt` zvyčajne funguje aj bez `-lm`, pretože matematické funkcie sú súčasťou runtime knižnice – `-lm` ale
neprekáža a kód je potom prenosný.

## C++ súbor (g++)

Cvičenie 9 a príklady s triedami pracujú s C++. Pre C++ sa používa `g++` a štandard C++17:

```bash
g++ -std=c++17 -Wall -Wextra -o program main.cpp
```

Pomôcka: `.c` súbory kompiluj `gcc`, `.cpp` súbory `g++`. Pozor: niektoré príklady na stránke majú síce príponu
`.c`, ale používajú `new` (čo je C++ prvok) – ak ti `gcc` na takom súbore nahlási chybu, skús `g++`.

## Ladiace informácie a sanitizery

Pre ladenie pripoj prepínač `-g` a program potom spusti v debuggeri `gdb`:

```bash
gcc -std=c17 -Wall -Wextra -g -o program main.c
gdb ./program
```

GCC má aj zabudované "sanitery", ktoré počas behu chytajú bežné chyby práce s pamäťou (pretečenie poľa, double-free,
prístup po `free`). Stačí pridať `-fsanitize=address` pri kompilácii:

```bash
gcc -std=c17 -Wall -Wextra -g -fsanitize=address -o program main.c
./program
```

Na Linuxe sa dá na kontrolu práce s pamäťou použiť aj `valgrind ./program` – na Windowse valgrind nie je.

## Prepojenie s editorom (VS Code)

Najjednoduchšie pracovné prostredie pre predmet je VS Code s rozšírením *C/C++*:

1. Nainštaluj VS Code a rozšírenie **C/C++** (od Microsoft).
2. Otvor zložku s `main.c`.
3. `Ctrl+Shift+B` spustí build task – prvýkrát ťa VS Code vyzve na výber kompilátora; vyber **gcc**.
   Ak `gcc` nenájde (Windows), uisti sa, že máš nastavenú cestu `C:\mingw64\bin` v PATH.

Alternatívou je napísať príkazy priamo do integrovaného terminála (vo Windowse je to PowerShell – fungujú v ňom
rovnaké príkazy `gcc` ako na Linuxe). Pre väčšie projekty sa hodí **CLion** alebo bežné študentské IDE.

## Časté chyby a riešenia

### ❌ `'gcc' nie je interný ani externý príkaz` (Windows) / `command not found: gcc`

`gcc` nie je v PATH. Pridaj `C:\mingw64\bin` do premennej PATH (krok 3 inštalácie vyššie) a **reštartuj** terminál.
Kontrola: `where.exe gcc` (PowerShell) musí ukázať existujúcu cestu.

### ❌ `error: 'for' loop initial declarations are only allowed in C99 mode`

Nepoužil si `-std=c17`. Všetky príkazy kompilácie v predmete majú povinnú `-std=c17`.

### ❌ `undefined reference to 'sqrt'`

Chýbajúca matematická knižnica – pridaj `-lm` **za** zdrojové súbory (časť o `-lm` vyššie).

### ❌ `warning: implicit declaration of function ...`

Používaš funkciu, ktorej prototyp kompilátor nevidí – väčšinou chýba `#include <hlavicka.h>`
(napr. `#include <string.h>` pre `strcmp`) alebo je funkcia definovaná až za volaním a chýba jej deklarácia.

### ❌ Pokrivená diakritika vo výstupe na Windowse

Zdrojový kód aj terminál musia používať rovnaké kódovanie. Postup:

- Ulož súbor v UTF-8 (v editore nastav kódovanie).
- V termináli pred spustením programu prepni kódovanie: `chcp 65001` (CMD/PowerShell).
- Ak to nepomôže, napíš texty v programe bez diakritiky.

### ❌ `Permission denied` pri spustení `./program` na Linux/macOS

Súbor nie je označený ako spustiteľný – skontroluj `ls -l program` a prípadne `chmod +x program`. Na Windowse
môže spustenie `.exe` pozdržať antivírus – skús program spustiť znova alebo pridaj working directory do výnimiek.

## Rýchly referenčný list

| Chcem                      | Príkaz                                                 |
|----------------------------|--------------------------------------------------------|
| Skontrolovať inštaláciu    | `gcc --version`                                        |
| Skompilovať podľa predmetu | `gcc -std=c17 -o program -Wall -Wextra main.c`         |
| Skompilovať C++            | `g++ -std=c++17 -Wall -Wextra -o program main.cpp`     |
| Pripojiť matematiku        | `... main.c -lm`                                       |
| Viac súborov naraz         | `... -o program main.c dalsi.c`                        |
| Len objektový súbor        | `gcc -std=c17 -c main.c`                               |
| Pre ladenie                | `gcc -std=c17 -g -o program main.c`                    |
| Kontrola pamäte pri behu   | `gcc -std=c17 -g -fsanitize=address -o program main.c` |

## Ďalšie zdroje

- [GNU GCC Manual](https://gcc.gnu.org/onlinedocs/) – kompletná dokumentácia kompilátora
- [WinLibs](https://winlibs.com/) – predpripravené MinGW-w64 buildy na stiahnutie pre Windows
- [mingw-w64.org](https://www.mingw-w64.org/downloads/) – zoznam podporovaných MinGW-w64 distribúcií
- Cvičenia na stránke predmetu používajú rovnaké kompilačné príkazy – pozri napr.
  [Cvičenie 1](../exercises/exercise-1/)

---
date: '2026-10-12T10:00:00+02:00'
title: 'Projekt s CMake a CLion (gcc)'
---

Návod [Štruktúra C projektu a Makefile](../project_and_makefile/) ťa naučil postaviť jednoduchý build ručne.
CMake je ďalší level: najpoužívanejší generátor buildu v praxi a **presne na ňom beží IDE CLion**, ktoré sa
odporúča na prácu s C a C++. Cieľom tohto návodu je, aby si pochopil skladbu projektu okolo
`CMakeLists.txt` a vedel taký projekt otvoriť, postaviť a spustiť – v termináli aj v CLion.

## Čo je CMake (a čo nie je)

CMake **nie je kompilátor**. Je to generátor predpisov na build – z jedného súboru `CMakeLists.txt` vygeneruje
Makefiley (alebo Ninja súbor) a tie potom zavolajú `gcc`. Výhody oproti ručnému Makefile:

- **Jeden predpis, tri platformy** – Windows/Linux/macOS, a CMake sám nájde vhodný kompilátor.
- **IDE integrujú CMake natívne** – CLion, Qt Creator, VS; projekt otvoríš a build beží bez nastavovania.
- **Automatický inkrementálny build** – rebuiltuje len to, čo sa zmenilo.
- **Viac targetov a knižníc bez utrpenia** – dva programy + knižnica v jednom projekte? Tri riadky.

Rovnaká úloha, dva pohľady:

| Úloha            | Makefile            | CMakeLists.txt                               |
|------------------|---------------------|----------------------------------------------|
| spustenie buildu | `make`              | `cmake -S . -B build && cmake --build build` |
| štandard C17     | `CFLAGS = -std=c17` | `set(CMAKE_C_STANDARD 17)`                   |
| zdrojové súbory  | vypíšeš ručne       | vypíšeš ručne (alebo `GLOB`)                 |
| knižnice         | `-lm`               | `target_link_libraries(... m)`               |
| IDE podpora      | treba nastaviť      | číta priamo (CLion)                          |

## Štruktúra projektu

```
muj-projekt/
├── CMakeLists.txt      # predpis, ako to postaviť
├── .gitignore          # build/ sem nesmie!
└── src/
    ├── main.c
    ├── statistika.c
    └── statistika.h
```

CMake zvyčajne generuje do adresára `build/` – ten je **výstup, nie zdroj**. Prvý commit preto pridaj:

```gitignore
build/
```

Pravidlo: `cmake` sa **nikdy nespúšťa priamo v zdrojovom adresári** – vždy spusti príkaz `-S . -B build` z koreňového
priečinku projektu (tam kde je súbor CMakeLists.txt). Ak to urobíš, zasype ti
zdrojový strom pôvodnými súbormi a CLion sa z toho zblázni.

## Prvý CMakeLists.txt

Projekt z tohto návodu (dva zdrojáky + matematická knižnica):

```cmake
cmake_minimum_required(VERSION 3.20)
project(gamestats C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(gamestats src/main.c src/statistika.c)
target_compile_options(gamestats PRIVATE -Wall -Wextra)
target_link_libraries(gamestats m)
```

| Riadok                                      | Čo hovorí CMake                                         |
|---------------------------------------------|---------------------------------------------------------|
| `cmake_minimum_required`                    | nepokračuj, ak je nainštalovaný príliš starý CMake      |
| `project(gamestats C)`                      | meno projektu a jazyk (pre C++ napíš `CXX`)             |
| `CMAKE_C_STANDARD 17`                       | ekvivalent prepínača `-std=c17`                         |
| `STANDARD_REQUIRED ON`                      | bez C17 nekompiluj – žiadne tiché "tak to skúsime inak" |
| `add_executable(... súbory)`                | vytvor program `gamestats` z týchto zdrojov             |
| `target_compile_options(... -Wall -Wextra)` | pridaj flagy len tomuto cieľu                           |
| `target_link_libraries(... m)`              | napoj matiku (na Linuxe/macOS ekvivalent `-lm`)         |

> [!IMPORTANT]
> Každý zdrojový `.c` súbor musí byť v `add_executable`. Ak sa nejaký zdrojový súbor zabudne vypíše sa chyba:
> `undefined reference to 'priemer'` – presnú situáciu z návodu [Chyby v C](../c_errors/).

## Build v termináli

```bash
cmake -S . -B build        # konfigurácia: nájdi kompilátor, vygeneruj Makefile
cmake --build build        # samotný build (volá gcc)
./build/gamestats          # spustenie – Linux/macOS
```

Prvý `cmake -S . -B build` :

```text
-- The C compiler identification is GNU 16.2.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done (0.1s)
-- Generating done (0.2s)
-- Build files have been written to: .../build
```

`cmake --build build` :

```text
[ 33%] Building C object CMakeFiles/gamestats.dir/src/main.c.o
[ 66%] Building C object CMakeFiles/gamestats.dir/src/statistika.c.o
[100%] Linking C executable gamestats
[100%] Built target gamestats
```

Zmeníš len `main.c` a spustíš build znovu – **statistika.c sa nepreklada** :

```text
[ 33%] Building C object CMakeFiles/gamestats.dir/src/main.c.o
[ 66%] Linking C executable gamestats
[100%] Built target gamestats
```

### Kde je gcc a aký kompilátor sa použil

CMake pri konfigurácii hľadá sám: na Linuxe siahol po výstupe `gcc`. Ak chceš **garantovane
gcc**, povedz mu to:

```bash
cmake -S . -B build -DCMAKE_C_COMPILER=gcc
```

Ak kompilátor nevie nájsť, zlyhá konfigurácia:

```text
  is not a full path to an existing compiler tool.

  Tell CMake where to find the compiler by setting either the environment
  variable "CC" or the CMake cache entry CMAKE_C_COMPILER to the full path to
  the compiler, or to the compiler name if it is in the PATH.
```

Oprava: nainštaluj a pripoj gcc podľa návodu [Inštalácia kompilátora GCC](../gcc/) (na Windowse je to
`C:\msys64\ucrt64\bin` alebo `C:\mingw64\bin` v PATH), a adresár `build` po oprave zmaž (`rm -rf build`) – CMake má zlý
kompilátor
navždy zapísaný v cache.

### Užitočné príkazy

| Chcem                  | Príkaz                                                |
|------------------------|-------------------------------------------------------|
| Postaviť               | `cmake --build build`                                 |
| Paralelne (rýchlejšie) | `cmake --build build -j 4`                            |
| Iba jeden cieľ         | `cmake --build build --target gamestats`              |
| Zmazať výstupy / cache | `cmake --build build --target clean` / `rm -rf build` |
| Debug build            | `cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug`        |
| Optimalizovaný build   | `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release`      |
| Zmeniť flagy           | uprav `CMakeLists.txt` a znovu `cmake --build`        |

Zmena v `CMakeLists.txt` sa aplikuje sama pri ďalšom `cmake --build` (Makefile CMake znovu zavolá).

## CLion – rovnaký projekt myšou

CLion je IDE, ktoré projekt **číta priamo z `CMakeLists.txt`** – žiadne nastavovanie buildu.

1. **File → Open** a vyber **koreňový adresár** projektu (CLion sám nájde `CMakeLists.txt`). Neotváraj
   `src/main.c` jednotlivo.
2. Po otvorení prebehne automatická konfigurácia. Ak CLion nenájde kompilátor, vyber ho v **Settings → Build, Execution,
   Deployment → Toolchains** – na Windowse zvoľ `MinGW` s cestou na
   `C:\mingw64\bin\gcc.exe` (CLion vie MinGW nástroj aj sám stiahnuť).
3. **🔨 Build** (`Ctrl+F9`) = `cmake --build`, **▶️ Run** (`Shift+F10`) = spustí cieľ (v predvolenej klávesnici; meniť sa
   dá v Settings → Keymap). Vpravo hore
   prepínaš, ktorý cieľ sa builduje/spúšťa.
4. **Run → Edit Configurations**: tu nastav **Program arguments** a hlavne **Working directory** –
   ak program číta súbory (cvičenie 5), v CLion beží z iného adresára než v termináli a súbor nenájde.
5. **Ladenie**: klik do riadku → breakpoint, **🐛 Debug** (`Shift+F9`). Premenné a callstack ukazuje okná
   samy; `gdb` pod kapotou vybavuje CLion.
6. Keď niečo "nesedí", pomocou menu **Tools → CMake → Reset Cache and Reload Project** – je to to isté ako
   `rm -rf build` v termináli.

> [!TIP]
> Študentskú licencu na CLion (aj cały balík JetBrains) dostaneš zdarma cez JetBrains Education –
> stačí školský e-mail. Predmet odporúča CLion pri C++ cvičeniach; na prednáškach/cvičeniach stačí
> gcc + ľubovoľný editor, takže IDE nikdy nie je podmienka.

## Viac cieľov a knižnica (voliteľné)

Rastúci projekt si vyžiada rozdeliť kód: spoločná logika ako knižnica, viac programov.

```cmake
cmake_minimum_required(VERSION 3.20)
project(herny_statistik C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(statistika STATIC src/statistika.c)
target_compile_options(statistika PRIVATE -Wall -Wextra)

add_executable(gamestats src/main.c)
target_compile_options(gamestats PRIVATE -Wall -Wextra)
target_link_libraries(gamestats statistika m)

add_executable(dennik src/dennik.c)
target_link_libraries(dennik statistika m)
```

`add_library` zostaví statickú knižnicu (`.a`) a `target_link_libraries` ju napojí do oboch programov.
CLion zobrazí všetky tri ciele v dropdowne. Príjemný vedľajší efekt: knižnica sa kompiluje raz a varovania
počúvaš z jedného miesta.

## Najčastejšie chyby

### ❌ `The source directory ... does not appear to contain CMakeLists.txt`

CMake spustený z nesprávneho adresára (alebo CLion otvoril `src/`). Skontroluj, kde si (`pwd`), a púšťaj
konfiguráciu z koreňa projektu.

### ❌ `undefined reference to 'priemer'` pri buildu

Súbor s implementáciou chýba v zozname `add_executable`/`add_library`. Dopíš ho; CMake cache (`rm -rf build`) netreba,
stačí `cmake --build build`.

### ❌ Zmenil som CMakeLists a nič sa nestalo

Zmeny v `CMakeLists.txt` sa aplikujú až pri ďalšom buildu – v termináli znovu `cmake -S . -B build`,
v CLion **Reload CMake Project** (chybové notifikácie IDE ukáža pri návestí kurzora na vlnovku).

### ❌ Program v CLion nájde súbor, ale v termináli nie (a naopak)

Spúšťaj z rovnakého **Working directory**. V CLion to nastav v Run/Debug Configurations; v termináli
púšťaj `./build/gamestats` z koreňa projektu.

### ❌ Zdrojový adresár zasýpaný súbormi po in-source buildu

Ak si raz spustil `cmake .`, adresár je plný dočasných výstupov `CMakeCache.txt`, `Makefile`, `CMakeFiles/`.
Zbav sa ich a nabudúce vždy `-B build`:

```bash
rm -rf CMakeCache.txt CMakeFiles Makefile cmake_install.cmake
```

## Rýchly referenčný list

| Akcia           | Terminál                 | CLion                              |
|-----------------|--------------------------|------------------------------------|
| Konfigurácia    | `cmake -S . -B build`    | automaticky / Reload CMake Project |
| Build           | `cmake --build build`    | 🔨 `Ctrl+F9`                       |
| Spustenie       | `./build/gamestats`      | ▶️ `Ctrl+Shift+F10`                 |
| Parametre + cwd | argumenty za príkazom    | Run → Edit Configurations          |
| Ladenie         | `gdb ./build/gamestats`  | breakpoint + `Shift+F9`            |
| Reset cache     | `rm -rf build`           | Tools → CMake → Reset Cache        |
| Debug/Release   | `-DCMAKE_BUILD_TYPE=...` | CMake profile                      |

## Ďalšie zdroje

- Návod [Štruktúra C projektu a Makefile](../project_and_makefile/) – jednoduchá alternatíva bez CMake
- Návod [Inštalácia kompilátora GCC](../gcc/) – čo je gcc a ako ho zohnať na svojej platforme
- Návod [Chyby v C](../c_errors/) – linkovanie a `undefined reference` do detailov
- [CMake tutorial (oficiálny)](https://cmake.org/cmake/help/latest/tutorial/index.html) – interaktívny kurz
- [CLion docs – CMake](https://www.jetbrains.com/help/clion/cmake-support-in-clion.html) – integrácia IDE

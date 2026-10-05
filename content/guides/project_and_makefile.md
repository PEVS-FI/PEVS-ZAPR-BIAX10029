---
date: '2026-10-05T16:00:00+02:00'
title: 'Štruktúra C projektu a práca s Makefile'
---

Dobré nastavenie projektu nie je ozdoba – je to časť tvojho hodnotenia (štruktúra kódu, čitateľnosť, spracovanie
vstupov) a hlavne vec, ktorú oceníš ty sám, keď sa k programu vrátíš o dva týždne. Tento návod ukazuje, ako si
nastaviť projekt v C, čo v ňom nesmie chýbať a ako ho ovládať cez `make`.

## Štruktúra projektu

Pre projekty v tomto kurze (aj semestrálne zadanie) použij takúto štruktúru:

```
muj-projekt/
├── .gitignore          # to, čo Git má ignorovať (binárky, dočasné súbory)
├── Makefile            # predpis na zostavenie projektu
├── README.md           # popis projektu pre človeka
└── src/                # zdrojové kódy
    ├── main.c          # main funkcia a načítanie vstupov
    ├── statistika.c    # implementácia funkcií
    └── statistika.h    # deklarácie (prototypy) funkcií
```

Po kompilácii pribudne adresár `bin/` so spustiteľným súborom a objektovými súbormi – ten do Gitu nepatrí.
Presne tento vzor používajú aj zadania (zdrojový kód v `src/main.c`, výstup do `bin/`).

> [!IMPORTANT]
> Polohy súborov sú súčasťou zadania. Ak zadanie vyžaduje `src/main.c`, umiestnenie mimo túto cestu sa pri
> hodnotení nezohľadňuje.

## Čo v projekte nesmie chýbať

| Súčasť | Na čo slúži |
|--------|-------------|
| `README.md` | Čo projekt je, ako ho skompilovať a spustiť – prvá vec, ktorú uvidia hodnotitelia |
| `.gitignore` | Zabráni nahodeniu `bin/`, `.o`, `.exe` a dočasných súborov do repozitára |
| `Makefile` | Jednotné a zopakovateľné zostavenie príkazom `make` |
| `src/` | Zdrojové kódy prehľadne na jednom mieste |
| Hlavičky (`.h`) | Deklarácie funkcií oddelené od implementácie |
| Rozdelenie do funkcií | Aspoň `main` + logika + výpočty + výpisy – nie 200 riadkov v hlavnej funkcii |
| Ošetrenie vstupov | Kontrola záporných hodnôt, delenia nulou, nečíselného vstupu |

### A čo v projekte byť nemá

- Skompilované výstupy (`.o`, `a.out`, `program.exe`, obsah `bin/`) v Gitu
- Absolútne cesty (`C:\Users\jano\Plocha\zadanie\...`) – projekt musí byť presunuteľný
- Duplikovaný kód – ten istý úsek radšej vyniesť do funkcie a volať ju
- Zakomentovaný kód „možno sa ešte zíde“ – na to je Git a jeho história

## README.md – minimum, ktoré obstojí

```markdown
# Gamestats – kalkulátor herných štatistík

Autor: Ján Novák, BIAX10029 (zadanie 1)

## Kompilácia
make
alebo: gcc -std=c17 -o bin/gamestats -Wall -Wextra src/main.c

## Spustenie
./bin/gamestats --kills 25 --deaths 10 --assists 15 --duration 35

## Funkcionalita
- výpočet K/D, KDA, KPM, APM a performance skóre
- priradenie ranku podľa zadania, ošetrenie neplatných vstupov
```

Odpovedaj na otázky, ktoré si kladie čitateľ: *Čo to je? Ako to spustím? Čo to očakáva na vstupe?*

## .gitignore

Pre C projekt v tomto predmete stačí:

```gitignore
# kompilačné výstupy
bin/
*.o
*.d
*.exe
a.out

# editor a systémové súbory
.vscode/
.idea/
*.swp
Thumbs.db
```

Súbor patrí do koreňa projektu a **sám sa do Gitu committuje** – každý, kto projekt klonuje, musí mať rovnaké
pravidlá.

## Makefile – prečo ho používať

Bez neho pri každej zmene dopisuješ do terminálu dlhý kompilačný príkaz (a zabúdaš naň). Makefile ti dá tri veci:

1. **Príkaz `make`** zostaví projekt podľa predpisu, ktorý si raz napísal.
2. **Rekompiluje len to, čo sa zmenilo** – podľa časových pečiatok súborov.
3. **Rovnaké správanie** u teba, u spolužiaka aj v hodnotiacom pipeline.

### Anatómia pravidla

Základná stavebná jednotka je pravidlo: **cieľ, závislosti, príkazy**. Riadok s príkazom musí začínať znakom
TAB, nie medzerami – to je najčastejšia príčina chýb začiatočníkov.

```makefile
program: main.c
	gcc -std=c17 -Wall -Wextra main.c -o program
```

Použitie:

```bash
make program     # zostaví cieľ 'program'
make             # bez argumentu zostaví prvý cieľ v súbore (tradične 'all')
```

Keď je `main.c` novší ako `program`, make ho rekompiluje. Ak nič nie je staré, vypíše
`make: Nothing to be done for 'all'.` – a to je správne, šetrí to čas.

### Makefile pre väčší projekt

Odskúšaný predpis pre projekt s viacerými zdrojovými súbormi (`src/*.c` → `bin/*.o` → `bin/gamestats`):

```makefile
CC      := gcc
CFLAGS  := -std=c17 -Wall -Wextra -g -MMD -MP
BIN_DIR := bin
SRC_DIR := src
TARGET  := $(BIN_DIR)/gamestats

ZDROJE  := $(wildcard $(SRC_DIR)/*.c)
OBJEKTY := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(ZDROJE))

all: $(TARGET)

$(TARGET): $(OBJEKTY)
	$(CC) $(OBJEKTY) -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET) --help

clean:
	rm -rf $(BIN_DIR)

.PHONY: all run clean

-include $(OBJEKTY:.o=.d)
```

Rozobraté kúsky:

| Zápis | Význam |
|-------|--------|
| `CC := gcc` | premenná s kompilátorom; `:=` sa vyhodnotí hneď pri čítaní súboru |
| `$(wildcard src/*.c)` | zoznam všetkých `.c` súborov v priečinku |
| `$(patsubst src/%.c,bin/%.o,...)` | prepíše `src/main.c` na `bin/main.o` |
| `%.o: %.c` | pattern – pravidlo platí pre *akýkoľvek* súbor, make dosadí meno |
| `$@` | cieľ aktuálneho pravidla (napr. `bin/main.o`) |
| `$<` | prvá závislosť (napr. `src/main.c`) |
| `$^` | všetky závislosti (všetky `.o` súbory pri linkovaní) |
| `-MMD -MP` | kompilátor pri kompilácii píše `.d` súbor so závislosťami na hlavičky |
| `-include *.d` | make vďaka tomu vie, že zmena `.h` znamená rekompiláciu `.c` |
| `.PHONY: all run clean` | ciele, ktoré nie sú súbormi – fungujú aj keď súbor `clean` existuje |
| `@mkdir -p` | potichu vytvorí `bin/` – `make` funguje aj z čistého checkoutu |

> [!NOTE]
> Bez `-MMD -MP` a `-include` si make pamätá iba závislosti, ktoré napíšeš ručne. Zmeníš `statistika.h`, ale
> `main.o` sa neprekompiluje – a ty sa čuduješ, prečo program stále beží so starým správaním.

### Ciele, ktoré sa ti hodia

- `make` – zostaviť projekt (cieľ `all`)
- `make run` – zostaviť a hneď spustiť so základným argumentom
- `make clean` – zmazať výsledky kompilácie; pred odovzdaním zadania sprav `make clean` a znova `make`,
  aby si overil, že projekt zostaví od nuly
- Ladenie so sanitizermi – nepotrebuješ samostatný cieľ, stačí dočasne prepísať premennú:
  `make CFLAGS="-std=c17 -Wall -Wextra -g -fsanitize=address"`

## Práca s make

```bash
make -j4                            # paralelne, až 4 kompilácie naraz (rýchlejšie pri väčších projektoch)
make -n                             # iba ukáže, čo by make spravil (suchý chod)
make clean all                      # zmazať a zostaviť od nuly
make program CFLAGS="-std=c17 -O2"  # dočasne prepísať premennú z príkazového riadku
```

Make sa rozhoduje podľa **časových pečiatok**: súbor spracuje, ak je jeho závislosť novšia ako výstup. Ak chceš
nútenú rekompiláciu všetkého, použi `make clean` a znova `make`.

> [!WARNING]
> Na Windowse: WinLibs balík obsahuje `make` priamo. Iné distribúcie (niXman) prinášajú len `mingw32-make` –
> vtedy zavolaj `mingw32-make`, alebo si v `C:\mingw64\bin` vytvor kópiu pomenovanú `make.exe`.
> Príkazy v pravidlách sa na Windowse spúšťajú cez CMD – `rm -rf` nefunguje, do cieľa `clean` napíš
> `rmdir /s /q $(BIN_DIR)`, alebo používaj make z Git Bash.

## Najčastejšie chyby

### ❌ `Makefile:7: *** missing separator. Stop.`

Príkazový riadok nezačína TAB-om, ale medzerami. Zapni v editore "zobrazovať biele znaky" a v pravidle trvajte
na TAB-e (v premenných sa medzery na začiatok riadku nedávajú).

### ❌ Zmenil som hlavičku a `make` nič nerobí

Chýbajú závislosti na `.h` súbory. Riešením je `-MMD -MP` + `-include` z ukážkového Makefile vyššie, alebo
dopíš závislosti ručne: `$(BIN_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/statistika.h`.

### ❌ `make clean` povie "make: 'clean' is up to date."

V adresári existuje priečinok alebo súbor menom `clean` a make si myslí, že cieľ je hotový. Pridaj
`.PHONY: clean` (a ďalšie nesúborové ciele).

### ❌ `undefined reference to 'sqrt'`

Na Linuxe a macOS pripoj matematickú knižnicu pri linkovaní: do pravidla pre `$(TARGET)` pridaj `-lm`
až **za** objektové súbory. Podrobnosti v návode [Inštalácia kompilátora GCC](../gcc/).

### ❌ Po `git clone` projekt nejde zostaviť

Nahodil si do Gitu skompilované `.o` súbory a chýbajú zdrojové kódy – alebo v pravidle chýba `mkdir -p`.
Skontroluj `.gitignore` a nechaj make vytvoriť `bin/` sám.

## Rýchly referenčný list

| Chcem | Príkaz |
|-------|--------|
| Zostaviť projekt | `make` |
| Zostaviť konkrétny cieľ | `make run`, `make program` |
| Zmazať výsledky | `make clean` |
| Pozrieť, čo make spraví | `make -n` |
| Rýchlejší build | `make -j4` |
| Dočasná zmena prepínačov | `make CFLAGS="…"` |

## Ďalšie zdroje

- Návod [Inštalácia kompilátora GCC](../gcc/) – kompilačné prepínače a chyby pri linkovaní
- Návod [Práca v termináli pre začiatočníkov](../how_on_terminal/) – spúšťanie programov, presmerovanie
- Návod [Git pre začiatočníkov](../git_for_beginners/) – commitovanie zdrojových súborov, nie binárnych výstupov
- [GNU Make Manual](https://www.gnu.org/software/make/manual/) – kompletná dokumentácia make

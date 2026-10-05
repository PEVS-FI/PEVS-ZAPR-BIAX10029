---
date: '2026-10-05T14:00:00+02:00'
title: 'Práca v termináli pre začiatočníkov'
---

Terminál (konzola, príkazový riadok) je textové okno, v ktorom ovládaš počítač príkazmi. V tomto predmete ho potrebuješ
na kompiláciu programov (`gcc -std=c17 ...`), na spúšťanie a testovanie zadaní a na prácu s Gitom. Tento návod ťa
naučí to, čo skutočne potrebuješ – nič viac.

> [!TIP]
> Príkazy v návode sú rozdelené podľa systému. Ak používaš **PowerShell** (Windows), väčšina "unixových" príkazov ako
> `ls`, `cd` alebo `pwd` funguje tiež – PowerShell ich má nastavené ako aliasy.

## Ktorý terminál použiť

| Systém | Terminál | Shell |
|--------|----------|-------|
| Windows 10/11 | **PowerShell** (alebo *Windows Terminal*) | PowerShell |
| Linux (Ubuntu, Fedora...) | Terminal / Konsole | bash alebo zsh |
| macOS | Terminal | zsh |

Na Windowse sa stretneš aj so starým **CMD** (Príkazový riadok). Funguje podobne, ale odporúčame PowerShell –
je modernší a použiješ ho aj v [návode na inštaláciu GCC](../gcc/).

## Ako vyzerá príkaz

Každý príkaz má rovnakú kostru:

```
príkaz    parametre    prepínače
──────    ─────────    ─────────────
cd        Documents
gcc       main.c       -std=c17 -Wall
```

- **Príkaz** – čo má terminál urobiť (vždy ako prvé).
- **Parametre** – nad čím to má urobiť (súbory, priečinky...).
- **Prepínače** – voľby, ako to má urobiť (zvyčajne začínajú na `-` alebo `--`).

Príkaz spustíš stlačením **Enter**. Kým Enter nedáš, nič sa nedeje – môžeš text ešte upraviť.

## Kde som a kam ísť

Základ každého terminálu: orientácia v priečinkoch.

```bash
pwd              # vypíše, v akom priečinku práve som (print working directory)
ls               # vypíše obsah priečinka (Windows aj dir)
cd Documents     # vojdem do priečinka Documents
cd ..            # o jeden priečinok späť (hore)
cd ~             # domovský priečinok (Windows: %USERPROFILE%)
```

> [!IMPORTANT]
> `cd` mení priečinok **vnútri terminálu**, nie v oknách Prieskumníka. Každé nové okno terminálu začína opäť v
> domovskom priečinku.

**Absolútna a relatívna cesta.** Zapisovať ich môžeš dvoma spôsobmi:

```bash
cd C:\Users\jano\skola\zapr           # absolútna cesta – od koreňa disku
cd skola/zapr                          # relatívna cesta – od aktuálneho priečinka
```

Na Windowse funguje v PowerShell aj obrátenka `\`, aj lomítko `/`. Na Linuxe a macOS vždy len `/`.

**Tip, ktorý šetrí prsty:** počas písania stlač **Tab** a terminál doplní názov priečinka alebo súboru.
Dvojitý Tab ukáže všetky možnosti.

## Spúšťanie programov

Program, ktorý si skompiloval, spustíš takto:

```bash
./program            # Linux / macOS
program.exe          # Windows CMD
.\program.exe        # Windows PowerShell – predpona .\ je povinná!
```

Parametre zadáš za názov programu:

```bash
./program --help
./gamestats --kills 25 --deaths 10 --assists 15 --duration 35
```

Program ukončíš príkazom `Ctrl+C` (zastav aj program, ktorý beží donekonečna alebo čaká na vstup).

## Práca so súbormi a priečinkmi

```bash
mkdir skola                 # vytvorí priečinok
cp program.c zaloha.c       # skopíruje súbor (Windows: copy)
mv program.c src/           # presunie / premenuje (Windows: move)
cat zadanie.txt             # vypíše obsah súboru (Windows: type, Get-Content)
rm subor.txt                # vymaže súbor (Windows: del)
rm -r stary_priecinok       # vymaže priečinok so všetkým (Windows: rmdir /s)
```

> [!WARNING]
> `rm` (a `del`) mažú **natvrdo – nie do koša**. Obsah priečinka s `.c` súbormi maž len vtedy, ak vieš, čo robíš.
> Pred `rm` si vždy skontrol cestu príkazom `pwd`.

## Presmerovanie: výstup do súboru

Pri testovaní zadaní sa ti hodí uložiť výstup programu do súboru:

```bash
./program > vystup.txt      # výpis programu sa uloží do vystup.txt (prepíše ho)
./program >> vystup.txt     # pridá výpis na koniec súboru (neprepíše)
./program < vstup.txt       # program číta vstup zo súboru (nie z klávesnice)
```

| Znak | Čo robí |
|------|---------|
| `>`  | výstup do súboru (prepíše) |
| `>>` | výstup do súboru (pripojí na koniec) |
| `<`  | vstup zo súboru |
| `\|` | výstup jedného príkazu ako vstup druhého (rúra) |

> [!NOTE]
> Príkaz `<` (vstup zo súboru) funguje v CMD, Linuxe a macOS, ale **v PowerShell nie**. Vo Windows namiesto
> `.\program.exe < vstup.txt` použi rúru:
> ```powershell
> Get-Content vstup.txt | .\program.exe
> ```

Rúra `|` je užitočná aj pri hľadaní vo výpise:

```bash
gcc main.c -std=c17 2>&1 | grep warning    # ukáže len riadky s varovaním (Linux/macOS)
dir | more                                   # výpis po stránkach (Windows)
```

## Klávesové skratky, ktoré sa hodia

| Skratka | Čo urobí |
|---------|----------|
| `Tab` | doplní názov (priečinok/súbor/príkaz) |
| `↑` / `↓` | história príkazov (predchádzajúce príkazy) |
| `Ctrl+C` | zastavi aktuálny príkaz/program |
| `Ctrl+L` | vyčistiť obrazovku (Linux/macOS; `clear`/`cls` všade) |
| `Ctrl+Shift+V` | vložiť text do terminálu (PowerShell, Windows Terminal) |

## Najčastejšie chyby začiatočníkov

### ❌ PowerShell: `'program.exe' nie je rozpoznaný ako názov príkazu`

PowerShell **nespustí** program z aktuálneho priečinka bez predpony. Napiš:

```powershell
.\program.exe
```

### ❌ CMD: `cd` nezmenilo priečinok, som stále na C:

Na Windowse v CMD samotné `cd D:\skola` disk neprepne. Skús:

```cmd
cd /d D:\skola
```

alebo najprv prepni disk príkazom `D:` a potom `cd`.

### ❌ Príkaz nenájde súbor, hoci tam je

Cesta obsahuje **medzery** (`C:\Moje Veci\program.exe`). Obal ju do úvodzoviek:

```powershell
& "C:\Moje Veci\program.exe" --help
```

### ❌ Pokrivená slovenčina vo výstupe

Terminál nepoužíva UTF-8. V CMD a PowerShell pomôže:

```cmd
chcp 65001
```

Podrobnejšie riešenie je v návode [Inštalácia kompilátora GCC](../gcc/).

### ❌ Zasekol sa program a čaká na vstup

Stlač `Ctrl+C`. Ak program očakáva vstup z klávesnice (napr. `scanf`), kurzor len bliká – program čaká na hodnotu.
Napíš požadovaný vstup, alebo program zastav príkazom `Ctrl+C`.

## Rýchly referenčný list

| Chcem | Linux / macOS | Windows (PowerShell) |
|-------|---------------|----------------------|
| Kde som | `pwd` | `pwd` (alebo `cd` naprázdno) |
| Čo je tu | `ls` | `ls` alebo `dir` |
| Ísť o patro hore | `cd ..` | `cd ..` |
| Domov | `cd ~` | `cd ~` |
| Vymazať súbor | `rm subor` | `del subor` |
| Vyčistiť obrazovku | `clear` | `cls` |
| Skompilovať a spustiť | `gcc -std=c17 -o program main.c && ./program` | `gcc -std=c17 -o program main.c; .\program.exe` |

> [!TIP]
> Spájanie príkazov: na Linuxe/macOS `&&` spustí druhý príkaz len ak prvý uspel, `;` spustí druhý vždy.
> PowerShell pozná `&&` od verzie 7 a `;` vždy. Na Windowse skúš radšej `;`, ak ti `&&` nefunguje.

## Ďalšie zdroje

- Návod [Inštalácia kompilátora GCC](../gcc/) – inštalácia, kompilácia a časté chyby
- Návod [Git pre začiatočníkov](../git_for_beginners/) – inštalácia Gitu funguje najľahšie práve cez terminál
- [ExplainShell](https://explainshell.com/) – rozloží akýkoľvek príkaz a vysvetlí jeho časti

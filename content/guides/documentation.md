---
date: '2026-10-05T18:00:00+02:00'
title: 'Písanie dokumentácie: prečo, čo, kedy a kde'
---

Dokumentácia je súčasť programu, nie ozdobný bonus navyše. Poznáš to: vrátiš sa k vlastnému kódu po dvoch týždňoch
a nevieš, prečo tam je tá podmienka, čo čaká tá funkcia ani ako program spustiť. Dobrá dokumentácia odpovedá na tieto otázky
skôr, než vôbec vzniknú.

## Prečo písať dokumentáciu

- **Pre seba.** O týždeň zabudneš, prečo si kontroloval `deaths == 0` pred delením. Dokumentácia je pamäť, ktorá
  netrpí amnéziou.
- **Pre hodnotiteľa.** Zadácia sa hodnotia aj ručne – okrem iného podľa *štruktúrovania kódu*. Čitateľný README a
  komentáre kód nezlepšia, ale ukážu, že projekt zvládneš nielen napísať, ale aj odovzdať.
- **Pre ďalšieho človeka.** Spolužiaka, ktorý si chce spustiť tvoju ukážku, alebo seba v budúcom semestri, keď na
  tomto projekte budeš stavať ďalej.
- **Lebo kód odpovedá na „ako", dokumentácia na „prečo" a „na čo".** Kompilátor zistí, či kód funguje; či je
  zrozumiteľný, zistí až čitateľ.

Platí jednoduché pravidlo: z dokumentácie spoznáš stav projektu rovnako ako z varovaní kompilátora.

## Úrovne dokumentácie projektu

| Úroveň | Kde žije | Kto ju číta |
|--------|----------|-------------|
| `README.md` | koreň repozitára | ktokoľvek – prvý kontakt s projektom |
| komentáre v kóde | zdrojové súbory | udržiavateľ, hodnotiteľ |
| hlavičky funkcií (Doxygen) | zdrojové súbory, prípadne generovaný HTML | ten, kto funkciu používa |
| commit messages | história Gitu | ten, kto zisťuje, prečo sa čo zmenilo |

Tento návod sa venuje prvým trom úrovniam; o štvrtej sa dočítaš v [návode o Gite](../git_for_beginners/).

## README.md – brána k projektu

README sa číta skôr, než kód. Malo by odpovedať na štyri otázky: *Čo to je? Ako to skompilujem? Ako to spustím?
Čo to očakáva na vstupe?*

```markdown
# Gamestats – kalkulátor herných štatistík

Autor: Ján Novák, BIAX10029 (zadanie 1)

## Čo program robí
Vypočíta zadané herné metriky (K/D, KDA, KPM, APM), performance skóre a rank.

## Kompilácia
make
alebo: gcc -std=c17 -o bin/gamestats -Wall -Wextra src/main.c

## Spustenie
./bin/gamestats --kills 25 --deaths 10 --assists 15 --duration 35
./bin/gamestats --help

## Argumenty
Povinné: --kills, --deaths, --assists, --duration (celé čísla)
Voliteľné: --headshots, --teamkills, --mvp

## Štruktúra projektu
src/main.c – main a spracovanie vstupov; src/statistika.c/.h – výpočty a rank.
```

Pravidlá dobrého README:

- **Príkazy musia byť skopírovateľné.** Nie „skompiluješ podobne ako minule", ale presný príkaz.
- **Ukážka vstupu a výstupu** povie viac ako odstavec opisu – skopíruj reálny beh programu.
- **Stručnosť nad rozvláčnosť.** Väčšie témy (inštalácia, návrh riešenia) patria do samostatných súborov v
  `docs/`; README nech je jedna stránka.

## Komentáre v kóde

### Komentuj prečo, nie čo

Komentár, ktorý opisuje kód, je stratený čas. Kód hovorí *čo* robí; komentár má vysvetliť *prečo* je tam.

```c
// CHYBA: komentár len opisuje to, čo je vidno v kóde
int pocet = nacitaj();

// SPRÁVNE: komentár vysvetľuje rozhodnutie, ktoré kód sám nevie povedať
// Limit 100 zodpovedá maximálnemu počtu hier v testovacej sade zadania.
int pocet = nacitaj();
```

### Vysvetli prekvapivé konštanty a výnimky

```c
// Delenie nulou: pri 0 deaths chápeme K/D = kills,
// inak by program spadol na Floating point exception.
double kd = (deaths == 0) ? (double)kills : (double)kills / deaths;
```

```c
// CHYBA: TODO bez kontextu sa o mesiac stane súčasťou kódu
// TODO: doladit

// SPRÁVNE: TODO má tri časti – čo, kde a do kedy
// TODO (jano): ošetriť EOF zo scanf() – súvisí s úlohou 6.2, dokončiť pred odovzdaním
```

### Čo do kódu nepatrí

- **Zakomentovaný starý kód.** Históriu si pamätá Git – zmáž ho a neduplikuj.
- **Komentár, ktorý sa rozchádza s kódom.** Horší ako žiadny – klame. Meníš kód, v tom istom commite zmeň aj
  komentár.
- **Komentár na každom riadku.** Stena šumu skryje tie tri, ktoré stoja za to.

## Hlavička funkcie a Doxygen

Každá funkcia, ktorá nie je úplne triviálna, by mala mať nad sebou krátky komentár: čo robí, čo potrebuje a čo
vracia. V C sa osvedčil štýl Doxygen – taký komentár vyzerá takto:

```c
/**
 * @brief Vypočíta aritmetický priemer prvkov poľa.
 *
 * Využíva sa pri výpočte priemeru skóre za všetky hry.
 *
 * @param pole   Ukazovateľ na prvý prvok poľa.
 * @param n      Počet prvkov poľa; musí byť kladný.
 * @return Priemer; pre n <= 0 vráti 0.0.
 */
double priemer(const int *pole, int n);
```

Z takto označených komentárov vygeneruje nástroj `doxygen` prehľadnú HTML dokumentáciu. Na odovzdanie zadania ho
nepotrebuješ – stačí README a komentáre – ale návyk „každá funkcia má hlavičku" sa oplatí aj mimo predmetu.
Editory (VS Code, CLion) hlavičky rozumejú a ukazujú ich pri kontextovej nápovede.

## Kedy písať dokumentáciu

- **Pred kódom.** README s tým, čo program bude vedieť, je zmluva – ujasníš si hranice projektu skôr, než napíšeš
  prvú funkciu.
- **Počas kódovania.** Ku každej hotovej funkcii pridaj hlavičku hneď, kým vieš, prečo si ju riešil takto.
  Platí: funkcia bez dokumentácie nie je hotová.
- **Pri každom commite.** Správa commitu je dokumentácia zmeny pre budúceho teba:
  „pridaná kontrola delenia nulou v kd() – spadalo pri deaths=0".
- **Pred odovzdaním.** Skús projekt presne podľa README skompilovať a spustiť. Čo v ňom nefunguje, je chyba
  v dokumentácii – alebo v projekte.

A nikdy nie „až na konci". Na konci už nepíšeš dokumentáciu, ale archeológiu.

## Kde dokumentáciu uchovávať

| Typ dokumentácie | Správne miesto | Nesprávne miesto |
|------------------|----------------|------------------|
| popis a spustenie projektu | `README.md` v koreňi | Word na ploche, chat |
| komentáre a hlavičky funkcií | priamo v `.c` / `.h` | samostatný textový súbor mimo kódu |
| architektúra, dlhšie návody | `docs/*.md` v repozitári | poznámky mimo repozitára |
| generovaný HTML (Doxygen) | adresár `doc/` (v Gitu, alebo sa regeneruje) | posielaný ako ZIP |

Základné pravidlo: **dokumentácia žije vedľa kódu, v tom istom repozitári** – len tak zostáva synchronizovaná
a zmena kódu pripomína, že sa má meniť tiež.

## Časté chyby

### ❌ Dokumentácia, ktorá neplatí

Kód sa zmenil, README nie. Čitateľ podľa neho spustí inú cestu alebo neexistujúci prepínač – a stratí dôveru.
Riešenie: zmena kódu a dokumentácie v tom istom commite; pred odovzdaním preber README ako checklist.

### ❌ README bez príkazu na spustenie

Popis „program počíta štatistiky" nikoho neposunie dopredu. Prvá vec, ktorú čitateľ potrebuje, je skopírovateľný
príkaz kompilácie a behu.

### ❌ Duplikovaná dokumentácia

Rovnaký text v README aj v komentári aj v `docs/` – pri prvej zmene sa rozíde. Napíš vec na jednom mieste a inde
na ňu odkáž: „Použitie argumentov: pozri README.md, časť Argumenty".

### ❌ Komentár = opis kódu

`// navratova hodnota je 0` nad `return 0;` je šum. Komentuj rozhodnutia, obmedzenia a súvislosti, ktoré kód
sám nevyjadrí.

## Rýchly referenčný list

| Úkon | Kde / ako |
|------|-----------|
| Čo dať do README | opis → kompilácia → spustenie → argumenty → ukážka výstupu |
| Komentár | prečo, nie čo; pri prekvapivých konštantách a ošetreniach |
| Hlavička funkcie | `@brief`, `@param`, `@return` (Doxygen štýl) |
| Kedy písať | pred kódovaním, pri funkcii, pri commite, pred odovzdaním |
| Kde uchovávať | vedľa kódu v repozitári; väčšie texty do `docs/` |

## Ďalšie zdroje

- Návod [Štruktúra C projektu a Makefile](../project_and_makefile/) – šablóna README a `.gitignore`
- Návod [Git pre začiatočníkov](../git_for_beginners/) – commit messages ako dokumentácia zmien
- [Doxygen manual](https://www.doxygen.nl/manual/) – syntax komentárov a generovanie dokumentácie

---
date: '2025-11-12T23:55:09+01:00'
title: 'Úloha 9.4'
weight: 4
---

Napíšte program, zdrojový kód, v jazyku C++, ktorý modeluje hierarchiu zamestnancov vo firme pomocou dedičnosti tried.
Program bude obsahovať tieto triedy:

Základná trieda: `Employee`

**Atribúty**:

* Meno zamestnanca (_string_)
* ID zamestnanca (_int_)

**Metódy**:

* Konštruktor na inicializáciu mena a ID.
* Virtuálna metóda `calculateSalary()`, ktorá vráti základný plat (napr. 1000 EUR).
* Metóda na výpis informácií o zamestnancovi.

Odvodená trieda: `Manager`

Dedí z triedy **Employee**.
**Atribúty**:

* Bonus (_float_)

**Metódy**:

* Preťaženie metódy `calculateSalary()`, ktorá vráti základný plat plus bonus.
* Metóda na nastavenie bonusu.

Odvodená trieda: `Intern`

Dedí z triedy **Employee**.
**Atribúty**:

* Počet hodín praxe (_int_)
* Sadzba za hodinu (_float_)

**Metódy**:

* Preťaženie metódy `calculateSalary()`, ktorá vypočíta plat ako počet hodín * sadzba za hodinu.

V rámci programu:

* Definujte všetky tri triedy a ich príslušné atribúty a metódy.
* Programe vytvorte pole zamestnancov, ktoré bude obsahovať objekty typu _Employee_, _Manager_, a _Intern_.
* Pre každý objekt zavolajte metódu `calculateSalary()` a vypíšte informácie o zamestnancovi vrátane vypočítaného platu.
* Využite princíp dedičnosti a polymorfizmus (virtuálne metódy). Použite dynamickú alokáciu objektov v poli
  zamestnancov.
  Dodržujte dobré princípy objektovo-orientovaného návrhu (napr. zapúzdrenie).

### Príklady vstupov / výstupov programu

Program môže obsahovať nasledovné objekty:

* Zamestnanec: Employee("Alice", 1)
* Manažér: Manager("Bob", 2, bonus = 500.0)
* Intern: Intern("Charlie", 3, hodiny = 20, sadzba = 10.0)

```text
Zamestnanec:
Meno: Alice, ID: 1, Plat: 1000.0

Manažér:
Meno: Bob, ID: 2, Plat: 1500.0

Stážista:
Meno: Charlie, ID: 3, Plat: 200.0
```

---

Tu neskôr pribudne príkladné riešenie

<!--

Musím si počkať kým sa tu objaví príklad riešenia.

Nezabudni, že najviac sa naučíš ak to vypracuješ sám. 😉

-->

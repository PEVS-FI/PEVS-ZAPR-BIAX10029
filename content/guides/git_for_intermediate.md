---
date: '2026-10-05T21:00:00+02:00'
title: 'Git pre mierne pokročilých'
---

Nadväzujeme na návod [Git pre začiatočníkov](../git_for_beginners/). Ten vysvetlil pojmy repozitár, commit, vetva
a základných desať príkazov (`init`, `clone`, `add`, `commit`, `push`, `pull`, `status`, `branch`, `checkout`,
`merge`). Tu sa učíš riešiť situácie, na ktoré základný návod nestačí: ako vrátiť zlý commit, ako vyriešiť
konflikt a ako bezpečne pracovať so vzdialeným repozitárom.

> [!NOTE]
> Všetky chybové výpisy v návode sú skutočné správy z gitu 2.55 – na iných verziách sa môžu mierne líšiť slovami,
> nie však významom.

## Tri oblasti, kde Git drží súbory

```
pracovná zložka  ──git add──▶  staging area  ──git commit──▶  história (repozitar)
   (súbory ako ich vidíš)         (pripravené zábery)           (minulosť, commit za commitom)
```

- **Pracovná zložka** – súbory, ktoré práve edituješ.
- **Staging area** – výber zmien, ktoré pôjdu do *budúceho* commitu. `git add` = "toto patrí do ďalšej fotografie".
- **História** – už uložené commity. Minulosť sa len tak neprepisuje – história sa skôr dopĺňa.

Pomôcka na kontrolu: `git diff` ukáže nezahalené zmeny, `git diff --staged` to, čo ide do commitu. Pred
`git commit` pozri `git status` – predídeš prekvapeniu, že si nahodil `bin/` alebo `.o` súbory.

## Pozeranie sa do histórie

```bash
git log                          # plný záznam – autor, dátum, diff
git log --oneline                # jeden riadok na commit
git log --oneline --graph        # s grafom vetiev
git show <hash>                  # čo presne zmenil konkrétny commit
git diff HEAD~1                  # zmena oproti predchádzajúcemu commitu
```

Pracovná ukážka grafu po zlúčení vetvy (typický tvar, keď niekto odbočil a vrátil sa):

```text
*   5594799 vyrieseny konflikt
|\
| * 3c81410 pridany bonus
* | 4a6af7f moja zmena
|/
* badf2bb pridana main.c
```

Commit nie je číslo poradia – je to **hash** (`5594799`, skrátený tvar). Plná hodnota je v `git log`.

## Krok späť: ako vrátiť to, čo sme pokazili

| Situácia | Príkaz |
|----------|--------|
| Zahodím nezahalené zmeny v súbore | `git restore subor.c` |
| Zruší prípravu na commit (zmeny v súbore ostávajú) | `git restore --staged subor.c` |
| Prepíšem message posledného commitu | `git commit --amend -m "novy text"` |
| Posledný commit bol chybný – bezpečné vrátenie | `git revert <hash>` (pridá nový commit, ktorý zmenu vráti späť) |
| Zmazať posledné commity a zmeny zachovať v stagingi | `git reset --soft HEAD~1` |
| Zmazať posledné commity aj so zmenami (pozor!) | `git reset --hard HEAD~1` |

> [!WARNING]
> `amend`, `reset` a čokoľvek, čo prepisuje minulosť, používaj len na commity, ktoré **ešte neboli pushnuté**.
> Cudzie kópie histórie po prepise nesadia – pri zdieľanom repozitári (aj ten tvoj k zadaniu) radšej
> commit vráť poctivým `git revert`.

### Vystrihnutie zo zlej vetvy

Zmeny omylom na `main`? Presuň ich do správnej vetvy:

```bash
git branch zachrana              # commit si podržíme v záložnej vetve
git reset --hard origin/main     # main vrátime na vzdialený stav (len kým NIC nie je pushnuté!)
git switch -c funkcia            # teraz pracujeme v správnej vetve
git cherry-pick <hash-zachrana>  # vybereme konkrétny commit
git branch -D zachrana           # zálohu zmažeme
```

## Vetvy naplno

```bash
git switch main                          # moderná náhrada za git checkout (checkout ostáva, switch je explicitnejší)
git switch -c funkcia-b                    # nová vetva od aktuálnej
git branch -a                             # lokálne + vzdialené vetvy
git merge funkcia-b                        # vtiahni zmenu do aktuálnej vetvy
git branch -d funkcia-b                    # zmaz len už zlúčenú vetvu
git push origin --delete funkcia-b         # a zmaž aj na vzdialenom
```

Zvyk, ktorý sa oplatí: **každá úloha = krátka vetva od `main`**, po dokončení merge späť a vetvu zmazať.
Vetva `main` je potom vždy funkčný stav projektu – presne takto vyzerá aj odovzdanie zadania (zmeny v `main`
v deadline = odovzdané).

Pomenovanie master/main: dnes sa nové repozitáry tvoria ako `main`. Ak ti niekde svieti `master`, nastav si to raz a
navždy: `git config --global init.defaultBranch main`.

## Vzdialený repozitár (origin)

```bash
git remote -v                    # kam pushuješ / odkiaľ pulluješ
git fetch                        # stiahni, ale NEZLUČ – najprv sa pozri
git pull                         # stiahne a hneď zlúči s vzdialenou vetvou
git push -u origin main          # prvý push vetvy + napojenie na upstream
git branch -vv                   # lokálne vetvy a ich upstream + oneskorenie
```

`git fetch` je bezpečnejší brat príkazu `git pull`: zmeny len stiahne, a kým si ich nepozrieš (`git log main..origin/main` alebo
`git diff`), nič sa ti v práci nezmenilo.

Stav "moja vetva zaostáva za origin/main" spoznáš podľa tohto výpisu pri pushi:

```text
 ! [rejected]        HEAD -> main (fetch first)
error: failed to push some refs to '...remote.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
```

Oprava: `git pull` → prípadne vyrieš konflikty (ďalej) → `git push`.

## Konflikty: ako sa čítajú a riešia

Nastanú vtedy, keď dve vetvy zmenili **rovnaké miesto** v súbore – Git nedokáže hádať, preto zastaví merge:

```text
Auto-merging main.c
CONFLICT (content): Merge conflict in main.c
Automatic merge failed; fix conflicts and then commit the result.
```

V súbore pribudú markery:

```c
int main(void) { return 0; }
<<<<<<< HEAD
// moja zmena
=======
// zmena z origin/main
>>>>>>> origin/main
```

Postup riešenia:

1. Otvor súbor a pri **každom** markeri sa rozhodni: moja verzia, ich, alebo oboje.
2. **Odstráň markery** `<<<<<<<`, `=======`, `>>>>>>>` – nemal by v súbore zostať ani jeden.
3. `git add subor.c` – tým povieš "konflikt je vyriešený".
4. `git commit` – Git predvyplní message o zlúčení; nech ho, história je potom prehľadnejšia.

Ak ti to celé prerastie cez hlavu, ústupová klapka:

```bash
git merge --abort     # vráti všetko späť do stavu pred merge
```

Prevencia je lacná: malé commity, časté `git pull`, a do rovnakého súboru v jeden deň nesiahnuť dvoma vetvami.

## Stash: odložiť rozrobenú prácu

Terminál ti nadáva pri prepnutí vetvy:

```text
error: Your local changes to the following files would be overwritten by checkout:
	main.c
Please commit your changes or stash them before you switch branches.
Aborting
```

Ak ešte nemáš čo commitnúť, odlož to do odkladiska:

```bash
git stash                 # "WIP" – uložím nezahalené zmeny a upracem pracovnú zložku
git stash list            # odkladiska: stash@{0}, stash@{1}, ...
git stash pop             # vráti najnovšie uložené a zmaže ho
```

```text
Saved working directory and index state WIP on main: 5594799 vyrieseny konflikt
Dropped refs/stash@{0}
```

Stash je dočasný parkovací pruh, nie úložisko na týždne.

## .gitignore v praxi

Súbor `.gitignore` v koreni hovorí, ktoré súbory Git *ignoruje* (prečítaj si [Štruktúra C projektu](../project_and_makefile/)):

```gitignore
bin/
*.o
*.d
*.exe
.vscode/
```

Základné pravidlá: `*` nepreskakuje `/` (nezahŕňa ďalší priečinok), adresár s koncovým `/` ignoruje celý
obsah, `!subor` znamená opak – výnimku. Overenie, či pravidlo sedí: `git check-ignore -v bin/gamestats`.

> [!TIP]
> Ak si omylom už nahodil binárku **predtým**, než si `.gitignore` vytvoril, ignorácia ju neodstráni – minulosť
> uprace až `git rm --cached subor` (súbor na disku zostane).

## Git pri odovzdávaní zadaní

Tvoj repozitár k zadaniu vznikol cez GitHub Classroom – máš svoju súkromnú kópiu s pripravenou štruktúrou.
Ako to prebieha v praxi:

1. Práca v malých commitoch; push do `main` kedykoľvek – **hodnotí sa posledný commit v `main` do termínu**.
2. **Upravuj len `src/`** – súbory pipeline (`.github/`) a testy (`test/`) v repozitári k zadaniu sa nesmú
   meniť; hrozí za to nulové hodnotenie.
3. Po odovzdaní ti cvičiaci vytvorí pull request `main` → `feedback`; hodnotenie a komentáre čítaš **v danom pull requesti**,
   nie v kóde samotnom. Diskusia je súčasťou výučby – odpovedať na komentár je normálna vec.
4. Ak PR ukazuje zelenú (pipeline OK) a ty vieš, že program nefunguje, rieš to v `main` ďalším commitom –
   pipeline beží pri každom pushi.

Pull request mimo zadania (spolupráca na examples, vlastný projekt) má rovnakú kostru: vetva → push → PR na
GitHub → revízia → merge. Práca s PR je najbezpečnejší spôsob, ako sa naučiť čítať cudzie diffy.

## Časté chyby

### ❌ `push rejected ... (fetch first)`

Niekto (aj tvoja druhá kópia) pushol skôr. Použi `git pull`, prípadne vyrieš konflikty, push znovu. Nikdy
nepouži `git push --force` ako prvú reakciu.

### ❌ Zabudnutý `.gitignore`, v histórii je 40 MB binárok

`.gitignore` ignoruje iba budúcnosť. Z budúcich commitov binárky odstrániš `git rm --cached`; história
bez binárok už chce prepis minulosti (len vo vlastnom súkromnom repozitári!). Najlepšia obrana: `.gitignore` ako prvý commit.

### ❌ „Detached HEAD"

`git checkout <hash>` ťa vytrhol z akejkoľvek vetvy – commity, ktoré tu vytvoríš, nikam nepatria.
Návrat: `git switch main` (alebo si z toho stavu vytvor vetvu `git switch -c zachrana`).

### ❌ Strach z konfliktu po `git pull`

Konflikt **nepoškodí** tvoju prácu – práve naopak, zastaví sa a pýta sa. Markery, `add`, `commit`. A ak je to
moc, `git merge --abort` a si presne tam, kde si bol pred pullom.

## Rýchly referenčný list

| Situácia | Príkaz |
|----------|--------|
| Kde som, čo je zmenené | `git status -sb` |
| Čo ide do commitu | `git diff --staged` |
| Vráti nezahalené zmeny | `git restore subor.c` |
| Prepis posledného commitu (len nepushnutého) | `git commit --amend` |
| Bezpečné vrátenie commitu | `git revert <hash>` |
| Stiahni a pozri, ale nemeň | `git fetch` + `git log main..origin/main` |
| Konflikt – storno | `git merge --abort` |
| Odložiť rozrobené | `git stash` / `git stash pop` |
| Zoznam vetiev + upstream | `git branch -vv` |
| Ísť do novej vetvy od main | `git switch -c funkcia` |
| Ísť do existujúcej vetvy | `git switch main` |
| Prečo je súbor ignorovaný | `git check-ignore -v subor` |

## Ďalšie zdroje

- Návod [Git pre začiatočníkov](../git_for_beginners/) – základné pojmy a príkazy
- Návod [Štruktúra C projektu a Makefile](../project_and_makefile/) – čo a ako ignorovať v C projekte
- [Pro Git book](https://git-scm.com/book/en/v2) – kompletná kniha o Gite (zadarmo, anglicky)
- [GitHub Docs – About pull requests](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests)

---
date: '2025-11-12T23:39:45+01:00'
title: '📚 Úloha 8.4'
weight: 4
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý vytvorí štruktúru na reprezentáciu knihy v
knižnici.

Štruktúra by mala obsahovať:

- _názov_ (pole znakov)
- _autora_ (pole znakov)
- _rok vydania_ (celé číslo)

Program by mal načítať údaje zo súboru kde je definovaná kniha na jednom riadku a hodnoty štruktúry sú oddelené
bodkočiarkou.
Vstupný súbor môže byť v rovnakom priečinku ako program a môže mať napevno definovaný názov v zdrojovom kóde.
Program po úspešnom spracovaní súboru vypíše počet načítaných kníh.
Program následne umožní zadať používateľovi rok a vypíše knihy, ktoré boli vydané v zadanom roku.

### Príklady vstupov / výstupov programu

Vstupný súbor s knihami

```text
Programovanie v C;Kernighan & Ritchie;1988  
Moderné algoritmy;Jon Bentley;1990  
Umenie programovania;Donald Knuth;1968  
Štruktúra a interpretácia počítačových programov;Harold Abelson & Gerald Jay Sussman;1985  
Cvičenia z programovania;Brian Kernighan;1988  
Algoritmy v C++;Robert Sedgewick;1990  
Čistý kód;Robert C. Martin;2008  
Pragmatický programátor;Andrew Hunt & David Thomas;1999  
Python pre začiatočníkov;Guido van Rossum;2000  
Počítačová grafika;John F. Hughes & James D. Foley;1995  
```

Priebeh programu môže byť nasledovný:

```text
Počet kníh v databáze: 10
Zadajte rok vydania kníh: 1990

Názov: Moderné algoritmy
Autor: Jon Bentley
Rok vydania: 1990
---
Názov: Algoritmy v C++
Autor: Robert Sedgewick
Rok vydania: 1990
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100

// Štruktúra na reprezentáciu knihy
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

// Funkcia na načítanie údajov zo súboru
int loadBooks(const char *filename, Book books[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nepodarilo sa otvoriť súbor %s.\n", filename);
        return -1;
    }

    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (count >= MAX_BOOKS) {
            printf("Dosiahnutý maximálny počet kníh (%d).\n", MAX_BOOKS);
            break;
        }

        // Odstránenie nového riadku na konci
        line[strcspn(line, "\n")] = '\0';

        // Rozdelenie riadku podľa bodkočiarky
        char *token = strtok(line, ";");
        if (token != NULL) {
            strncpy(books[count].title, token, MAX_TITLE_LENGTH - 1);
            books[count].title[MAX_TITLE_LENGTH - 1] = '\0';
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            strncpy(books[count].author, token, MAX_AUTHOR_LENGTH - 1);
            books[count].author[MAX_AUTHOR_LENGTH - 1] = '\0';
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            books[count].year = atoi(token);
        }

        count++;
    }

    fclose(file);
    return count;
}

// Funkcia na vyhľadanie a výpis kníh podľa roku
void printBooksByYear(Book books[], int count, int year) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (books[i].year == year) {
            printf("Názov: %s\n", books[i].title);
            printf("Autor: %s\n", books[i].author);
            printf("Rok vydania: %d\n", books[i].year);
            printf("---\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Žiadne knihy z roku %d.\n", year);
    }
}

int main() {
    Book books[MAX_BOOKS];
    const char *filename = "books.txt";

    // Načítanie kníh zo súboru
    int bookCount = loadBooks(filename, books);
    if (bookCount < 0) {
        return 1; // Chyba pri načítaní
    }

    printf("Počet kníh v databáze: %d\n", bookCount);

    // Zadanie roku od používateľa
    int year;
    printf("Zadajte rok vydania kníh: ");
    scanf("%d", &year);

    // Výpis kníh podľa roku
    printBooksByYear(books, bookCount, year);

    return 0;
}
```

#### Vysvetlenie

1. Štruktúra Book:
    * Obsahuje názov knihy, autora a rok vydania.

2. Načítanie zo súboru:
    * Funkcia loadBooks otvára súbor books.txt a načítava knihy po riadkoch.
    * Každý riadok je rozdelený na časti (title, author, year) pomocou strtok.
    * Maximálny počet kníh je obmedzený na MAX_BOOKS.

3. Vyhľadanie podľa roku:
    * Funkcia printBooksByYear prechádza zoznam kníh a vypisuje knihy, ktoré zodpovedajú zadanému roku.

4. Hlavný program:
    * Načítava knihy zo súboru.
    * Vypisuje počet kníh v databáze.
    * Umožňuje používateľovi zadať rok a zobrazí zodpovedajúce knihy.

-->

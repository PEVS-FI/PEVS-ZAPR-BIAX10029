---
date: '2025-11-12T23:39:47+01:00'
title: '⛓️‍💥 Úloha 8.5'
weight: 5
---

Napíšte program, zdrojový kód, v jazyku C použitím štandardu C17, ktorý implementuje jednoduchý zreťazený zoznam pomocou
štruktúr.

Každý prvok zoznamu by mal obsahovať celé kladné číslo a pointer na ďalší prvok.
Program umožní používateľovi cez štandardný vstup zadať číslo prvku zoznamu. Po zadaní vstupu je nový prvok pridaný na
koniec zoznamu
a následne vypíše celý aktuálny zoznam a znova ponúkne používateľovi zadať ďalší prvok.
Program končí ak používateľ na vstupe zadá hodnotu _-1_.

> [!IMPORTANT]
> Nezabudnite uvoľniť pamäť alokovanú pre jednotlivé prvky zoznamu na konci programu!

### Príklady vstupov / výstupov programu

Priebeh programu môže vyzerať nasledovne:

```text
---
Zadajte hodnotu prvku: 1
Aktuálny zoznam: 1
---
Zadajte hodnotu prvku: 85
Aktuálny zoznam: 1, 85
---
Zadajte hodnotu prvku: 423
Aktuálny zoznam: 1, 85, 423
---
Zadajte hodnotu prvku: -1
```

---

Tu neskôr pribudne príkladné riešenie

<!--

```C
#include <stdio.h>
#include <stdlib.h>

// Štruktúra pre uzol zreťazeného zoznamu
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Funkcia na vytvorenie nového uzla
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Nepodarilo sa alokovať pamäť pre nový uzol.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Funkcia na pripojenie uzla na koniec zoznamu
void appendNode(Node** head, int value) {
    Node* newNode = createNode(value);

    if (*head == NULL) {
        // Ak je zoznam prázdny, nový uzol sa stane hlavou
        *head = newNode;
    } else {
        // Inak nájdeme posledný uzol a pripojíme nový uzol
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Funkcia na výpis zoznamu
void printList(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("Zoznam je prázdny.\n");
        return;
    }
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("\n");
}

// Funkcia na uvoľnenie pamäte zoznamu
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL; // Hlava zoznamu
    int input;

    while (1) {
        printf("\nZadajte hodnotu prvku (-1 pre ukončenie): ");
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        if (input < 0) {
            printf("Zadajte iba kladné čísla alebo -1 pre ukončenie.\n");
            continue;
        }

        // Pridanie nového prvku do zoznamu
        appendNode(&head, input);

        // Výpis aktuálneho zoznamu
        printf("Aktuálny zoznam: ");
        printList(head);
    }

    // Uvoľnenie pamäte
    freeList(head);
    printf("Pamäť bola uvoľnená. Program ukončený.\n");

    return 0;
}
```

#### Vysvetlenie

1. Štruktúra Node:
    * Reprezentuje uzol zoznamu, obsahuje hodnotu (value) a pointer na ďalší uzol (next).

2. Vytvorenie uzla:
    * Funkcia createNode alokuje pamäť pre nový uzol a inicializuje ho hodnotou.

3. Pripojenie uzla na koniec zoznamu:
    * Funkcia appendNode pridá nový uzol na koniec zoznamu.
    * Ak je zoznam prázdny, nový uzol sa stane hlavou.

4. Výpis zoznamu:
    * Funkcia printList prechádza zoznam a vypisuje hodnoty jednotlivých uzlov.

5. Uvoľnenie pamäte:
    * Funkcia freeList prejde všetky uzly zoznamu a uvoľní ich pamäť.

6. Hlavný program:
    * Používateľ opakovane zadáva hodnoty, ktoré sa pridávajú do zoznamu.
    * Po každom pridaní sa vypíše aktuálny stav zoznamu.
    * Program končí, keď používateľ zadá -1.

-->

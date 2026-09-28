/*
 * Alokácia dynamického poľa pomocou operátora new.
 */

#include <stdio.h>

int main() {
    int *dyn_pole, pocet;

    printf("zadaj pocet prvkov pola ");
    scanf("%d", &pocet);

    dyn_pole = new int[pocet];

    for (int i = 0; i < pocet; i++) {
        printf("zadaj dyn_pole[%d] ", i);
        scanf("%d", dyn_pole + i);
    }

    for (int i = 0; i < pocet; i++) {
        printf("dyn_pole[%d] = %d (teda %d) a je na adrese %p\n", i, dyn_pole[i], *(dyn_pole + i), dyn_pole + i);
    }
}
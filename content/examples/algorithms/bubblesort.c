/*
 * Ukážka triedenia poľa celých čísel algoritmom bubble sort.
 */

#include <stdio.h>

void sort(int *a, int pocet) {
    int sorted = 1;
    do {
        sorted = 1;
        for (int i = 0; i < pocet - 1; i++) {
            if (a[i] > a[i + 1]) {
                int x = a[i];
                a[i] = a[i + 1];
                a[i + 1] = x;
                sorted = 0;
            }
        }
    } while (sorted == 0);
}

int main() {
    int *dyn_pole, pocet;

    printf("zadaj pocet prvkov pola ");
    scanf("%d", &pocet);

    dyn_pole = new int[pocet];
    for (int i = 0; i < pocet; i++) {
        printf("zadaj dyn_pole[%d] ", i);
        scanf("%d", dyn_pole + i);
    }

    sort(dyn_pole, pocet);
    for (int i = 0; i < pocet; i++) {
        printf("dyn_pole[%d] = %d (teda %d) a je na adrese %p\n", i, dyn_pole[i], *(dyn_pole + i), dyn_pole + i);
    }
}
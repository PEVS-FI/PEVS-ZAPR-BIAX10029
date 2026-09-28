/*
 * Alokácia poľa funkciou calloc, ktorá pamäť vynuluje.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dyn_pole, pocet;

    printf("zadaj pocet prvkov pola ");
    scanf("%d", &pocet);

    printf("velkost int je %d\n", sizeof(int));

    if ((dyn_pole = (int *) calloc(pocet, sizeof(int))) != NULL) {
        for (int i = 0; i < pocet; i++) {
            printf("zadaj dyn_pole[%d] ", i);
            scanf("%d", &dyn_pole[i]);
        }

        for (int i = 0; i < pocet; i++) {
            printf("dyn_pole[%d] = %d (teda %d) a je na adrese %p\n", i, dyn_pole[i], *(dyn_pole + i), dyn_pole + i);
        }
        free((void *) dyn_pole);
    } else {
        printf("nemam dost pamati");
    }
}
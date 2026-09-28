/*
 * Vytvorenie dvojrozmerného poľa s rôznym počtom prvkov v riadkoch.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int **dyn_pole2D, *pocet_v_riadku, pocet_riadkov, i, j;

    printf("zadaj pocet riadkov pola ");
    scanf("%d", &pocet_riadkov);

    dyn_pole2D = (int **) malloc(pocet_riadkov * sizeof(int *));
    pocet_v_riadku = (int *) malloc(pocet_riadkov * sizeof(int));

    for (i = 0; i < pocet_riadkov; i++) {
        printf("zadaj pocet prvkov v riadku %d ", i);
        scanf("%d", pocet_v_riadku + i);
        dyn_pole2D[i] = (int *) malloc(*(pocet_v_riadku + i) * sizeof(int));
        for (j = 0; j < *(pocet_v_riadku + i); j++) {
            printf("zadaj prvok dyn_pole2D[%d][%d]: ", i, j);
            scanf("%d", (*(dyn_pole2D + i) + j));
        }
    }

    for (i = 0; i < pocet_riadkov; i++) {
        for (j = 0; j < pocet_v_riadku[i]; j++)
            printf("%d ", *(*(dyn_pole2D + i) + j));
        printf("\n");
    }
}
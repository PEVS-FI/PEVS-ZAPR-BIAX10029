/*
 * Ukážka viacúrovňového dynamického poľa s použitím príkazu goto.
 */

#include <stdio.h>

int main() {
    int i = 0, j = 0;
    int **pole;

    pole = new int *[3];
    int po[3];
    int po2[2];

    int *pole1 = new int[3];
    pole[1] = pole1;
    int max;
    int horna;
    printf("zadaj hornu hranica \n");
    scanf("%d", &horna);
    printf("zadaj max \n");
    scanf("%d", &max);

    for (j = 0; j < horna; j++) {
        for (i = 0; i <= j; printf("i", i++));
        if (i == max) goto a;
        printf("\n");
    }
a:
    printf("pokracovanie programu \n");
    return 0;
}
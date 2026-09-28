/*
 * Otvorenie súboru pre čítanie aj zápis v režime w+.
 */

#include <stdio.h>

int main() {
    int pocet, stav;
    FILE *f;
    f = fopen("konta.txt", "w+");

    fscanf(f, "%d\n", &pocet);
    printf("pocet = %d\n", pocet);

    /*for (int i = 0; i < pocet; i++)
	{
		fscanf(f, "%d\n", &stav);
		printf("Stav konta %d = %d\n", i, stav);
	}
	*/

    for (int i = 0; i < pocet; i++) {
        printf("zadaj stav konta s poradovym cislom %d: ", i);
        scanf("%d", &stav);
        fprintf(f, "%d\n", stav);
    }

    fclose(f);

    return 0;
}
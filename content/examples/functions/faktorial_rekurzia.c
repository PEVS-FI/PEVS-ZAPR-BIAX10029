/*
 * Výpočet kombinačného čísla s využitím rekurzívneho faktoriálu.
 */

#include <stdio.h>

int faktorial(int vstup) {
    if (vstup == 0)
        return 1;
    else
        return vstup * faktorial(vstup - 1);
}

int main() {
    int n, k;
    printf("program na vypocet kombinacneho cisla\n");
    printf("zadaj n: ");
    scanf("%d", &n);

    printf("zadaj k: ");
    scanf("%d", &k);

    if (k < 0 || n < k)
        printf("takyto fak nepocitam");
    else
        printf("%d nad %d = %d", n, k, faktorial(n) / (faktorial(n - k) * faktorial(k)));

    return 0;
}

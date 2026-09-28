/*
 * Rekurzívny výpočet faktoriálu čísla.
 */

#include <stdio.h>

int fak(int n) {
    if (n == 0) { return 1; } else { return n * fak(n - 1); }
}

int main() {
    int i, j;
    printf("zadaj i ");
    scanf("%d", &i);
    j = fak(i);
    printf("fak(%d) = %d", i, j);
}
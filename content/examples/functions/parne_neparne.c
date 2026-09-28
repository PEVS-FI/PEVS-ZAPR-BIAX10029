/*
 * Dve funkcie, ktoré sa vzájomne volajú (vzájomná rekurzia).
 */

#include <stdio.h>

int odd(int n);

int even(int n) {
    // predpoklad: n >= 0
    if (n == 0) return 1;
    else if (n == 1) return 0;
    else return odd(n - 1);
}

int odd(int n) {
    // predpoklad: n >= 0
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return even(n - 1);
}

int main() {
    int i, j;
    printf("zadaj i ");
    scanf("%d", &i);
    j = even(i);
    printf("even(%d) = %d", i, j);
}
/*
 * Správne použitie volania hodnotou a volania odkazom.
 */

#include <stdio.h>

void zvacsio(int *a, int n) {
    *a = *a + n;
}

int cbv(int a) {
    a = a + 1;
    return a;
}

int main() {
    int n;

    printf("zadaj n");
    scanf("%d", &n);

    n = cbv(n);
    printf("n = %d\n", n);
    zvacsio(&n, 5);
    printf("n = %d\n", n);
}
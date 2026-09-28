/*
 * Základná práca so smerníkom na premennú.
 */

#include <stdio.h>

int main() {
    int i, *p_i;

    printf("zadaj i: ");
    scanf("%d", &i);

    p_i = &i;

    printf("i = %d, *p_i = %d, &i = %p a p_i = %p, &p_i = %p", i, *p_i, &i, p_i, &p_i);

    return 0;
}
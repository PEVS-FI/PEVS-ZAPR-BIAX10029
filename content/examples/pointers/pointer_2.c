/*
 * Práca so smerníkom na smerník (viacúrovňový pointer).
 */

#include <stdio.h>

int main() {
    int i, j, *p_i, **ppi;

    printf("zadaj i: ");
    scanf("%d", &i);

    p_i = &i;

    printf("i = %d, *p_i = %d, &i = %p a p_i = %p\n", i, *p_i, &i, p_i);

    printf("zadaj j: ");
    scanf("%d", &j);

    p_i = &j;

    printf("i = %d, *p_i = %d, &i = %p a p_i = %p, j = %d, &j = %p\n", i, *p_i, &i, p_i, j, &j);


    ppi = &p_i;

    printf("&p_i = %p, ppi = %p, *ppi = %p, **ppi = %d\n", &p_i, ppi, *ppi, **ppi);


    p_i = &i;

    **ppi = i + j;

    printf("i = %d, j = %d", i, j);

    return 0;
}
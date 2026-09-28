/*
 * Práca so statickým jednorozmerným poľom pevnej veľkosti.
 */

#include <stdio.h>

int main() {
    int st_pole[5];

    for (int i = 0; i < 5; i++) {
        printf("zadaj st_pole[%d] ", i);
        scanf("%d", st_pole + i);
    }

    for (int i = 0; i < 5; i++) {
        printf("st_pole[%d] = %d (teda %d) a je na adrese %p (teda %p) \n", i, st_pole[i], *(st_pole + i), st_pole[i],
               &(*(st_pole + i)));
    }
}
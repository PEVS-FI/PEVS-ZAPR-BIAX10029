/*
 * Práca so statickým dvojrozmerným poľom pevnej veľkosti.
 */

#include <stdio.h>

int main() {
    int st_pole[3][4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("zadaj st_pole[%d][%d] ", i, j);
            scanf("%d", st_pole[i] + j);
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%p\n", st_pole[i]);
        for (int j = 0; j < 4; j++)
            printf("st_pole[%d][%d] = %d a je na adrese %p \n", i, j, st_pole[i][j], &st_pole[i][j]);
        printf("\n");
    }
}
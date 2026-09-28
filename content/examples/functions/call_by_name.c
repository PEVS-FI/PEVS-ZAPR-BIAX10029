/*
 * Predávanie argumentu funkcii pomocou smerníka (odkazu).
 */

#include <stdio.h>

void call_bname(int *poi_na_int) {
    *poi_na_int = *poi_na_int + 1;
}

int call_bvalue(int norm_int) {
    norm_int = norm_int - 1;
    return norm_int;
}

int main() {
    int i;
    printf("zadaj i: ");
    scanf("%d", &i);
    call_bname(&i);
    printf("i = %d\n", i);

    call_bvalue(i);
    printf("i = %d\n", i);

    i = call_bvalue(i);
    printf("i = %d\n", i);

    return 0;
}
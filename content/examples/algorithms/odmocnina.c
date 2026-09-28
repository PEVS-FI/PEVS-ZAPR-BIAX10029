/*
 * Približný výpočet druhej odmocniny čísla delením intervalu.
 */

#include <stdio.h>

int main() {
    double x;
    printf("Zadajte x \n");
    scanf("%lf", &x);
    double d = 0;
    double h = x + 1;
    double s = (d + h) / 2;
    double eps = 1.0e-10;
    int i = 1;
    while ((h - d) / s > eps) {
        if (s * s >= x)
            h = s;
        else
            d = s;
        s = (d + h) / 2;

        printf("i  = %d, s = %lf ", i++, s);
    }
    printf("Odmocnina %lf je %lf", x, s);
    return 0;
}
/*
 * Rekurzívny výpočet odmocniny delením intervalu.
 */

#include <stdio.h>

double delenie_intervalu(double d, double h, double cislo, double presnost) {
    double s = (d + h) / 2;

    if ((h - d) / s > presnost) {
        if (s * s >= cislo)
            h = s;
        else
            d = s;
        return delenie_intervalu(d, h, cislo, presnost);
    } else
        return s;
}

int main() {
    double x;
    printf("Zadajte x \n");
    scanf("%lf", &x);
    double d = 0;
    double h = x + 1;

    double eps = 1.0e-10;
    int i = 1;
    double s = delenie_intervalu(d, h, x, eps);

    printf("Odmocnina %lf je %lf", x, s);
    return 0;
}
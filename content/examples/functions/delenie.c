/*
 * Funkcia, ktorá ošetruje delenie nulou.
 */

#include <stdio.h>

double delenie(double citatel, double menovatel) {
    if (menovatel == 0) {
        printf("kedze menovatel bol 0, neviem, co mam vratit, tak zvraciam 0\n");
        return 0.0;
    } else
        return citatel / menovatel;
}

int main() {
    double citatel, menovatel;
    printf("zadaj citatel: ");
    scanf("%lf", &citatel);
    printf("zadaj menovatel: ");
    scanf("%lf", &menovatel);

    printf("vysledok je %lf", delenie(citatel, menovatel));
}
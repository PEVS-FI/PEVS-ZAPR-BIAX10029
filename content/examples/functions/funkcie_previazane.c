/*
 * Predbežné deklarácie funkcií vz. ich definície.
 */

#include <stdio.h>

// --- DEFINICIE ---

int druha(int i);

int i = 5;

// --- IMPLEMENTACIA ---

void prva() {
    int i = 3;
    i = druha(i);
}

int druha(int i) {
    printf("tlacenka %d", 2 * i);
    return 2 * i;
}

int main() {
    prva();
}
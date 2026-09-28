/*
 * Základná ukážka volania jednoduchých funkcií.
 */

#include <stdio.h>

void druha();

void prva();

int main() {
    prva();
    return 0;
}

void prva() {
    druha();
}

void druha() {
    printf("foo");
}
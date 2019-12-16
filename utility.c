#include <stdio.h>
#include <string.h>

#include "utility.h"
#include "fichas.h"

void imprimeLineaMatriz() {
    printf("+---+---+---+\n");
}

void imprimeSimboloDePieza(int val) {
    char simbolo;
    switch(val) {
    case BLANCAS:
        simbolo = 254;
        break;
    case NEGRAS:
        simbolo = 'o';
        break;
    case ESPACIO:
        simbolo = ' ';
        break;
    }
    printf(" %c |", simbolo);
}

int minimo(int v1, int v2) {
    return v1 < v2 ? v1 : v2;
}

int maximo(int v1, int v2) {
    return v1 > v2 ? v1 : v2;
}

int selectorEnRango(int selector, int lower, int upper) {
    return selector >= lower && selector <= upper;
}

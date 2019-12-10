#include <stdio.h>
#include <string.h>

#include "utility.h"

void imprimeLineaMatriz() {
    printf("+---+---+---+\n");
}

void imprimeSimboloDePieza(int val) {
    char simbolo;
    switch(val) {
    case 1:
        simbolo = 254;
        break;
    case -1:
        simbolo = 'o';
        break;
    case 0:
        simbolo = ' ';
        break;
    }
    printf(" %c |", simbolo);
}

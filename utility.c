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

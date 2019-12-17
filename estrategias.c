
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fichas.h"
#include "estrategias.h"
#include "utility.h"

tNodo *jugadaAdversario(tNodo *t) {
    int selectorPieza = 0, jugada = 0;

    do {
        do {
            printf("Elige la pieza a mover:[0 o 1]:");
            scanf("%d", &selectorPieza);
            fflush(stdin);
        } while (!piezaValida(t, selectorPieza));

        do {
            printf("Elige una jugada:\nARRIBA: 0\nDERECHA: 1\nABAJO: 2\nIZQUIERDA: 3\n->");
            scanf("%d", &jugada);
            fflush(stdin);
        } while (!selectorEnRango(jugada, 0, 3));
        jugada = jugada * 2 + selectorPieza;

        if (!esValida(t, jugada, BLANCAS)) {
            printf("Jugada no valida, elige de nuevo.\n");
        }

    } while (!esValida(t, jugada, BLANCAS));

    t = aplicaJugada(t, jugada, BLANCAS);
    return t;
}

int piezaValida(tNodo *actual, int selectorPieza) {
    return !piezaFuera(actual, BLANCAS, selectorPieza);
}

tNodo *minimax(tNodo *nodo) {
    int max = 10000, maxActual, jugada, mejorJugada;

    for (jugada = ARRIBA_0; jugada < NUM_MOVIMIENTOS; jugada++) {
        tNodo *intento = (tNodo *)malloc(sizeof(tNodo));
        if (esValida(nodo, jugada, NEGRAS)) {
            intento = aplicaJugada(nodo, jugada, NEGRAS);
            maxActual = valorMin(intento, 0);
            if (maxActual > max) {
                max = maxActual;
                mejorJugada = jugada;
            }
        }
        free(intento);
    }
    nodo = aplicaJugada(nodo, mejorJugada, NEGRAS);
    return nodo;
}

int valorMax(tNodo *nodo, int prof) {
    int valor_max, jugada, jugador = NEGRAS;
    if (terminal(nodo)) {
        valor_max = terminal(nodo);
    } else {
        if(prof == LIMITE_PROF) {
            valor_max = heuristica(nodo, NEGRAS);
        } else {
            valor_max = -100000;
            for (jugada = ARRIBA_0; jugada < NUM_MOVIMIENTOS; jugada++) {
                if (esValida(nodo, jugada, jugador)) {
                    valor_max = maximo(valor_max, valorMin(aplicaJugada(nodo, jugada, jugador), prof + 1));
                }
            }
        }
    }
    return valor_max;
}

int valorMin(tNodo *nodo, int prof) {
    int valor_min, jugada, jugador = BLANCAS;
    if (terminal(nodo)) {
        valor_min = terminal(nodo);
    } else {
        if(prof == LIMITE_PROF) {
            valor_min = heuristica(nodo, BLANCAS);
        } else {
            if(prof == LIMITE_PROF) {
                valor_min = heuristica(nodo, BLANCAS);
            } else {
                valor_min = 100000;
                for (jugada = ARRIBA_0; jugada < NUM_MOVIMIENTOS; jugada++) {
                    if (esValida(nodo, jugada, jugador)) {
                        valor_min = minimo(valor_min, valorMax(aplicaJugada(nodo, jugada, jugador), prof + 1));
                    }
                }
            }
        }
    }
    return valor_min;
}

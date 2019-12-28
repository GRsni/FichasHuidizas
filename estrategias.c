
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fichas.h"
#include "estrategias.h"
#include "utility.h"

extern int juegoFinalizado;
extern int ESTRATEGIA;
extern int PROF_MAXIMA;

tNodo *jugadaAdversario(tNodo *t) {
    int selectorPieza = 0, jugada = 0;
    if(!quedanMovimientosPosibles(t, BLANCAS)) {
        juegoFinalizado = 1;
    } else {
        do {
            do {
                printf("Elige la pieza a mover [Pieza 0 o Pieza 1]:");
                scanf("%d", &selectorPieza);
            } while (!selectorEnRango(selectorPieza, 0, 1) && !piezaValida(t, selectorPieza));

            do {
                printf("Elige una jugada:\nARRIBA: 0\nDERECHA: 1\nABAJO: 2\nIZQUIERDA: 3\n->");
                scanf("%d", &jugada);
            } while (!selectorEnRango(jugada, 0, 3));
            jugada = jugada * 2 + selectorPieza;

            if (!esValida(t, jugada, BLANCAS)) {
                printf("Jugada no valida, elige de nuevo.\n");
            }

        } while (!esValida(t, jugada, BLANCAS) && quedanMovimientosPosibles(t, BLANCAS));
        t = aplicaJugada(t, jugada, BLANCAS);

        juegoFinalizado = 0;
    }
    return t;
}

int piezaValida(tNodo *actual, int selectorPieza) {
    return !piezaFuera(actual, BLANCAS, selectorPieza);
}

tNodo *minimax(tNodo *nodo) {
    int max = -10000, maxActual, jugada, mejorJugada;
    if(!quedanMovimientosPosibles(nodo, NEGRAS)) {
        juegoFinalizado = 1;
    } else {
        for (jugada = ARRIBA_0; jugada < NUM_MOVIMIENTOS; jugada++) {
            tNodo *intento;
            if (esValida(nodo, jugada, NEGRAS)) {
                intento = aplicaJugada(nodo, jugada, NEGRAS);
                maxActual = valorMin(intento, 0);
                if (maxActual > max) {
                    max = maxActual;
                    mejorJugada = jugada;
                }
            }
        }
        nodo = aplicaJugada(nodo, mejorJugada, NEGRAS);
        juegoFinalizado = 0;
    }
    return nodo;
}

int valorMax(tNodo *nodo, int prof) {
    int valor_max, jugada, jugador = NEGRAS;
    if (terminal(nodo)) {
        valor_max = terminal(nodo);
    } else {
        if(prof == PROF_MAXIMA) {
            valor_max = heuristica(nodo, NEGRAS);
        } else {
            valor_max = -100000;
            for (jugada = ARRIBA_0; jugada < NUM_MOVIMIENTOS; jugada++) {
                if (esValida(nodo, jugada, jugador)) {
                    tNodo *prueba = aplicaJugada(nodo, jugada, NEGRAS);
                    valor_max = maximo(valor_max, valorMin(prueba, prof + 1));
                    free(prueba);
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
        if(prof == PROF_MAXIMA) {
            valor_min = heuristica(nodo, BLANCAS);
        } else {
            valor_min = 100000;
            for (jugada = ARRIBA_0; jugada < NUM_MOVIMIENTOS; jugada++) {
                if (esValida(nodo, jugada, jugador)) {
                    tNodo *prueba = aplicaJugada(nodo, jugada, jugador);
                    valor_min = minimo(valor_min, valorMax(prueba, prof + 1));
                    free(prueba);

                }
            }
        }
    }
    return valor_min;
}

tNodo *poda_ab(tNodo *actual) {
    int max_actual, jugada, mejorJugada, prof = 1, v, alfa = -100000, beta = 100000;
    tNodo *intento;
    if(!quedanMovimientosPosibles(actual, NEGRAS)) {
        juegoFinalizado = 1;
    } else {
        for(jugada = ARRIBA_0; jugada < NUM_MOVIMIENTOS; jugada++) {
            if(esValida(actual, jugada, NEGRAS)) {
                intento = aplicaJugada(actual, jugada, NEGRAS);
                v = valorMin_ab(intento, opuesto(NEGRAS), prof + 1, alfa, beta);
                if(v > alfa) {
                    alfa = v;
                    mejorJugada = jugada;
                }
                free(intento);
            }
        }

        if(esValida(actual, mejorJugada, NEGRAS)) {
            actual = aplicaJugada(actual, mejorJugada, NEGRAS);
        }
        juegoFinalizado = 0;
    }
    return actual;
}

int valorMin_ab(tNodo *nodo, int jugador, int prof, int alfa, int beta) {
    int vmin, jugada;
    tNodo *intento;
    if(terminal(nodo)) {
        vmin = terminal(nodo);
    } else if(prof == PROF_MAXIMA) {
        vmin = heuristica(nodo, jugador);
    } else {
        int jugada = ARRIBA_0;
        while(jugada < NUM_MOVIMIENTOS && alfa < beta) {
            if(esValida(nodo, jugada, jugador)) {
                intento = aplicaJugada(nodo, jugada, jugador);
                beta = minimo(beta, valorMax_ab(intento, opuesto(jugador), prof + 1, alfa, beta));
                free(intento);
            }
            jugada++;
        }
        vmin = beta;
    }
    return vmin;
}

int valorMax_ab(tNodo *nodo, int jugador, int prof, int alfa, int beta) {
    int vmax, jugada;
    tNodo *intento;
    if(terminal(nodo)) {
        vmax = terminal(nodo);
    } else if(prof == PROF_MAXIMA) {
        vmax = heuristica(nodo, jugador);
    } else {
        int jugada = ARRIBA_0;
        while(jugada < NUM_MOVIMIENTOS && alfa < beta) {
            if(esValida(nodo, jugada, jugador)) {
                intento = aplicaJugada(nodo, jugada, jugador);
                alfa = maximo(alfa, valorMin_ab(intento, opuesto(jugador), prof + 1, alfa, beta));
                free(intento);
            }
            jugada++;
        }
        vmax = alfa;
    }
    return vmax;
}



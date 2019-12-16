
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fichas.h"
#include "estrategias.h"
#include "utility.h"



tNodo *jugadaAdversario(tNodo *t) {
    int selectorPieza = 0, jugada = 0;

    do {
        printf("Elige la pieza a mover:[0 o 1]:");
        scanf("%d", &selectorPieza);
    } while(!piezaValida(t, selectorPieza));

    do{
        printf("Elige una jugada:\nARRIBA: 0\nDERECHA: 1\nABAJO: 2\nIZQUIERDA: 3\n->");
        scanf("%d", &jugada);
    }while(!selectorEnRango(jugada, 0, 3));

    while (!esValida(t, jugada, 0)) {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
    }
    t = aplicaJugada(t, -1, jugada);
    return t;
}

int piezaValida(tNodo *actual, int selectorPieza) {
    return !piezaFuera(actual, BLANCAS, selectorPieza);
}

tNodo* minimax(tNodo *nodo, int jugador) {
    int max = 10000, maxActual, jugada, mejorJugada;
    tNodo *intento = (tNodo *)malloc(sizeof(tNodo));

    for(jugada = 1; jugada < N; jugada++) {
        if(esValida(nodo, jugada, jugador)) {
            intento = aplicaJugada(nodo, jugada, jugador);
            maxActual = valorMin(intento);
            if(maxActual > max) {
                max = maxActual;
                mejorJugada = jugada;
            }
        }
    }
    nodo = aplicaJugada(nodo, mejorJugada, jugador);
    return nodo;
}

int valorMax(tNodo *nodo) {
    int valor_max, jugada, jugador = 1;
    if(terminal(nodo)) {
        valor_max = terminal(nodo);
    } else {
        valor_max = -100000;
        for(jugada = 1; jugada < N; jugada++) {
            if(esValida(nodo, jugada, jugador)) {
                valor_max = maximo(valor_max, valorMin(aplicaJugada(nodo, jugada, jugador)));
            }
        }
    }
    return valor_max;
}

int valorMin(tNodo *nodo) {
    int valor_min, jugada, jugador = -1;
    if(terminal(nodo)) {
        valor_min = terminal(nodo);
    } else {
        valor_min = 100000;
        for(jugada = 1; jugada < N; jugada++) {
            if(esValida(nodo, jugada, jugador)) {
                valor_min = minimo(valor_min, valorMax(aplicaJugada(nodo, jugador, jugada)));
            }
        }
    }
    return valor_min;
}


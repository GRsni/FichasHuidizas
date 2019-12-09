/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fichas.h"
#include "minimaxAlum.h"



tNodo *jugadaAdversario(tNodo *t) {
    int jugada = 0;
    printf("\nJugada ([0..8])?: ");
    scanf("%d", &jugada);
    while (!esValida(t, jugada)) {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
    }
    t = aplicaJugada(t, -1, jugada);
    return t;
}


tNodo* minimax(tNodo *nodo, int jugador) {
    int max = 10000, maxActual, jugada, mejorJugada;
    tNodo *intento = (tNodo *)malloc(sizeof(tNodo));

    for(jugada = 1; jugada < N; jugada++) {
        if(esValida(nodo, jugada)) {
            intento = aplicaJugada(nodo, jugador, jugada);
            maxActual = valorMin(intento);
            if(maxActual > max) {
                max = maxActual;
                mejorJugada = jugada;
            }
        }
    }
    nodo = aplicaJugada(nodo, jugador, mejorJugada);
    return nodo;
}

int valorMax(tNodo *nodo) {
    int valor_max, jugada, jugador = 1;
    if(terminal(nodo, jugador)) {
        valor_max = terminal(nodo, jugador);
    } else {
        valor_max = -100000;
        for(jugada = 1; jugada < N; jugada++) {
            if(esValida(nodo, jugada)) {
                valor_max = imax(valor_max, valorMin(aplicaJugada(nodo, jugador, jugada)));
            }
        }
    }
    return valor_max;
}

int valorMin(tNodo *nodo) {
    int valor_min, jugada, jugador = -1;
    if(terminal(nodo, jugador)) {
        valor_min = terminal(nodo, jugador);
    } else {
        valor_min = 100000;
        for(jugada = 1; jugada < N; jugada++) {
            if(esValida(nodo, jugada)) {
                valor_min = imin(valor_min, valorMax(aplicaJugada(nodo, jugador, jugada)));
            }
        }
    }
    return valor_min;
}


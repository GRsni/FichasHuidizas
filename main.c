/*******************************************/
/* 		    main.c                         */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include "fichas.h"
#include "utility.h"
#include "estrategias.h"

int juegoFinalizado = 0;

int testFunction() {
    tNodo *juego = estadoInicial();
    int i;
    printf("PROBANDO FUNCION aplicaOperador()\n");
    dispNodo(juego);
    for(i = ARRIBA_0; i < NUM_MOVIMIENTOS; i++) {
        dispOperador(i);
        if(esValida(juego, i, NEGRAS)) {
            tNodo *nuevo = aplicaJugada(juego, i, NEGRAS);
            dispNodo(nuevo);
        }
        if(esValida(juego, i, BLANCAS)) {
            tNodo *nuevo = aplicaJugada(juego, i, BLANCAS);
            dispNodo(nuevo);
        }
    }
    printf("\n\nPROBANDO esValida()\n");
    while(esValida(juego, ARRIBA_0, NEGRAS)) {
        dispNodo(juego);
        juego = aplicaJugada(juego, ARRIBA_0, NEGRAS);
    }
    dispNodo(juego);
    return 0;
}

int juego() {
    int jugador = BLANCAS; //0=BLANCAS, 1=NEGRAS
    int ganador = 0;

    tNodo *juego = estadoInicial();

    printf("El Agente Inteligente juega con las piezas negras \nEl Jugador Humano con las blancas \n");
    do {
        printf("Quieres empezar primero o segundo?[0-1]:\n->");
        scanf("%d", &jugador);
    } while(!selectorEnRango(jugador, 0, 1));
    dispNodo(juego);

    while(!juegoFinalizado) {
        if(jugador == BLANCAS) {
            juego = jugadaAdversario(juego);
        } else if(jugador == NEGRAS) {
            juego = minimax(juego);
        }
        if(!juegoFinalizado) {
            jugador = opuesto(jugador);
        }
        dispNodo(juego);
    }


    switch(jugador) {
    case NEGRAS:
        printf("\n HE GANADOOOO\n");
        break;
    case BLANCAS:
        printf("\n Increible pero has ganado tu :( \n\n");
        break;
    default:
        printf("\n algo ha salido mal en el juego ..\n");
    }
    return 0;
}

int main() {


//    return testFunction();
    return juego();

}

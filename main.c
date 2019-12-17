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

void testFunction() {
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
    while(esValida(juego, DERECHA_0, NEGRAS)) {
        dispNodo(juego);
        juego = aplicaJugada(juego, DERECHA_0, NEGRAS);
    }
    dispNodo(juego);
}

int juego(){
    int jugador = BLANCAS; //+1 o -1, Empieza el humano
    int ganador = 0;

    tNodo *juego = estadoInicial();

    printf("El Agente Inteligente juega con las piezas negras \nEl Jugador Humano con las blancas \n");
    dispNodo(juego);

    ganador = terminal(juego);

    while(ganador == 0) {
        if(jugador == BLANCAS) {
            juego = jugadaAdversario(juego);
        } else if(jugador == NEGRAS) {
            juego = minimax(juego);
        }
        jugador = opuesto(jugador);
        ganador = terminal(juego);
        dispNodo(juego);
    }


    switch(ganador) {
    case 100:
        printf("\n HE GANADOOOO\n");
        break;
    case 0:
        printf("\n EMPATE\n");
        break;
    case -100:
        printf("\n Increible pero has ganado tu :(( \n\n");
        break;
    default:
        printf("\n algo ha salido mal en el juego ..\n");
    }
    return 0;
}

int main() {


//    testFunction();
    return juego();

}

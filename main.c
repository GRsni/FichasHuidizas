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

int main() {
    int jugador = 1; //+1 o -1, Empieza el humano
    int primero, ganador;
    tNodo *juego = estadoInicial();

    printf("El Agente Inteligente juega con las piezas negras \nEl Jugador Humano con las blancas \n");

    ganador = terminal(juego);

    while(ganador != 0) {
        if(jugador == 1) {
            juego = jugadaAdversario(juego);
        } else if(jugador == -1) {
            juego = minimax(juego, NEGRAS);
        }
        ganador = terminal(juego);
    }


//    switch(ganador) {
//    case 100:
//        printf("\n HE GANADOOOO\n");
//        break;
//    case 0:
//        printf("\n EMPATE\n");
//        break;
//    case -100:
//        printf("\n Increible pero has ganado tu :(( \n\n");
//        break;
//    default:
//        printf("\n algo ha salido mal en el juego ..\n");
//    }
    return 0;
}

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
//#include "minimaxAlum.h"

int main() {
//    int jugador;  //+1 o -1
    int primero, ganador;
    tNodo *juego = estadoInicial();
    dispNodo(juego);

    for(int i = ARRIBA; i < NUM_MOVIMIENTOS; i++) {
        dispOperador(i);
        printf("Valido para pieza 1 negra: %d\n", esValida(juego, i, NEGRAS, 0));
        printf("Valido para pieza 2 negra: %d\n", esValida(juego, i, NEGRAS, 1));
        printf("Valido para pieza 1 blanca: %d\n", esValida(juego, i, BLANCAS, 0));
        printf("Valido para pieza 2 blanca: %d\n", esValida(juego, i, BLANCAS, 1));
    }
//
//    printf("El Agente Inteligente juega con X \nEl Jugador Humano con O \n Elige el turno 1:Primero o 2:Segundo ");
//    scanf("%d", &primero);
//    printf("\n");
//    if (primero == 1)
//        jugador = -1; // Turno de Min
//    else
//        jugador = 1; // Turno de Max
//
////    ganador = terminal(juego, jugador);
//
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

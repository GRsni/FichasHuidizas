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
#include "menu.h"

int juegoFinalizado = 0;
int ESTRATEGIA = MINIMAX;
int PROF_MAXIMA = 5;

int funcionTest() {
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

int main() {


//    return funcionTest();
    return menu();

}

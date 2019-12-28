#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"
#include "fichas.h"
#include "estrategias.h"
#include "utility.h"

extern int ESTRATEGIA;
extern int PROF_MAXIMA;
extern int juegoFinalizado;

int elegirPrimerJugador() {
    int selector;
    printf("El Agente Inteligente juega con las piezas negras \nEl Jugador Humano con las blancas \n");
    do {
        printf("Quieres empezar primero[0] o segundo[1]?:\n->");
        scanf("%d", &selector);
    } while(!selectorEnRango(selector, BLANCAS, NEGRAS));
    return selector;
}

void selectorOpcionesMenu(int selector) {
    switch(selector) {
    case 0:
        juego();
        break;
    case 1:
        elegirEstrategiaDeJuego();
        break;
    case 2:
        elegirProfundidadMaxima();
        break;
    case 3:
        printf("\nSaliendo del programa.\n\n");
        break;
    }
}

int juego() {
    int jugador = elegirPrimerJugador(); //0=BLANCAS, 1=NEGRAS
    tNodo *juego = estadoInicial();
    juegoFinalizado = 0;
    int valorEstado = 0;
    dispNodo(juego);

    while(!juegoFinalizado && valorEstado == 0) {
        if(jugador == BLANCAS) {
            juego = jugadaAdversario(juego);
        } else if(jugador == NEGRAS) {
            if(ESTRATEGIA == MINIMAX) {
                juego = minimax(juego);
            } else if(ESTRATEGIA == PODA) {
                juego = poda_ab(juego);
            }
        }
        valorEstado = terminal(juego);
        jugador = opuesto(jugador);
        dispNodo(juego);
    }

    if(valorEstado == 10000) {
        jugador = BLANCAS;
    } else if(valorEstado == -10000) {
        jugador = NEGRAS;
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

void elegirEstrategiaDeJuego() {
    do {
        printf("Elige la estrategia de busqueda:\nMinimax: 0 | Poda Alfa/Beta: 1\n->");
        scanf("%d", &ESTRATEGIA);
    } while(!selectorEnRango(ESTRATEGIA, 0, 1));
}

void elegirProfundidadMaxima() {
    do {
        printf("Elige la profundidad maxima de expansion (entre 1 y 12)\n->");
        scanf("%d", &PROF_MAXIMA);
    } while(!selectorEnRango(PROF_MAXIMA, 1, 12));
}

int menu() {
    int selector = 1;

    printf("        FICHAS HUIDIZAS      \n");
    elegirEstrategiaDeJuego();
    while(selector != 3) {
        do {
            printf("\n\n------Menu principal------\n-Jugar contra el ordenador: 0\nElegir otra estrategia: 1\nElegir la profuncidad maxima:2\nSalir del programa: 3\n->");
            scanf("%d", &selector);
        } while(!selectorEnRango(selector, 0, 3));
        selectorOpcionesMenu(selector);
    }
    return 0;
}

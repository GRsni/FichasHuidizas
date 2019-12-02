#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fichas.h"




tNodo *estadoInicial() {
    return crearNodo(tablero_inicial);
}

tNodo *crearNodo(int celdas[N]) {
    tNodo *Nodo = (tNodo *) malloc(sizeof(tNodo));
    int i, c;
    Nodo->vacias = 0;
    for (i = 0; i < N; i++) {
        c = celdas[i];
        Nodo->celdas[i] = c;
        if (c == 0)
            Nodo->vacias = Nodo->vacias + 1;
    }
    return Nodo;
}


tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada) {
    tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
    memcpy(nuevo, actual, sizeof(tNodo));
    nuevo->celdas[jugada] = jugador;
    nuevo->vacias--;  // marca la posición que indica pone la marca del jugador
    return nuevo;
}
int esValida(tNodo *actual, int jugada) {
    return (jugada >= 0 && jugada < 9 && actual->celdas[jugada] == 0) ; // si está vacía la posición, la jugada es válido
}
int opuesto( int jugador) {
    return (jugador * -1);//Jugador 1 y Jugador -1
}

int lleno(tNodo *tablero) {
    return (tablero->vacias != 0);
}

int terminal(tNodo *Nodo, int jugador) {

    int i = 0, res = 0;
    while (res == 0 && i < 8) {
        if(Nodo->celdas[opciones[i][0]] != 0 &&
                Nodo->celdas[opciones[i][0]] == Nodo->celdas[opciones[i][1]] &&
                Nodo->celdas[opciones[i][0]] == Nodo->celdas[opciones[i][2]])
            res = Nodo->celdas[opciones[i][2]]; //indica que jugador ocupa las casillas ganadoras
        i++;
    }
    return res * 100 * jugador;
}

int imin(int v1, int v2) {
    return (v1 > v2) ? v2 : v1;
}

int imax(int v1, int v2) {
    return (v1 > v2) ? v1 : v2;
}

int heuristica(tNodo *nodo, int jugador, int pos) {
    int mejorJugada=0, i;
    //unsigned opciones[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    switch(pos) {
    case 1:
        for(i=0; i<=6; i+=3){
            int comprobar[3]=opciones[i];
            printf("comprobar[%d]: %d\n", i, comprobar[i]);
        }

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;

    }

}

////////////////////////////////////////
//  VISUALIZACIÓN DE NodoS
////////////////////////////////////////

char marca(int i) {
    switch(i) {
    case 1:
        return 'X';
    case 0:
        return ' ';
    case -1:
        return 'O';
    default:
        return ' ';
    }
}

void dispNodo(tNodo *b) {
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", marca(b->celdas[0]), marca(b->celdas[1]), marca(b->celdas[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", marca(b->celdas[3]), marca(b->celdas[4]), marca(b->celdas[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", marca(b->celdas[6]), marca(b->celdas[7]), marca(b->celdas[8]));
    printf("---+---+---\n\n");
}







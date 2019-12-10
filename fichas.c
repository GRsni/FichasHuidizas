#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fichas.h"
#include "utility.h"

tNodo *estadoInicial() {
    return crearNodo(tablero_inicial);
}

tNodo *crearNodo(int celdas[N][N]) {
    int i, j;
    tNodo* nodo = (tNodo *)malloc(sizeof(tNodo));
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            nodo->celdas[i][j] = celdas[i][j];
        }
    }
    inicializaPiezasBlancas(nodo);
    inicializaPiezasNegras(nodo);
    return nodo;
}

void inicializaPiezasBlancas(tNodo *actual) {
    actual->piezas[0][0][0] = 1;
    actual->piezas[0][0][1] = 0;
    actual->piezas[0][1][0] = 2;
    actual->piezas[0][1][1] = 2;
}

void inicializaPiezasNegras(tNodo *actual) {
    actual->piezas[1][0][0] = 0;
    actual->piezas[1][0][1] = 0;
    actual->piezas[1][1][0] = 1;
    actual->piezas[1][1][1] = 0;
}

tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada, int selectorFicha) {

}

int esValida(tNodo *actual, int jugada, int jugador, int selectorFicha) {
    int valido = 1;

    switch(jugada) {
    case ARRIBA:
        valido = compruebaArriba(actual, jugador, selectorFicha);
        break;
    case DERECHA:
        valido = compruebaDerecha(actual, jugador, selectorFicha);
        break;
    case ABAJO:
        valido = compruebaAbajo(actual, jugador, selectorFicha);
        break;
    case IZQUIERDA:
        valido = compruebaIzquierda(actual, jugador, selectorFicha);
        break;
    }
    return valido;
}

int compruebaArriba(tNodo *actual, int jugador, int selectorFicha) {
    int row = actual->piezas[jugador][selectorFicha][0];
    int col = actual->piezas[jugador][selectorFicha][1];
    int valido = 1;
    if(row == 0) {
        if(jugador == NEGRAS) {
            valido = 0;
        }
    } else {
        if(actual->celdas[row - 1][col] != 1) {
            valido = 0;
        }
    }
    return valido;
}

int compruebaDerecha(tNodo *actual, int jugador, int selectorFicha) {
    int row = actual->piezas[jugador][selectorFicha][0];
    int col = actual->piezas[jugador][selectorFicha][1];
    int valido = 1;
    if(jugador == NEGRAS) {
        valido = 0;
    } else if(row != 0) {
        if(col - 1 < 0 || actual->celdas[row][col - 1] != 0) {
            valido = 0;
        }
    } else {
        if(actual->celdas[row][col - 1] != 0) {
            valido = 0;
        }
    }
    return valido;
}

int compruebaAbajo(tNodo *actual, int jugador, int selectorFicha) {
    int row = actual->piezas[jugador][selectorFicha][0];
    int col = actual->piezas[jugador][selectorFicha][1];
    int valido = 1;
    if(jugador == NEGRAS) {
        valido = 0;
    } else if(row != 0) {
        if(col - 1 < 0 || actual->celdas[row][col - 1] != 0) {
            valido = 0;
        }
    } else {
        if(actual->celdas[row][col - 1] != 0) {
            valido = 0;
        }
    }
    return valido;
}

int compruebaIzquierda(tNodo *actual, int jugador, int selectorFicha) {
    int row = actual->piezas[jugador][selectorFicha][0];
    int col = actual->piezas[jugador][selectorFicha][1];
    int valido = 1;
    if(jugador == NEGRAS) {
        valido = 0;
    } else if(row != 0) {
        if(col - 1 < 0 || actual->celdas[row][col - 1] != 0) {
            valido = 0;
        }
    } else {
        if(actual->celdas[row][col - 1] != 0) {
            valido = 0;
        }
    }
    return valido;
}

int piezaFuera(tNodo *actual, int jugador, int pieza) {
    return actual->piezas[jugador][pieza][0] == -1 && actual->piezas[jugador][pieza][1] == -1;
}

int terminal(tNodo *actual, int jugador) {
    return piezaFuera(actual, jugador, 0) && piezaFuera(actual, jugador, 1);
}

void dispNodo(tNodo *actual) {
    printf("IMPRIMIENDO ESTADO ACTUAL:\n");
    int i = 0, j = 0;
    do {
        j = 0;
        imprimeLineaMatriz();
        printf("|");
        do {
            imprimeSimboloDePieza(actual->celdas[i][j]);
            j++;
        } while(j < 3);
        printf("\n");
        i++;
    } while(i < 3);
    imprimeLineaMatriz();
    dispPiezas(actual);
}

void dispPiezas(tNodo *actual) {
    printf("Piezas blancas:\n[%d, %d] y [%d, %d]\n", actual->piezas[0][0][0],
           actual->piezas[0][0][1],
           actual->piezas[0][1][0],
           actual->piezas[0][1][1]);
    printf("Piezas negras:\n[%d, %d] y [%d, %d]\n", actual->piezas[1][0][0],
           actual->piezas[1][0][1],
           actual->piezas[1][1][0],
           actual->piezas[1][1][1]);
}

void dispOperador(int jugada) {
    printf("REALIZANDO JUGADA:  ");
    switch(jugada) {
    case ARRIBA:
        printf("ARRIBA\n");
        break;
    case DERECHA:
        printf("DERECHA\n");
        break;
    case ABAJO:
        printf("ABAJO\n");
        break;
    case IZQUIERDA:
        printf("IZQUIERDA\n");
        break;
    }
}

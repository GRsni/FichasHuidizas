#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fichas.h"
#include "utility.h"

tNodo *estadoInicial() {
    return crearNodo(tablero_inicial);
}

tNodo *crearNodo(int celdas[N][N]) {
    int i, j, numN = 0, numB = 0;
    tNodo* nodo = (tNodo *)malloc(sizeof(tNodo));
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            nodo->celdas[i][j] = celdas[i][j];
            if(celdas[i][j] == NEGRAS) {
                inicializaPiezaCualquiera(nodo, NEGRAS, numN, i, j);
                numN++;
            } else if(celdas[i][j] == BLANCAS) {
                inicializaPiezaCualquiera(nodo, BLANCAS, numB, i, j);
                numB++;
            }
        }
    }
    return nodo;
}

void inicializaPiezasBlancas(tNodo *actual) {
    actual->piezas[0][0][0] = 1;
    actual->piezas[0][0][1] = 2;
    actual->piezas[0][1][0] = 2;
    actual->piezas[0][1][1] = 2;
}

void inicializaPiezasNegras(tNodo *actual) {
    actual->piezas[1][0][0] = 0;
    actual->piezas[1][0][1] = 0;
    actual->piezas[1][1][0] = 1;
    actual->piezas[1][1][1] = 0;
}

void inicializaPiezaCualquiera(tNodo *actual, int jugador, int index, int row, int col) {
    actual->piezas[jugador][index][0] = row;
    actual->piezas[jugador][index][1] = col;
}

tNodo *aplicaJugada(tNodo *actual, int jugada, int jugador) {
    tNodo *nuevo = (tNodo *)malloc(sizeof(tNodo));
    if(nuevo == NULL) {
        return actual;
    }
    memcpy(nuevo, actual, sizeof(tNodo));

    int selectorPieza = 0;

    //Jugadas pares se refieren a la pieza con indice 0, jugadas impares controlan la pieza con indice 1
    if(jugada % 2 == 0) {
        selectorPieza = 0;
    } else {
        selectorPieza = 1;
    }

    int row = nuevo->piezas[jugador][selectorPieza][0];
    int col = nuevo->piezas[jugador][selectorPieza][1];

    int nextRow, nextCol;

    switch(jugada) {
    case ARRIBA_0:
    case ARRIBA_1:
        nextRow = row - 1;
        nextCol = col;
        break;
    case DERECHA_0:
    case DERECHA_1:
        nextRow = row;
        nextCol = col + 1;
        break;
    case ABAJO_0:
    case ABAJO_1:
        nextRow = row + 1;
        nextCol = col;
        break;
    case IZQUIERDA_0:
    case IZQUIERDA_1:
        nextRow = row;
        nextCol = col - 1;
        break;
    }

    nuevo->celdas[row][col] = ESPACIO;
    if(nextCol >= 0 && nextCol < N && nextRow >= 0 && nextRow < N) {
        nuevo->celdas[nextRow][nextCol] = jugador;
    }

    nuevo->piezas[jugador][selectorPieza][0] = nextRow;
    nuevo->piezas[jugador][selectorPieza][1] = nextCol;


    return nuevo;
}

int esValida(tNodo *actual, int jugada, int jugador) {
    int valido = 1;
    switch(jugada) {
    case ARRIBA_0:
        valido = compruebaArriba(actual, jugador, 0);
        break;
    case DERECHA_0:
        valido = compruebaDerecha(actual, jugador, 0);
        break;
    case ABAJO_0:
        valido = compruebaAbajo(actual, jugador, 0);
        break;
    case IZQUIERDA_0:
        valido = compruebaIzquierda(actual, jugador, 0);
        break;
    case ARRIBA_1:
        valido = compruebaArriba(actual, jugador, 1);
        break;
    case DERECHA_1:
        valido = compruebaDerecha(actual, jugador, 1);
        break;
    case ABAJO_1:
        valido = compruebaAbajo(actual, jugador, 1);
        break;
    case IZQUIERDA_1:
        valido = compruebaIzquierda(actual, jugador, 1);
        break;
    }
    return valido;
}

int compruebaArriba(tNodo *actual, int jugador, int selectorFicha) {
    int row = actual->piezas[jugador][selectorFicha][0];
    int col = actual->piezas[jugador][selectorFicha][1];
    int valido = 0;
    if(!piezaFuera(actual, jugador, selectorFicha)) {
        if(row == 0) {
            if(jugador == BLANCAS) {
                valido = 1;
            }
        } else if(row > 0) {
            if(actual->celdas[row - 1][col] == ESPACIO) {
                valido = 1;
            }
        }
    }
    return valido;
}

int compruebaDerecha(tNodo *actual, int jugador, int selectorFicha) {
    int row = actual->piezas[jugador][selectorFicha][0];
    int col = actual->piezas[jugador][selectorFicha][1];
    int valido = 0;
    if(!piezaFuera(actual, jugador, selectorFicha)) {
        if(col == N - 1) {
            if(jugador == NEGRAS) {
                valido = 1;
            }
        } else if(col < N - 1) {
            if(actual->celdas[row][col + 1] == ESPACIO) {
                valido = 1;
            }
        }
    }
    return valido;
}

int compruebaAbajo(tNodo *actual, int jugador, int selectorFicha) {
    int row = actual->piezas[jugador][selectorFicha][0];
    int col = actual->piezas[jugador][selectorFicha][1];
    int valido = 0;

    if(!piezaFuera(actual, jugador, selectorFicha)) {
        if(jugador == NEGRAS) {
            if(row < N - 1 && actual->celdas[row + 1][col] == ESPACIO) {
                valido = 1;
            }
        }
    }
    return valido;
}

int compruebaIzquierda(tNodo *actual, int jugador, int selectorFicha) {
    int row = actual->piezas[jugador][selectorFicha][0];
    int col = actual->piezas[jugador][selectorFicha][1];
    int valido = 0;
    if(!piezaFuera(actual, jugador, selectorFicha)) {
        if(jugador == BLANCAS) {
            if(col > 0 && actual->celdas[row][col - 1] == ESPACIO) {
                valido = 1;
            }
        }
    }
    return valido;
}

int piezaFuera(tNodo *actual, int jugador, int pieza) {
    int row = actual->piezas[jugador][pieza][0];
    int col = actual->piezas[jugador][pieza][1];
    return (col > N - 1 || col < 0 || row > N - 1 || row < 0);
}

int terminal(tNodo *actual) {
    int res = 0;
    if(piezaFuera(actual, BLANCAS, 0) && piezaFuera(actual, BLANCAS, 1)) {
        res = 10000;
    } else if(piezaFuera(actual, NEGRAS, 0) && piezaFuera(actual, NEGRAS, 1)) {
        res = -10000;
    }
    return res;
}

int heuristica(tNodo * nodo, int jugador) {
    int row0N = nodo->piezas[NEGRAS][0][0];
    int col0N = nodo->piezas[NEGRAS][0][1];
    int row1N = nodo->piezas[NEGRAS][1][0];
    int col1N = nodo->piezas[NEGRAS][1][1];

    int row0B = nodo->piezas[BLANCAS][0][0];
    int col0B = nodo->piezas[BLANCAS][0][1];
    int row1B = nodo->piezas[BLANCAS][1][0];
    int col1B = nodo->piezas[BLANCAS][1][1];
    int valorPieza0N = 0, valorPieza1N = 0, valorPieza0B = 0, valorPieza1B = 0;

    if(col0N == N - 1) {
        valorPieza0N = valores_heuristica[row0N][col0N + 1];
    } else {
        valorPieza0N = valores_heuristica[row0N][col0N];
    }
    if(col1N == N - 1) {
        valorPieza1N = valores_heuristica[row1N][col1N + 1];
    } else {
        valorPieza1N = valores_heuristica[row1N][col1N];
    }

    if(row0B == 0) {
        valorPieza0B = valores_heuristica[row0B][col0B];
    } else {
        valorPieza0B = valores_heuristica[row0B+ 1][col0B];
    }
    if(row1B == 0) {
        valorPieza1B = valores_heuristica[row1B][col1B];
    } else {
        valorPieza1B = valores_heuristica[row1B + 1][col1B];
    }

    int valorFinal=0;
    if(jugador==NEGRAS){
        valorFinal=valorPieza1N+valorPieza1N-valorPieza0B-valorPieza1B;
    }else if(jugador==BLANCAS){
     valorFinal=valorPieza1B+valorPieza1B-valorPieza0N-valorPieza1N;
    }

    return valorFinal;
}

int distanciaNegras(tNodo *actual) {
    int col1 = actual->piezas[NEGRAS][0][1];
    int col2 = actual->piezas[NEGRAS][1][1];
    return N - col1 + N - col2;
}

int distanciaBlancas(tNodo *actual) {
    int row1 = actual->piezas[BLANCAS][0][0];
    int row2 = actual->piezas[BLANCAS][1][0];
    return row1 + row2;
}

int quedanMovimientosPosibles(tNodo *actual, int jugador) {
    int jugada = ARRIBA_0;
    int valido = 0;
    while(jugada < NUM_MOVIMIENTOS && !valido) {
        if(esValida(actual, jugada, jugador)) {
            valido = 1;
        }
        jugada++;
    }
    return valido;
}


void dispNodo(tNodo *actual) {
    printf("Estado ACTUAL:\n");
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
    printf("\n");
}

void dispPiezas(tNodo *actual) {
    printf("Piezas blancas (%c):\n[%d, %d] y [%d, %d]\n", 254,
           actual->piezas[0][0][0],
           actual->piezas[0][0][1],
           actual->piezas[0][1][0],
           actual->piezas[0][1][1]);
    printf("Piezas negras (o):\n[%d, %d] y [%d, %d]\n",
           actual->piezas[1][0][0],
           actual->piezas[1][0][1],
           actual->piezas[1][1][0],
           actual->piezas[1][1][1]);
}

void dispOperador(int jugada) {
    printf("Realizando jugada:  ");
    switch(jugada) {
    case ARRIBA_0:
        printf("ARRIBA  pieza 0\n");
        break;
    case ARRIBA_1:
        printf("ARRIBA  pieza 1\n");
        break;
    case DERECHA_0:
        printf("DERECHA pieza 0\n");
        break;
    case DERECHA_1:
        printf("DERECHA pieza 1\n");
        break;
    case ABAJO_0:
        printf("ABAJO pieza 0\n");
        break;
    case ABAJO_1:
        printf("ABAJO pieza 1\n");
        break;
    case IZQUIERDA_0:
        printf("IZQUIERDA pieza 0\n");
        break;
    case IZQUIERDA_1:
        printf("IZQUIERDA pieza 1\n");
        break;
    }
}

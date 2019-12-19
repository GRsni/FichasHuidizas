
#ifndef _FICHAS_H_
#define _FICHAS_H_

#define N 3
#define BLANCAS 0
#define NEGRAS 1
#define ESPACIO -1

#define ARRIBA_0 0
#define DERECHA_0 2
#define ABAJO_0 4
#define IZQUIERDA_0 6
#define ARRIBA_1 1
#define DERECHA_1 3
#define ABAJO_1 5
#define IZQUIERDA_1 7
#define NUM_MOVIMIENTOS 8

#define LIMITE_PROF 10

typedef struct tNodo {
    int celdas[N][N];
    int piezas[2][2][2]; //piezas[0]=blancas, piezas[1]=negras
} tNodo;

static int tablero_inicial[N][N] = {
    {1, -1, -1},
    {1, -1, -1},
    {-1, 0, 0}
};

static int valores_heuristica[N][N] = {
    {2, 3, 4},
    {1, 2, 3},
    {0, 1, 3}
};



tNodo *estadoInicial();
tNodo *crearNodo(int celdas[N][N]);

void inicializaPiezasBlancas(tNodo * actual);
void inicializaPiezasNegras(tNodo * actual);
void inicializaPiezaCualquiera(tNodo * actual, int jugador, int index, int col, int row);

/*tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
 actual: es el tablero actual,
 jugador: la marca del jugador que tiene el turno
 jugada: indica en qué posición del tablero pondrá la marca
 devuelve: el nuevo Nodo tras aplicar la jugada */
tNodo * aplicaJugada(tNodo * actual, int jugada, int jugador);

/*Devuelve 1 si la jugada es valida, 0 en otro caso*/
int esValida(tNodo * actual, int jugada, int jugador);

/*Devuelve 1 si es valido mover hacia arriba*/
int compruebaArriba(tNodo * actual, int jugador, int selectorFicha);

/*Devuelve 1 si es valido mover hacia la derecha*/
int compruebaDerecha(tNodo * actual, int jugador, int selectorFicha);

/*Devuelve 1 si es valido mover hacia abajo*/
int compruebaAbajo(tNodo * actual, int jugador, int selectorFicha);

/*Devuelve 1 si es valido mover hacia la izquierda*/
int compruebaIzquierda(tNodo * actual, int jugador, int selectorFicha);

/* int terminal(tNodo *actual, int jugador)
 funcion que determina si un nodo es terminal, ha ganado MAX o MIN
 actual: tablero actual
 jugador: 1 si es Max, 0 si es Min
 devuelve:  si ha gando MAX 100, si ha ganado MIN -100, o 0 en otro caso */
int terminal(tNodo * actual);
int piezaFuera(tNodo *actual, int jugador, int pieza);

int heuristica(tNodo * nodo, int jugador);
int distanciaNegras(tNodo *actual);
int distanciaBlancas(tNodo *actual);

void dispNodo(tNodo * s);
void dispPiezas(tNodo * actual);
void dispOperador(int jugada);

/*Devuelve 1 si aun quedan movimientos posibles para el jugador, 0 en otro caso*/
int quedanMovimientosPosibles(tNodo *actual, int jugador);

#endif // _FICHAS_H_



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

#ifndef _ESTADOS_
#define _ESTADOS_

typedef struct tNodo {
    int celdas[N][N];
    int piezas[2][2][2]; //piezas[0]=blancas, piezas[1]=negras
} tNodo;

static int tablero_inicial[N][N] = {
    {BLANCAS, ESPACIO, NEGRAS},
    {ESPACIO, NEGRAS, ESPACIO},
    {BLANCAS, ESPACIO, ESPACIO}
};

#endif // _ESTADOS_

tNodo *estadoInicial();
tNodo *crearNodo(int celdas[N][N]);

void inicializaPiezasBlancas(tNodo * actual);
void inicializaPiezasNegras(tNodo * actual);
void inicializaPiezaCualquiera(tNodo * actual, int jugador, int index, int col, int row);

/*tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
 actual: es el tablero actual,
 jugador: la marca del jugador que tiene el turno
 jugada: indica en qu� posici�n del tablero pondr� la marca
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
int terminal(tNodo * actual, int jugador);

void dispNodo(tNodo * s);
void dispPiezas(tNodo * actual);
void dispOperador(int jugada);
int minimo(int v1, int v2);

int minimo(int v1, int v2);

int heuristica(tNodo * nodo, int jugador, int pos);


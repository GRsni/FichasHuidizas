
#define N 3
#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3
#define NUM_MOVIMIENTOS 4

typedef struct tNodo {
    int celdas[N][N];
    int piezas[2][2][2]; //piezas[0]=blancas, piezas[1]=negras
} tNodo;

//Ficha blanca: 1, ficha negra -1
static int tablero_inicial[N][N] = {
    {-1, 0, 0},
    {-1, 0, 0},
    {0, 1, 1}
};



tNodo *crearNodo(int celdas[N][N]);

void inicializaPiezasBlancas(tNodo *actual);
void inicializaPiezasNegras(tNodo *actual);

/*tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
 actual: es el tablero actual,
 jugador: la marca del jugador que tiene el turno
 jugada: indica en qué posición del tablero pondrá la marca
 devuelve: el nuevo Nodo tras aplicar la jugada */
tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada, int selectorFicha);
int esValida(tNodo *actual, int jugada, int selectorFicha);

/* int terminal(tNodo *actual, int jugador)
 funcion que determina si un nodo es terminal, ha ganado MAX o MIN
 actual: tablero actual
 jugador: 1 si es Max -1 si es Min
 devuelve:  si ha gando MAX 100, si ha ganado MIN -100, o 0 en otro caso */
int terminal(tNodo *actual, int jugador);

void dispNodo(tNodo *s);
void dispPiezas(tNodo *actual);

int imin(int v1, int v2);

int imax(int v1, int v2);

int heuristica(tNodo *nodo, int jugador, int pos);


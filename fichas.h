
#define N 3

typedef struct tNodo {
    int celdas[N][N];
} tNodo;

//Ficha blanca: 1, ficha negra -1
static int tablero_inicial[N][N] = {
    {-1, 0, 0},
    {-1, 0, 0},
    {0, 1, 1}
};



tNodo *crearNodo(int celdas[N][N]);
tNodo *NodoInicial();


/*tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
 actual: es el tablero actual,
 jugador: la marca del jugador que tiene el turno
 jugada: indica en qué posición del tablero pondrá la marca
 devuelve: el nuevo Nodo tras aplicar la jugada */
tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada);
int esValida(tNodo *actual, int jugada);

//int terminal(tNodo *actual, int jugador)
// funcion que determina si un nodo es terminal, ha ganado MAX o MIN
// actual: tablero actual
// jugador: 1 si es Max -1 si es Min
//devuelve:  si ha gando MAX 100, si ha ganado MIN -100, empate 0
// si no es terminal tambiŽn devuelve 0
int terminal(tNodo *actual, int jugador);

void dispNodo(tNodo *s);
int opuesto( int jugador);
int lleno(tNodo *s);

int imin(int v1, int v2);

int imax(int v1, int v2);

int heuristica(tNodo *nodo, int jugador, int pos);


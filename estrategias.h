
#ifndef _ESTRATEGIAS_H_
#define _ESTRATEGIAS_H_

tNodo *jugadaAdversario(tNodo *t);
tNodo *minimax(tNodo *nodo);
int piezaValida(tNodo *actual, int selectorPieza);
int valorMin(tNodo *nodo, int prof);
int valorMax(tNodo *nodo, int prof);

tNodo *poda_ab(tNodo *nodo);
int valorMin_ab(tNodo *nodo, int jugador, int prof, int alfa, int beta);
int valorMax_ab(tNodo *nodo, int jugador, int prof, int alfa, int beta);

#endif // _ESTRATEGIAS_H_

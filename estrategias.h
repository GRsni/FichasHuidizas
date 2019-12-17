
#ifndef _ESTRATEGIAS_H_
#define _ESTRATEGIAS_H_

tNodo *jugadaAdversario(tNodo *t);
tNodo *minimax(tNodo *nodo);
int piezaValida(tNodo *actual, int selectorPieza);
int valorMin(tNodo *nodo, int prof);
int valorMax(tNodo *nodo, int prof);

#endif // _ESTRATEGIAS_H_


#ifndef _ESTRATEGIAS_H_
#define _ESTRATEGIAS_H_

tNodo *jugadaAdversario(tNodo *t);
tNodo *minimax(tNodo *nodo);
int piezaValida(tNodo *actual, int selectorPieza);
int valorMin(tNodo *nodo);
int valorMax(tNodo *nodo);

#endif // _ESTRATEGIAS_H_

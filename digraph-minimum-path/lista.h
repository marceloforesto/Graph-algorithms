#ifndef _LISTA_H
#define _LISTA_H

typedef struct grafo *Grafo;
typedef struct no *link;

link novoNo(int peso, int w, link next);
Grafo inicializa(int V);
void inserir(Grafo G, int v, int w, int pese);
void dijkstra(Grafo G, int s, int fila[], double valores[]);

#endif
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

#define MAX 999
#define MAXV 99

struct grafo {
	int V;
	int A;
	link *adj;
};

struct no {
	int peso;
	int w;
	link proximo;
};

link novoNo(int peso, int w, link proximo) { 
	link a = malloc( sizeof (struct no));
	a -> peso = peso;
	a -> w = w; 
	a -> proximo = proximo;     
	return a;                         
}

Grafo inicializa(int V) { 
	int v;
	Grafo G = malloc( sizeof *G);
	G -> V = V; 
	G -> A = 0;
	G -> adj = malloc( V * sizeof (link));
	for (v = 0; v < V; v++) 
		G -> adj[v] = NULL;
	return G;
}

void inserir(Grafo G, int v, int w, int peso) { 
	link a;
	for (a = G -> adj[v]; a != NULL; a = a -> proximo) 
		if (a -> w == w) 
			return;
	G -> adj[v] = novoNo(peso, w, G->adj[v]);
	G -> A++;
}

void kruskal(Grafo G, Grafo MST) { 
	int componente[MAXV], v; 
	link a;

	for (v = 0; v < G -> V; v++) 
		componente[v] = v;
	
	while (1) {
		int m, n, x, y;
		int custo = MAX;
		for (v = 0; v < G -> V; v++) 
			for (a = G -> adj[v]; a != NULL; a = a->proximo) 
				if (componente[v] != componente[a -> w] && custo > a -> peso) {
					custo = a->peso;
					m = v; 
					n = a->w;
				}
		if (custo == MAX) {
			return; 
		}
		
		inserir(MST, m, n, custo);
		inserir(MST, n, m, custo);
		x = componente[m]; 
		y = componente[n];
		
		for (v = 0; v < G -> V; v++) 
			if (componente[v] == y)
				componente[v] = x;
	}
}

void somaPesos (Grafo G, Grafo MST) {
	int somaGrafo, somaMst;
	link a;
	
	somaGrafo = 0;
	somaMst = 0;
	
	for (int j = 0; j < G->V; j++)
		for (a = G -> adj[j]; a != NULL; a = a -> proximo)
			somaGrafo += a -> peso;
		
	for (int j = 0; j < MST->V; j++)
		for (a = MST -> adj[j]; a != NULL; a = a -> proximo)
			somaMst += a -> peso;
	
	somaGrafo /= 2;
	somaMst /= 2;
		
	printf("%d %d", somaGrafo, somaMst);
}
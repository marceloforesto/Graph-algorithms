#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "fila.h"

#define MAX 100000

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

void dijkstra(Grafo G, int s, int parent[], double valores[]) { 
   int v0, w, arco[MAX];
   link a; 
   double c;
   for (w = 0; w < G->V; w++) 
      parent[w] = arco[w] = -1; 
   parent[s] = s;
   valores[s] = 0.0; 
   inicializaFila(G->V); 
   
   for (a = G->adj[s]; a != NULL; a = a->proximo) {
      w = a->w, c = a->peso;
      valores[w] = c; 
      insereFila(w, valores); 
      arco[w] = s; 
   } 

   while (!filaVazia()) {
      v0 = removeFila( valores); 
      parent[v0] = arco[v0]; 
      for (a = G->adj[v0]; a != NULL; a = a->proximo) {
         w = a->w; 
		 c = a->peso;
         if (parent[w] == -1) 
			 break;
         if (arco[w] == -1) { 
            valores[w] = valores[v0] + c; 
            insereFila( w, valores); 
            arco[w] = v0; 
         } 
         else if (valores[w] > valores[v0] + c) {
            valores[w] = valores[v0] + c; 
            organizaFila( w, valores); 
            arco[w] = v0; 
         }
      }
   }
   excluiFila( ); 
}
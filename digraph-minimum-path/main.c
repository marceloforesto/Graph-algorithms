#include <stdio.h>
#include "lista.h"
#define MAX 100000

int main() {
	int aresta, vertice, v1, v2, p, fila[MAX];
	double valores[MAX];
	scanf("%d %d", &vertice, &aresta);
	
	Grafo G = inicializa(vertice);

	for (int i = 0; i < aresta; i++) {
		scanf("%d %d %d", &v1, &v2, &p);
		inserir(G, v1, v2, p);
	}
	
	scanf("%d %d", &v1, &v2);
	
	dijkstra(G, v2, fila, valores);
	
	return 0;
}
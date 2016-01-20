#include <stdio.h>
#include "matriz.h"

int main() {
	int aresta, vertice, v1, v2;
	scanf("%d %d", &vertice, &aresta);
	Digraph G = inicializa(vertice);
	
	for (int i = 0; i < aresta; i++) {
		scanf("%d %d", &v1, &v2);
		inserir(G, v1, v2);
	}

	DAG(G);
	display();
	return 0;
}
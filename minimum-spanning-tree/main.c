#include <stdio.h>
#include "lista.h"

int main() {
	int aresta, vertice, v1, v2, p, soma;
	
	scanf("%d %d", &vertice, &aresta);
	
	Grafo G = inicializa(vertice);
	Grafo MST = inicializa(vertice);

	for (int i = 0; i < aresta; i++) {
		scanf("%d %d %d", &v1, &v2, &p);
		inserir(G, v1, v2, p);
		inserir(G, v2, v1, p);
	}
	
	kruskal(G, MST);
	somaPesos(G, MST);
	
	return 0;
}
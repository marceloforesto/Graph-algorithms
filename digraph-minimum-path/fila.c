#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializaFila(int maxN) { 
   pq = malloc( (maxN++) * sizeof (int));
   qp = malloc( maxN * sizeof (int));
   N = 0; 
}

static void exch(int i, int j) {
   int t;
   t = pq[i]; pq[i] = pq[j]; pq[j] = t;
   qp[pq[i]] = i;
   qp[pq[j]] = j;
}

static void cima(int k, double prty[]) {
   while (k > 1 && maior( k/2, k)) {
      exch( k/2, k);
      k = k/2;
   }
}

static void fixDown(int k, double prty[]) { 
   int j;
   while (2*k <= N) { 
      j = 2*k;
      if (j < N && maior(j, j+1)) j++;
      if (!maior( k, j)) break;
      exch(k, j); 
      k = j;
   }
}

int filaVazia(void) { 
   return N == 0; 
}

void insereFila(int v, double prty[]) {
   qp[v] = ++N; 
   pq[N] = v; 
   cima(N, prty); 
}

int removeFila(double prty[]) { 
   exch(1, N); 
   --N; 
   fixDown( 1, prty); 
   return pq[N+1]; 
}

void organizaFila(int w, double prty[]) { 
   cima(qp[w], prty); 
}

void excluiFila() { 
   free(pq);
   free(qp);
}
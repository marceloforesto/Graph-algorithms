#ifndef _FILA_H
#define _FILA_H

static int *pq; 
static int N;

#define maior(i, j) (prty[pq[i]] > prty[pq[j]] ? 1 : 0)

static int *qp;

static void exch(int i, int j);

static void cima(int k, double prty[]);

static void baixo(int k, double prty[]);

void inicializaFila(int maxN);

int filaVazia(void);

void insereFila(int v, double prty[]);

int removeFila(double prty[]);

void organizaFila(int w, double prty[]);

void excluiFila();

#endif

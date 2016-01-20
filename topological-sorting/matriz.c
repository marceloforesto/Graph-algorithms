#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

#define GRAY 0
#define WHITE -1
#define BLACK 1

static int conta, color[999], tsi[999], time;

struct digraph {
	int V;
	int A;
	link *adj;
};

struct node {
	int w;
	link next;
};

link novoNo( int w, link next) { 
	link a = malloc( sizeof (struct node));
	a->w = w; 
	a->next = next;     
	return a;                         
}

Digraph inicializa(int V) { 
	int v;
	Digraph G = malloc( sizeof *G);
	G->V = V; 
	G->A = 0;
	G->adj = malloc( V * sizeof (link));
	for (v = 0; v < V; v++) 
		G->adj[v] = NULL;
	return G;
}

void inserir(Digraph G, int v, int w) { 
	link a;
	for (a = G->adj[v]; a != NULL; a = a->next) 
		if (a->w == w) return;
	G->adj[v] = novoNo( w, G->adj[v]);
	G->A++;
}

void DAG(Digraph G) { 
   int v; 

   for (v = 0; v < G->V; v++)  
      color[v] = WHITE; 
   time = 0;
   for (v = 0; v < G->V; v++)
      if (color[v] == WHITE) 
         visit( G, v);
}

void visit(Digraph G, int v) { 
   link a; 
   color[v] = GRAY; 
   for (a = G->adj[v]; a != NULL; a = a->next)
      if (color[a->w] == WHITE) 
         visit( G, a->w);
   color[v] = BLACK;
   push(v);
   
}

#define MAXSIZE 100
 
struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;
 
void push (int num) {

    if (s.top != (MAXSIZE - 1)) {
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
}

void display (Digraph G)
{
    if (s.top != -1) {
        for (int i = s.top; i > 0; i--) 
            printf ("%d ", s.stk[i]);
    }
}
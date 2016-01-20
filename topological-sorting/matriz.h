#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct digraph *Digraph;
typedef struct node *link;

link novoNo( int w, link next);
Digraph inicializa(int V);
void inserir(Digraph G, int v, int w);
void DAG (Digraph G);
void visit (Digraph G, int v);





struct stack;
typedef struct stack STACK;
void push (int num);
void display ();

#endif
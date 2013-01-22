#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define BIALY 0
#define SZARY 1
#define CZARNY 2
typedef enum {FALSE,TRUE} bool;


typedef struct VERTEX{
	unsigned int label;
	unsigned int color;
}VERTEX;

typedef struct EDGE{
	unsigned int E;
	bool checked;
}EDGE;

typedef struct GRAPH{
	unsigned int size;
	VERTEX *labels;
	EDGE **edges;
}GRAPH;

typedef struct stack{
  unsigned int top;
  unsigned int *vertex;
  unsigned int size;
}stack;


/*Graph.c*/
GRAPH *create_graph(void);
unsigned int get_size_of_vertex();
VERTEX *create_points(GRAPH *G);
EDGE **alloc_edges(GRAPH *G);
void add_edges(GRAPH *G);
void view_edges(GRAPH *G);
void transfer_graph(GRAPH *G);
void delete_vertex(unsigned int i,GRAPH *G);
void reset_edges(GRAPH *G);
void free_graph(GRAPH *G);
/********/

/*DFS.c*/
void DFS_VISIT(GRAPH *G,unsigned int u,stack *s);
/*******/

/*Stack.c*/
stack *allocation_stack(unsigned int n,unsigned int how);
bool stack_empty(stack *s);
bool Push(stack *s, unsigned int x);
unsigned int Pop(stack *s);
void pop_false(unsigned int j,stack *s,unsigned int size);
stack *realloc_stacks(unsigned int n,stack *stacks);
void reset_stack(stack *s);
void free_stack(stack *s);
/*********/

/*Kosaraju.c*/
void Kosaraju(GRAPH *G,stack *s);
/*********/

#endif

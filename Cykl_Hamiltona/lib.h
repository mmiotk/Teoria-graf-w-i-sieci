#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {FALSE,TRUE} bool;

typedef struct GRAPH{
	unsigned int size;
	unsigned int *labels;
	unsigned int **edges;
}GRAPH;

/*Graph.c*/
GRAPH *create_graph(void);
unsigned int get_size_of_vertex();
unsigned int *create_points(GRAPH *G);
unsigned int **alloc_edges(GRAPH *G);
void add_edges(GRAPH *G);
void view_edges(GRAPH *G);
void free_graph(GRAPH *G);
/********/

/*Hamilton.c*/
unsigned int **create_hamilton_table(GRAPH *G);
void view_hamilton_table(unsigned int **tab,GRAPH *G);
void fill_hamilton_table(unsigned int **tab,GRAPH *G);
void if_hamilton(unsigned int **tab,GRAPH *G);
void free_hamilton_table(unsigned int **temp,GRAPH *G);
/********/

#endif

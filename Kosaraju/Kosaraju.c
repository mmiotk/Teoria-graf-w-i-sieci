#include "lib.h"

void Kosaraju(GRAPH * G, stack * s)
{
    transfer_graph(G);
    unsigned int temp_edge;
    unsigned int i;
    if (s->top < G->size) {
	printf("Graf nie jest silnie spójny!\n");
	return;
    }
    while (stack_empty(s) != TRUE) {
	temp_edge = Pop(s);
	//printf("Pop:%d\n",temp_edge);
	if (temp_edge != 0) {
	    stack *stacks = allocation_stack(G->size, 1);
	    DFS_VISIT(G, temp_edge, stacks);
	    printf("Skladowa spojnosc: ");
	    //view_edges(G);
	    //printf("Stack top == %d\n",stacks->top);
	    while (stack_empty(stacks) != TRUE) {
		temp_edge = Pop(stacks);
		printf("%d ", temp_edge);
		delete_vertex(temp_edge, G);
		pop_false(temp_edge, s, G->size);
	    }
	   putchar('\n');


	    free_stack(stacks);

	}
    }

}

#include "lib.h"


int main(void)
{
    GRAPH *G = create_graph();
   stack *stos= allocation_stack(G->size, 1);
    unsigned int i=1;
    view_edges(G);

    //putchar('\n');
	while(i<=G->size){ 
		
	 
	
	// printf("Zazcynam od %d\n",i);
    DFS_VISIT(G, i, stos);
    if(stos->top==G->size){
		//printf("Super\n");
		break;
	}
	else{
	i++;
	reset_edges(G);
	reset_stack(stos);
	}
	}
    Kosaraju(G, stos);
    //int i;
    //for(i=1;i<=G->size;i++){
    //      printf("%d ",Pop(stos));
    //}
    //putchar('\n');
    //transfer_graph(G);
    //G->edges[4][1].E=0;

    //DFS_VISIT(G,4,stos);
    free_graph(G);
    free_stack(stos);
    return EXIT_SUCCESS;
}


#include "lib.h"

void DFS_VISIT(GRAPH * G, unsigned int u, stack * s)
{
    unsigned int i;
    for (i = 1; i <= G->size; i++) {
	if (G->edges[u][i].E == 1) {
	    //printf("Tak dla %d %d\n",u,i);
	    //printf("Bo E[%d][%d]==%d\n",u,i,G->edges[u][i].E);
	    if (G->labels[i].color == BIALY) {
		//      printf("Odwiedzam %d z wierzcholka %d\n",i,u);
		DFS_VISIT(G, i, s);
	    }
	    //G->labels[u].color=CZARNY;
	} //else {
	    G->labels[u].color = CZARNY;
	//}

    }
   // printf("Odwiedzam %d \n", u);
    Push(s, u);
    //G->labels[u].color=CZARNY;
    /*
       for(i=1;i<=G->size;i++){
       printf("%d:C==%d\n",i,G->labels[i].color);
       }
     */

}

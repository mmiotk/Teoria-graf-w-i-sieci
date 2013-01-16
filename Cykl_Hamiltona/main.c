#include "lib.h"


int main(void){
	GRAPH *G=create_graph();
	unsigned int **hamilton_table;
	hamilton_table=create_hamilton_table(G);
	fill_hamilton_table(hamilton_table,G);
	//view_hamilton_table(hamilton_table,G);
	if_hamilton(hamilton_table,G);
	free_hamilton_table(hamilton_table,G);
	free_graph(G);
	return EXIT_SUCCESS;
}

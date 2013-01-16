#include "lib.h"

unsigned int get_size_of_vertex(){
	unsigned int temp;
	scanf("%d",&temp);
	return temp;
}

unsigned int *create_points(GRAPH *G){
	unsigned int *temp=malloc((G->size+1)*sizeof(unsigned int));
	if(temp==NULL){
	perror("MALLOC POINTS");
	exit(1);
	}	
	unsigned int i;
	for(i=1;i<=G->size;i++){
		temp[i]=i;
	}
	return temp;
}

unsigned int **alloc_edges(GRAPH *G){
	unsigned int **temp_edge;
	unsigned int i;
	temp_edge=(unsigned int**)calloc((G->size+1),sizeof(unsigned int*));
	if(temp_edge==NULL){
		perror("EDGE ONE MALLOC");
		exit(1);
	}
	for(i=1;i<=G->size;i++){
		temp_edge[i]=(unsigned int*)calloc((G->size+1),sizeof(unsigned int));
		if(temp_edge[i]==NULL){
		perror("EDGE ONE MALLOC");
		exit(1);
	}
	}
	return temp_edge;
}
void add_edges(GRAPH *G){
	unsigned int i,j;
	while(scanf("%d %d",&i,&j)!=EOF){
		G->edges[i][j]=1;
		G->edges[j][i]=1;
	}
}

void view_edges(GRAPH *G){
	unsigned int i,j;
	for(i=1;i<=G->size;i++){
		for(j=1;j<=G->size;j++){
			printf("%d ",G->edges[i][j]);
		}
		putchar('\n');
	}
}

GRAPH *create_graph(void){
	GRAPH *temp=malloc(1*sizeof(GRAPH));
	if(temp==NULL){
	perror("MALLOC GRAPH");
	exit(1);
	}
	temp->size=get_size_of_vertex();
	temp->labels=create_points(temp);
	temp->edges=alloc_edges(temp);
	add_edges(temp);
	view_edges(temp);
	return temp;
}



void free_graph(GRAPH *G){
	unsigned int i;
	free(G->labels);
	for(i=1;i<=G->size;i++){
		free(G->edges[i]);
	}
	free(G->edges);
	free(G);
}

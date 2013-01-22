#include "lib.h"

unsigned int get_size_of_vertex()
{
    unsigned int temp;
    scanf("%d", &temp);
    return temp;
}

VERTEX *create_points(GRAPH * G)
{
    VERTEX *temp = malloc((G->size + 1) * sizeof(VERTEX));
    if (temp == NULL) {
	perror("MALLOC POINTS");
	exit(1);
    }
    unsigned int i;
    for (i = 1; i <= G->size; i++) {
	temp[i].label = i;
	temp[i].color = BIALY;

    }
    return temp;
}

EDGE **alloc_edges(GRAPH * G)
{
    EDGE **temp_edge;
    unsigned int i;
    temp_edge = (EDGE **) calloc((G->size + 1), sizeof(EDGE *));
    if (temp_edge == NULL) {
	perror("EDGE ONE MALLOC");
	exit(1);
    }
    for (i = 1; i <= G->size; i++) {
	temp_edge[i] = (EDGE *) calloc((G->size + 1), sizeof(EDGE));
	if (temp_edge[i] == NULL) {
	    perror("EDGE ONE MALLOC");
	    exit(1);
	}
    }
    return temp_edge;
}

void add_edges(GRAPH * G)
{
    unsigned int i, j;
    while (scanf("%d %d", &i, &j) != EOF) {
	G->edges[i][j].E = 1;
	G->edges[i][j].checked = FALSE;
	//G->edges[j][i]=1;
    }
}

void view_edges(GRAPH * G)
{
    unsigned int i, j;
    for (i = 1; i <= G->size; i++) {
	for (j = 1; j <= G->size; j++) {
	    printf("%d ", G->edges[i][j].E);
	}
	putchar('\n');
    }
}

void reset_edges(GRAPH *G){
	 unsigned int i, j;
    for (i = 1; i <= G->size; i++) {
	for (j = 1; j <= G->size; j++) {
	     G->labels[i].color=BIALY;
	     G->labels[j].color=BIALY;
	}
	
    }
}

GRAPH *create_graph(void)
{
    GRAPH *temp = malloc(1 * sizeof(GRAPH));
    if (temp == NULL) {
	perror("MALLOC GRAPH");
	exit(1);
    }
    temp->size = get_size_of_vertex();
    temp->labels = create_points(temp);
    temp->edges = alloc_edges(temp);
    add_edges(temp);
//      view_edges(temp);
    return temp;
}

void transfer_graph(GRAPH * G)
{
    unsigned int i, j;
    for (i = 1; i <= G->size; i++) {
	for (j = 1; j <= G->size; j++) {
	    if (G->edges[i][j].E == 1 && G->edges[j][i].E != 1
		&& G->edges[i][j].checked == FALSE) {
		//      printf("TAK dla %d %d\n",i,j);
		G->edges[i][j].E = 0;
		G->edges[j][i].E = 1;
		G->edges[i][j].checked = TRUE;
		G->edges[j][i].checked = TRUE;

	    }
	    G->labels[i].color = BIALY;
	    G->labels[j].color = BIALY;
	}
    }
}

void delete_vertex(unsigned int i, GRAPH * G)
{
    unsigned int j;
    for (j = 1; j <= G->size; j++) {
	G->edges[i][j].E = 0;
	G->edges[j][i].E = 0;
    }
}

void free_graph(GRAPH * G)
{
    unsigned int i;
    free(G->labels);
    for (i = 1; i <= G->size; i++) {
	free(G->edges[i]);
    }
    free(G->edges);
    free(G);
}

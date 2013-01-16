#include "lib.h"




unsigned int **create_hamilton_table(GRAPH *G){
	unsigned int **temp;
	unsigned int i;
	unsigned int size_table = 1 << G->size; /*2^n*/
	unsigned int row_size = G->size+1;
	//printf("Row_size=%d\n",row_size);
	//printf("size_table=%d\n",size_table);
	temp = (unsigned int**)calloc(row_size,sizeof(unsigned int*));
	for(i=0;i<row_size;i++){
		temp[i]=(unsigned int*)calloc(size_table,sizeof(unsigned int ));
	}
	return temp;
}

void view_hamilton_table(unsigned int **tab,GRAPH *G){
	unsigned int i,j;
	unsigned int size_columns = 1<<G->size;
	for(i=1;i<=G->size;i++){
		for(j=1;j<size_columns;j++){
			//printf("J=%d ",j);
		//	printf("%d %d",i,j);
			printf("%d ",tab[i][j]);
		}
		putchar('\n');
	}
}

bool binary_check(unsigned int i){
	unsigned int a=i&(i-1);
	if(a==0){
		return TRUE;
	}
	else
	return FALSE;
}

bool common_element(unsigned int collection,unsigned int vertex){
	unsigned int a = collection&vertex;
	//printf("C:%d V:%d\n",collection,vertex);
	//printf("A:%d\n",a);
	if(a!=0){
		return TRUE;
	}
	else 
	return FALSE;
}



unsigned int function(unsigned int **tab,unsigned int collection,unsigned int vertex,GRAPH *G,unsigned int **edge,unsigned int v_label){
	//printf("C:%d V:%d\n",collection,vertex);
	unsigned int _and=collection|vertex;
	unsigned int _new_collection;
	unsigned int i;
	//printf("%d\n",_and);
	if(_and==vertex){
	//	printf("YES\n");
	//tab[k][collection]=1;
	return 1;
	}
	else{
		if(binary_check(collection)==FALSE && common_element(collection,vertex)==TRUE){
			//printf("Liczba %d jest potega dwojki\n",collection);
		//printf("!C:%d !V:%d\n",collection,vertex);
		_new_collection = collection^vertex;
	//	printf("NewCollection:%d\n",_new_collection);
		for(i=1;i<=G->size;i++){
			if(common_element(_new_collection,1<<(G->size-i))==TRUE){
				//printf("[%d][%d]\n",i,v_label);
				//printf("Function: Collection:%d Vertex:%d Result:%d\n",_new_collection,1<<(G->size-1),function(_new_collection,1<<(G->size-i),G,edge,i));
			//	printf("edge[%d][%d]==%d\n",i,v_label,edge[i][v_label]);
			//	printf("tab[%d][%d]==%d\n",i,_new_collection,tab[i][_new_collection]);
				if(edge[i][v_label]==1 && tab[i][_new_collection]==1){//function(_new_collection,1<<(G->size-i),G,edge,i)==1){
			//		printf("YES\n");
					//tab[k][collection]=1;
					return 1;
				}
			}
		}
		//putchar('\n');
	}
	}
	//tab[k][collection]=0;
	return 0;
}

void fill_hamilton_table(unsigned int **tab,GRAPH *G){
	unsigned int i,j;
	unsigned int size_columns = 1<<G->size;
	unsigned int size_rows = G->size+1;
	for(j=1;j<size_columns;j++)
	{
		for(i=1;i<size_rows;i++){
			//printf("%d %d %d\n",i,j,tab[i][j]);
			//printf("%d\n",1<<G->size-i);
			
		//	if(binary_check(j)==TRUE){
			//	printf("[%d] [%d]\n",j,i);
			tab[i][j]=function(tab,j,1<<(G->size-i),G,G->edges,i);
			//}
		}
		//putchar('\n');
	}
	
	
}

void if_hamilton(unsigned int **tab,GRAPH *G){
	unsigned int i;
	unsigned int j=1<<(G->size);
	bool var=FALSE;
	//printf("j==%d\n",j);
	for(i=1;i<=G->size;i++){
		//printf("%d\n",tab[i][j-1]);
		if(tab[i][j-1]==1){
		printf("Graf posiada sciezke hamiltona konczac na wierzcholku %d\n",i);
		var=TRUE;
		}
	}
	if(var==FALSE){
		printf("Graf nie posiada sciezki hamiltona\n");
	}
}

void free_hamilton_table(unsigned int **temp,GRAPH *G){
	unsigned int i;
	for(i=0;i<=G->size;i++){
	//	printf("%d\n",i);
		free(temp[i]);
	}
	free(temp);
}

#include "lib.h"

int get_size(unsigned int *a){
	unsigned int temp;
	while(1){
		scanf("%d",&temp);
		if(temp>0){
		*a=temp;
		return TRUE;
		}
	}
}

int alloc_points(double *a,POINT **tab,unsigned int size){
	unsigned int i;
	double maxi_temp=-10;
	POINT *temp=(POINT *)malloc(size*sizeof(POINT));
	if(!temp){
		perror("malloc");
		return FALSE;
	}
	for(i=0;i<size;i++){
		assert(add_point(&temp[i])==1);
		if(maxi_temp<temp[i].xx)
		maxi_temp=temp[i].xx;
	}
	printf("BLA %lf\n",maxi_temp);
	*a=maxi_temp;
	*tab=temp;
	
	return TRUE;
}

int **create_segments(unsigned int size){
	unsigned int i;
	int **tab;
	tab=(int **)calloc(size,sizeof(int *));
	for(i=0;i<size;i++){
		tab[i]=(int *)calloc(size,sizeof(int));
	}
	return tab;
}

int free_points(POINT *tab){
	free(tab);
	return TRUE;
}

int free_segments(int **tab,unsigned int size){
	unsigned int i;
	for(i=0;i<size;i++){
		free(tab[i]);
	}
	free(tab);
	return TRUE;
}

int add_segments(POINT *points,int **tab,int size){
	int i,j,quit;
	while(1){
		quit=scanf("%d %d",&i,&j);
		if(quit==EOF)
		break;
		if(i>-1 && i<size && j>-1 && j<size && tab[i][j]==0 && tab[j][i]==0)
		tab[i][j]=TRUE;
		tab[j][i]=TRUE;
		points[i].deg++;
		points[j].deg++;
		
	}
	return TRUE;
}

void triangulal_polygol(POLYGON a){
	int i,j;
	POLYGON y=a;
	for(i=0;i<a.size_points;i++){
		for(j=i;j<a.size_points;j++){
			if(i!=j && a.segments[i][j]==0){
				printf("Sprawdzam dla punktow: %lf %lf %lf %lf\n",a.points[i].xx,a.points[i].yy,a.points[j].xx,a.points[j].yy);
				
					POINT divide;
					divide.xx = (a.points[j].xx+a.points[i].xx)/2;
					divide.yy = (a.points[j].yy+a.points[i].yy)/2;
						if(Diagonal(i,j,a) && check_segments(i,j,a)==TRUE){	
						a.segments[i][j]=TRUE;
						a.segments[j][i]=TRUE;
						a.points[i].deg++;
						a.points[j].deg++;
				}
			}
		}
	}
}

int check_segments(int a,int b,POLYGON temp){
	int i,j;
	for(i=0;i<temp.size_points;i++){
		for(j=0;j<temp.size_points;j++){
			if(i!=j && temp.segments[i][j]!=0 && i!=a && j!=a && i!=b && j!=b){
			//	printf("Dla %d %d\n",i,j);
				SEGMENT a1,b1;
				a1.a=temp.points[i];
				a1.b=temp.points[j];
				b1.a=temp.points[a];
				b1.b=temp.points[b];
				if(Intersect(a1.a,a1.b,b1.a,b1.b)==TRUE)
				return FALSE;
			}
		}
	}
	return TRUE;
}



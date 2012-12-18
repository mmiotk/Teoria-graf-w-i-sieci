#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int size_of_vertex(){
	unsigned int temp;
	while(1){
	printf("Podaj liczbe wierzcholkow grafu: ");
	scanf("%d",&temp);
	if(temp>0)
	break;
	}
	return temp;
}

double **alokuj_tablice(unsigned int n){
	double **macierz;
	unsigned int i;
	macierz = (double**)malloc(n*sizeof(double*));
	for(i=0;i<n;i++){
		macierz[i]=(double *)malloc(n*sizeof(double));
	}
	return macierz;
}
void free_table(double **table,unsigned int n){
	unsigned int i;
	for(i=0;i<n;i++){
		free(table[i]);
	
	}
	free(table);
	
}
void wypelnij_krawedzie(double **table){
	unsigned int i,j;
	double waga;
	while(scanf("%d %d %lf",&i,&j,&waga)!=EOF){
		if(i!=j)
		table[i][j] = waga;
	}
	
}
void wypelnij_INF(double **table,unsigned int n){
	unsigned int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)
				table[i][j] = 0;
			
			else
			table[i][j] = INFINITY;
		}
	}
}
void wypisz_wiersz(int n){
	int i;
	printf("  |");
	for(i=0;i<n;i++){
		printf("%d |",i);
	}
	putchar('\n');
}
void przedzialka(int n){
	int i;
	for(i=0;i<n;i++){
		printf("----");
	}
	putchar('\n');
}

void wyswietl_tablice(double **table,int n){
	int i,j;
	printf("\nMacierz D:\n");
	for(i=-1;i<n;i++){
		
		for(j=0;j<n;j++){
			if(i==-1){
			wypisz_wiersz(n);
			i++;
			przedzialka(n);
			}
			if(i-j==i){
				printf("%d |",i);
			}
			if(table[i][j]<0)
			printf("%.lf|",table[i][j]);
			else
			printf("%.lf |",table[i][j]);
		}
		putchar('\n');
		}
		
	
	putchar('\n');
}
double min(double a,double b){
	
	if(a<=b)
	return a;
	else
	return b;
}

void Floyd_Warshall(double **m,unsigned int n){
	unsigned int k,i,j;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				m[i][j]=min(m[i][j],m[i][k]+m[k][j]);
			}
		}
		
	}
	
}

int main(){
	double **macierz;
	
	int n = size_of_vertex();
	
	macierz = alokuj_tablice(n);
	
	wypelnij_INF(macierz,n);
	wypelnij_krawedzie(macierz);
	//wyswietl_tablice(macierz,n);
	Floyd_Warshall(macierz,n);
	wyswietl_tablice(macierz,n);
	free_table(macierz,n);
	
	
	
	return EXIT_SUCCESS;
	
}

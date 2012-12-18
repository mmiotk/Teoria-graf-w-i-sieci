#include <stdio.h>
#include <stdlib.h>

void generuj_drzewo(unsigned int n){
	int i;
	printf("%d\n",n);
	for(i=1;i<=n;i++){
		
		if(i==1){
			printf("1 2 -1");
		}
		else{
			if(2*i<=n)
			printf("%d ",2*i-1);
			if(2*i+1<=n)
			printf("%d ",2*i);
			
		}
		if(i!=1)
		printf("%d -1",i/2-1);
		putchar('\n');
	}
}

int main(void){
	unsigned int n;
	//printf("Podaj liczbe elementow: ");
	scanf("%d",&n);
	generuj_drzewo(n);
	return EXIT_SUCCESS;
}

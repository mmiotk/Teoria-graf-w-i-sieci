#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lib.h"

stack *allocation_stack(unsigned int n){
  stack *stos=(stack*)malloc(1*sizeof(stack));
  if(stos==NULL){
    perror("Blad malloc (stos)");
  }
  stos->vertex=malloc(n*sizeof(unsigned int));
  if(stos->vertex == NULL){
    perror("Blad malloc (vertex)");
  }
  stos->size = n;
  stos->top = 0;
  return stos;
}

bool stack_empty(stack *s){
  if(s->top == 0)
    return TRUE;
  else
    return FALSE;
}

bool Push(stack *s, unsigned int x){
  if(s->top == s->size){
	perror("Brak miejsca");
	return FALSE;
  }
  s->top++;
  s->vertex[s->top] = x;
  return TRUE;
}

unsigned int Pop(stack *s){
  if(stack_empty(s) == TRUE)
    perror("Niedomiar");
  else
    s->top = s->top-1;
    return s->vertex[s->top+1];
}

void free_stack(stack *s){
  free(s->vertex);
  free(s);
}

stack *filling_stack(POINT *tab, unsigned int n){
  stack *s = allocation_stack(n);
  int i, k, min_deg=INT_MAX, min_inx;
  for(k=0; k<n; k++){
	for (i=0; i<n; i++){
      if(tab[i].deg < min_deg && tab[i].is_visited == FALSE){
        min_deg = tab[i].deg;
        min_inx = i;
      }
    }
    Push(s, min_inx);
    tab[min_inx].is_visited = TRUE;
    min_deg=INT_MAX;
  }
  return s;
}

bool color_exist(POINT *tab,int **edge,unsigned int n,int color,int w){
	int i;
	for(i=0;i<n;i++){
		if(edge[w][i] == 1 && tab[i].color==color){
		return TRUE;
	}
	}
	return FALSE;
}
int count_colors(POINT *tab,unsigned int n){
	int *colors;
	int i,maxi_color=0;
	int max_colors=0;
	for(i=0;i<n;i++){
		if(tab[i].color>max_colors)
		max_colors=tab[i].color;
	}
	colors=calloc(max_colors+1,sizeof(int));
	for(i=0;i<n;i++){
		colors[tab[i].color]++;
	}
	maxi_color = colors[1];
	for(i=2;i<=max_colors;i++){
		if(maxi_color>colors[i])
		maxi_color=colors[i];
	}
	free(colors);
	return maxi_color;
}

int get_max_color(POINT *tab,int **edge,int inx,unsigned int n){
	int temp=0;
	int i;
	for(i=0;i<n;i++){
		if(edge[inx][i]==1 && tab[i].color>temp){
			temp=tab[i].color;
		}
	}
	return temp;
}
int coloring_sl(POINT *tab, int **edge, unsigned int n){
  stack *s = NULL;
  s= allocation_stack(n);
  s = filling_stack(tab, n);
  int i, j, color, inx;
  int max_color;
  for(i=0; i<n; i++){
    color = 0;
    inx = Pop(s);
    max_color=get_max_color(tab,edge,inx,n);
    if(max_color==0)
    tab[inx].color = 1;
    else if(max_color==1)
    tab[inx].color=2;
    else{
		for(j=1;j<=max_color+1;j++){
			if(color_exist(tab,edge,n,j,inx)==FALSE){
				tab[inx].color=j;
				break;
			}
			
		}
	}
 }
  putchar('\n');
  free_stack(s);
  return count_colors(tab,n);
}

void print_colors(POINT *tab,unsigned int n){
	int i;
	for(i=0;i<n;i++){
		printf("Wierzcholek %d ma kolor==%d\n",i,tab[i].color);
	}
}

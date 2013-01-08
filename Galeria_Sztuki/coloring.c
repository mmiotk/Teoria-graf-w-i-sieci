#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {FALSE, TRUE} bool;

typedef struct POINT{
  double xx;
  double yy;
  int deg;
  bool is_visited;
  unsigned int color;
}POINT;

/*typedef struct vertex{
  unsigned int label;
//  unsigned int deg;
  unsigned int color;
}vertex;*/

typedef struct stack{
  unsigned int top;
  unsigned int *vertex;
  unsigned int size;
//  unsigned int color;
}stack;

unsigned int ilo_wie(){
  unsigned int temp;
  while(1){
    printf("Podaj liczbe wierzcholkow grafu: ");
    scanf("%d",&temp);
    if(temp>0)
      break;
  }
  return temp;
}

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
//  stos->vertex->label = 0;
//  stos->vertex->deg = 0;
//  stos->vertex->color = 0;
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
//  s->vertex->label = name;
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

stack filling_stack(POINT *tab, unsigned int n){
  stack *s = allocation_stack(n);
  int i, j, k, min_deg, min_inx;
//  min_deg = tab[0]->deg;
  for(k=0; k<n; k++){
    for(j=0; j<n; j++){
      if(tab[j]->is_visited == FALSE){
        min_deg = tab[j]->deg;
        break;
      }
    }
    for (i=1; i<n; i++){
      if(tab[i]->deg < min_deg && tab[i]->is_visited == FALSE){
        min_deg = tab[i]->deg;
        min_inx = i;
      }
    }
    Push(s, min_inx);
    tab[min_inx]->is_visited = TRUE;
  }
  return s;
}

int coloring_sl(POINT *tab, int **edge, unsigned int n){
  stack *s = allocation_stack(n);
  s = filling_stack(tab, n);
  int i, j, color, inx, color_count, sentinel, sentinel_count;
  for(i=0; i<n; i++){
    color = 1;
    inx = Pop(s);
    for(j=0; j<n; j++){
      if(edge[inx][j]->neighbour == 1 && edge[inx][j]->color == color){
        color++;
        j = 0;
      }
    }
    tab[i]->color = color;
  }
  sentinel = n;
  sentinel_count = n;
  for(i=1; i<=n; i++){
    color_count = 0;
    for(j=0; j<n; i++){
      if(tab[j]->color == i){
        color_count++;
      }
    }
    if(color_count < sentinel_count){
      sentinel = i;
      sentinel_count = color_count;
    }
  }
  return sentinel;
}

int main(){
/*  stack *stos;
  int n = ilo_wie();
  stos = allocation_stack(n);
  assert(stack_empty(stos)==TRUE);
  Push(stos,1);
  Push(stos,2);
  Push(stos,3);
  Push(stos,4);
  assert(stack_empty(stos)==FALSE);
  assert(Pop(stos)==1);*/
  return 0;
}

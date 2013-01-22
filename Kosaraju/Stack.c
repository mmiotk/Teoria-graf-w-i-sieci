#include "lib.h"

stack *allocation_stack(unsigned int n, unsigned int how)
{
    stack *stos = (stack *) malloc(how * sizeof(stack));
    if (stos == NULL) {
	perror("Blad malloc (stos)");
    }
    stos->vertex = calloc(n+2, sizeof(unsigned int));
    if (stos->vertex == NULL) {
	perror("Blad malloc (vertex)");
    }
    stos->size = n;
    stos->top = 0;
    return stos;
}

bool stack_empty(stack * s)
{
    if (s->top == 0)
	return TRUE;
    else
	return FALSE;
}

bool Push(stack * s, unsigned int x)
{
    if (s->top == s->size) {
	perror("Brak miejsca");
	return FALSE;
    }
    s->top++;
    s->vertex[s->top] = x;
    return TRUE;
}

unsigned int Pop(stack * s)
{
    if (stack_empty(s) == TRUE)
	perror("Niedomiar");
    else
	s->top = s->top - 1;
    return s->vertex[s->top + 1];
}

void pop_false(unsigned int j, stack * s, unsigned int size)
{
    unsigned int i;
    for (i = 0; i < size; i++) {
	if (s->vertex[i] == j) {
	    s->vertex[i] = 0;
	}
    }
}

stack *realloc_stacks(unsigned int n, stack * stacks)
{
    void *tmp;
    if ((tmp = realloc(stacks, n * sizeof(stack))) == NULL) {
	perror("REALLOC FAILURE!");
	exit(1);
    } else {
	return tmp;
    }
}

void reset_stack(stack *s){
	while(stack_empty(s)!=TRUE){
		Pop(s);
	}
}

void free_stack(stack * s)
{
    free(s->vertex);
    free(s);
}

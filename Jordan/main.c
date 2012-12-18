#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MLD 1000000000.0
#define CZAS(co) clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&co)
/*struktura kolejki*/
typedef struct FIFO {
    int *tab;
    int head, tail, length;
    int count;
} FIFO;

FIFO *create_FIFO(unsigned int n)
{
    FIFO *temp = malloc(1 * sizeof(FIFO));
    temp->tab = malloc(n * sizeof(int));
    temp->head = temp->tail = 0;
    temp->length = n;
    return temp;
}

void ENQUEUE(FIFO * Q, int x)
{
    if (Q->head == 0 && Q->tail == Q->length) {
	printf("KOLEJKA PELNA\n");
	return;
    } else {
	Q->tab[Q->tail] = x;
	Q->count++;
	if (Q->tail == Q->length)
	    Q->tail = 0;
	else
	    Q->tail++;
    }
}

int DEQUENE(FIFO * Q)
{
    int x = Q->tab[Q->head];
    Q->count--;
    if (Q->head == Q->length)
	Q->head = 0;
    else
	Q->head++;
    return x;
}

 /*struktura kolejki */


/*struktura grafu drzewa*/
typedef struct VERTEX {
    int deg, size;
    unsigned int *tab;
} VERTEX;

VERTEX *create_vertex(unsigned int n)
{
    VERTEX *temp = (VERTEX *) malloc(n * sizeof(VERTEX));
    temp->deg = temp->size = 0;
    return temp;
}

void add_neighbours(VERTEX * temp, unsigned int n, FIFO * Q)
{
    unsigned int i;
    int neighbour_temp;
    for (i = 0; i < n; i++) {
	printf
	    ("Podaj wszystkich sasiadow wierzcholka %d: (Liczba < 0 przerywa wprowadzenie)\n",
	     i);
	while (1) {
	    scanf("%d", &neighbour_temp);
	    if (neighbour_temp >= 0) {
		if (temp[i].tab == NULL) {
		    temp[i].tab = malloc(1 * sizeof(int));
		    temp[i].tab[0] = neighbour_temp;
		    temp[i].deg++;
		    temp[i].size++;
		} else {
		    void *tmp;
		    tmp =
			realloc(temp[i].tab,
				((temp[i].size) + 1) * sizeof(int));
		    temp[i].tab = tmp;
		    temp[i].tab[temp[i].size] = neighbour_temp;
		    temp[i].deg++;
		    temp[i].size++;
		}
	    } else {
		if (temp[i].deg == 1)
		    ENQUEUE(Q, i);
		break;
	    }

	}
    }
}

void view_graph(VERTEX * temp, unsigned int n)
{
    unsigned int i, j;
    for (i = 0; i < n; i++) {
	printf("Wierzcholek %d ma sasiadow: ", i);
	for (j = 0; j < temp[i].size; j++) {
	    printf("%d ", temp[i].tab[j]);
	}
	putchar('\n');
	printf("STOPIEN WIERZCHOLKA %d:%d LICZBA SASIADOW:%d \n", i,
	       temp[i].deg, temp[i].size);

    }
}

void free_all(VERTEX * temp, FIFO * q, unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++) {
	free(temp[i].tab);
    }
    free(temp);
    free(q->tab);
    free(q);
}

unsigned int get_size_of_vertex()
{
    unsigned int temp;
    printf("Podaj liczbe wierzcholkow: ");
    scanf("%d", &temp);
    return temp;
}

/*struktura grafu drzewa*/
/*Algorytm Jordana*/
void JORDAN(VERTEX * temp, unsigned int n, FIFO * Q)
{
    unsigned int j, vertex_temp, size = n;
    unsigned temp_neighbour, fifoTempSize;
    while (n > 2) {
	fifoTempSize = Q->count;
	while (fifoTempSize > 0) {
	    vertex_temp = DEQUENE(Q);
	    temp[vertex_temp].deg = -1;
	    for (j = 0; j < temp[vertex_temp].size; j++) {
		if (temp[temp[vertex_temp].tab[j]].deg != 0)
		    temp[temp[vertex_temp].tab[j]].deg--;
		if (temp[temp[vertex_temp].tab[j]].deg == 1) {
		    ENQUEUE(Q, temp[vertex_temp].tab[j]);
		    break;
		}
	    }
	    fifoTempSize--;
	    n--;
	}
    }
    /*Wypisanie centrum drzewa */
    for (j = 0; j < size; j++) {
	if (temp[j].deg >= 0)
	    printf("Wierzcholek %d jest centrum drzewa\n", j);
    }
}

/*Algorytm Jordana*/
double oblicz_czas(struct timespec kon,struct timespec pocz){
  double wynik;
  wynik=(pocz.tv_sec+pocz.tv_nsec/MLD)-(kon.tv_sec+kon.tv_nsec/MLD);
  return wynik;
}

int main()
{
	struct timespec start,stop;
	double czas;
	CZAS(start);
    unsigned int sizeVertex = get_size_of_vertex();
    VERTEX *wierzcholki = create_vertex(sizeVertex);
    FIFO *Q1 = create_FIFO(sizeVertex);
    add_neighbours(wierzcholki, sizeVertex, Q1);
    JORDAN(wierzcholki, sizeVertex, Q1);
    free_all(wierzcholki, Q1, sizeVertex);
    CZAS(stop);
  czas=oblicz_czas(start,stop);
  printf("ROZMIAR==%d|CZAS==%3.10lf|n/T(n)==%3.10lf\n",sizeVertex,czas,sizeVertex/czas);
    return EXIT_SUCCESS;
}

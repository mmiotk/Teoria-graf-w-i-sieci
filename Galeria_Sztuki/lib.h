#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <unistd.h>
#include <time.h>
#define MLD 1000000000.0


typedef enum {FALSE , TRUE } bool;

typedef struct POINT{
	double xx;
	double yy;
	int deg;
	bool is_visited;
  unsigned int color;
}POINT;
typedef struct SEGMENT{
	POINT a;
	POINT b;
}SEGMENT;

typedef struct POLYGON{
	unsigned int size_points;
	POINT *points;
	int **segments;
	double max_of_x;
}POLYGON;

typedef struct stack{
  unsigned int top;
  unsigned int *vertex;
  unsigned int size;
}stack;

/*point.c*/
int add_point(POINT *a);
void view_point(POINT temp);
/*********/

/*segment.c*/
int add_segment(SEGMENT *a);
void view_segment(SEGMENT temp);
/***********/

/*test.c*/
void tests(void);
/********/

/*polygon.c*/
int get_size(unsigned int *a);
int alloc_points(double *a,POINT **tab,unsigned int size);
int free_points(POINT *tab);
int **create_segments(unsigned int size);
int free_segments(int **tab,unsigned int size);
int add_segments(POINT *points,int **tab,int size);
void triangulal_polygol(POLYGON a);
int check_segments(int a,int b,POLYGON temp);
void draw_polygon(POLYGON t);
double oblicz_czas(struct timespec kon,struct timespec pocz);
/*****************/

/*Collinear.c*/
double Area2(POINT a,POINT b,POINT c);
bool Left(POINT a,POINT b,POINT c);
bool LeftON(POINT a,POINT b,POINT c);
bool Collinear(POINT a,POINT b,POINT c);
bool InterrectProp(POINT a,POINT b,POINT c,POINT d);
bool Xor(int x,int y);
bool Between(POINT a,POINT b,POINT c);
bool Intersect(POINT a,POINT b,POINT c,POINT d);
/*************/
/*Pointinsearch.c*/
bool InCone( int i, int j, POLYGON P );
bool Diagonal(int i, int j, POLYGON P);
bool DiagonalIntExt( int i, int j, POLYGON P );
/*****************/

/*coloring.c*/
stack *allocation_stack(unsigned int n);
bool stack_empty(stack *s);
bool Push(stack *s, unsigned int x);
unsigned int Pop(stack *s);
void free_stack(stack *s);
stack *filling_stack(POINT *tab, unsigned int n);
int coloring_sl(POINT *tab, int **edge, unsigned int n);
bool color_exist(POINT *tab,int **edge,unsigned int n,int color,int w);
int count_colors(POINT *tab,unsigned int n);
int get_max_color(POINT *tab,int **edge,int inx,unsigned int n);
void print_colors(POINT *tab,unsigned int n);
/*************/

#endif

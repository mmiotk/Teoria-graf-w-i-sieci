#include "lib.h"

int add_segment(SEGMENT *temp){
	POINT x,y;
	assert(add_point(&x)==1);
	assert(add_point(&y)==1);
	temp->a=x;
	temp->b=y;
	return 1;
}

void view_segment(SEGMENT temp){
	view_point(temp.a);
	view_point(temp.b);
	putchar('\n');
}


	
	

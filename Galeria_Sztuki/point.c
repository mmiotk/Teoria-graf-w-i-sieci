#include "lib.h"

int add_point(POINT *a){
	POINT temp;
	scanf("%lf %lf",&temp.xx,&temp.yy);
	temp.deg=0;
	*a=temp;
	assert(a->xx==temp.xx);
	assert(a->yy==temp.yy);
	return 1;
}
void view_point(POINT temp){
	printf("%lf|%lf |",temp.xx,temp.yy);
}


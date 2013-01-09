#include "lib.h"

void tests(void){
	SEGMENT x,y;
	POINT p,q,r,z;
	p.xx=0; p.yy=0;
	q.xx=2; q.yy=2;
	r.xx=0; r.yy=2;
	z.xx=2; z.yy=0;
	x.a=p;	x.b=q;
	y.a=r;	y.b=z;
	assert(Intersect(x.a,x.b,y.a,y.b)==TRUE);
	z.xx=-2;
	y.b=z;
	assert(Intersect(x.a,x.b,y.a,y.b)==FALSE);
	z.xx=1; z.yy=1;
	y.b=z;
	z.xx=2; z.yy=0;
	r.xx=1; r.yy=1;
	y.b=z;
	y.a=r;
	p.xx=3; p.yy=1;
	q.xx=1; q.yy=2;
	r.xx=2.5;r.yy=2;
	z.xx=4;z.yy=2;
	x.a=p; x.b=q;
	y.a=r;y.b=z;
	assert(Intersect(x.a,x.b,y.a,y.b)==FALSE);
	
	
}

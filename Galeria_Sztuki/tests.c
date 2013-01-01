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
	//Do sprawdzenia
	//printf("%d\n",cutting_segment(x,y));
	z.xx=2; z.yy=0;
	r.xx=1; r.yy=1;
	y.b=z;
	y.a=r;
	//printf("%d\n",cutting_segment(x,y));
	p.xx=3; p.yy=1;
	q.xx=1; q.yy=2;
	r.xx=2.5;r.yy=2;
	z.xx=4;z.yy=2;
	x.a=p; x.b=q;
	y.a=r;y.b=z;
	//assert(Intersect(x.a,x.b,y.a,y.b)==FALSE);
	
	
	POLYGON temp;
	
	assert(get_size(&temp.size_points)==TRUE);
	alloc_points(&temp.max_of_x,&temp.points,temp.size_points);
	temp.segments=create_segments(temp.size_points);
	add_segments(temp.points,temp.segments,temp.size_points);
	int i,j;
	for(i=0;i<temp.size_points;i++){
		for(j=0;j<temp.size_points;j++){
			printf("%d|",temp.segments[i][j]);
			
		}
		putchar('\n');
	}
	triangulal_polygol(temp); 
	putchar('\n');
	for(i=0;i<temp.size_points;i++){
		for(j=0;j<temp.size_points;j++){
			printf("%d|",temp.segments[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	
	for(i=0;i<temp.size_points;i++){
		for(j=0;j<temp.size_points;j++){
			printf("%d|",temp.segments[i][j]);
		}
		putchar('\n');
	}
	for(i=0;i<temp.size_points;i++){
		printf("STOPIEN WIERZCHOLKA %d:%d\n",i,temp.points[i].deg);
	}
	free_segments(temp.segments,temp.size_points);
	free_points(temp.points);
	
}

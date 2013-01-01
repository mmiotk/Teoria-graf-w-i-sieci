#include "lib.h"

double Area2(POINT a,POINT b,POINT c){
	return (b.xx - a.xx)*(c.yy-a.yy)-(c.xx-a.xx)*(b.yy - a.yy);
}

bool Left(POINT a,POINT b,POINT c){
	return (Area2(a,b,c)>0);
}

bool LeftON(POINT a,POINT b,POINT c){
	return (Area2(a,b,c)>=0);
}

bool Collinear(POINT a,POINT b,POINT c){
	return (Area2(a,b,c)==0);
}

bool InterrectProp(POINT a,POINT b,POINT c,POINT d){
	if(Collinear(a,b,c) || Collinear(a,b,d) || Collinear(c,d,a) || Collinear(c,d,b))
	return FALSE;
	return Xor(Left(a,b,c),Left(a,b,d)) && Xor(Left(c,d,a),Left(c,d,b));
}

bool Xor(int x,int y){
	return !x^!y;
}

bool Between(POINT a,POINT b,POINT c){
	if(!Collinear(a,b,c))
	return FALSE;
	if(a.xx != b.xx){
		return ((a.xx <= c.xx && c.xx <= b.xx)||(a.xx >= c.xx && c.xx >= b.xx));
	}
	else{
		return ((a.yy <= c.yy && c.yy <= b.yy)||(a.yy >= c.yy && c.yy >= b.yy));
	}
}

bool Intersect(POINT a,POINT b,POINT c,POINT d){
	if(InterrectProp(a,b,c,d))
	return TRUE;
	else if(Between(a,b,c) || Between(a,b,d) || Between(c,d,a) || Between(c,d,b))
	return TRUE;
	return FALSE;
}

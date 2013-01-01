#include "lib.h"

bool InCone( int i, int j, POLYGON P )
{
 int  i1;  /* i + 1 */
 int  in1; /* i - 1 */
      i1  = (i + 1)     % P.size_points;
      in1 = (i + P.size_points - 1) % P.size_points;
      if ( LeftON(P.points[in1], P.points[i], P.points[i1]) )
      return  Left(P.points[i], P.points[j], P.points[in1]) && Left(P.points[j], P.points[i], P.points[i1] );
      else
      return !(LeftON(P.points[i], P.points[j], P.points[i1] ) && 
               LeftON(P.points[j], P.points[i], P.points[in1]) );
               
}

bool DiagonalIntExt( int i, int j, POLYGON P )
{
   int  k;
   int k1;
    for ( k = 0; k < P.size_points; k++ ) {
          k1 = (k+1) % P.size_points;
    if ( ! (( k == i ) || ( k1 == i )||( k == j ) || ( k1 == j ) ))
    if ( Intersect( P.points[i], P.points[j], P.points[k], P.points[k1] ) )
    return	FALSE;
    }
return	TRUE;
}

bool Diagonal(int i, int j, POLYGON P)
{
 return	InCone(i, j, P) && DiagonalIntExt(i, j,P);
}


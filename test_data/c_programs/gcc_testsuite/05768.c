




double F[2] = { 0., 0. }, e = 0.;


void f ()
{
 int i;
 double E, W, P, d;

 W = 1.;
 d = 2.*e;
 E = 1. - d;

 if( d > 0.01 )
 {
  P = ( W < E ) ? (W - E)/d : (E - W)/d;
  F[i] += P;
 }
}


float g ()
{
 int i;
 double E, W, P, d;

 W = 1.;
 d = 2.*e;
 E = 1. - d;

 if( d > 0.01 )
 {
  P = ( W < E ) ? (W - E)/d : (E - W)/d;
  F[i] += P;
 }

 return 1.0 / d;
}

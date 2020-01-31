static const unsigned long
 B1 = 715094163,
 B2 = 696219795;

static const double
 C = 5.42857142857142815906e-01,
 D = -7.05306122448979611050e-01,
 E = 1.41428571428571436819e+00,
 F = 1.60714285714285720630e+00,
 G = 3.57142857142857150787e-01;

double
cbrtl (double x)
{
  long hx;
  double r,s,w;
  double lt;
  unsigned sign;
  typedef unsigned unsigned32 __attribute__((mode(SI)));
  union {
    double t;
    unsigned32 pt[2];
  } ut, ux;
  int n0;

  ut.t = 1.0;
  n0 = (ut.pt[0] == 0);

  ut.t = 0.0;
  ux.t = x;

  hx = ux.pt[n0];
  sign=hx&0x80000000;
  hx ^=sign;
  if(hx>=0x7ff00000) return(x+x);
  if((hx| ux.pt[1-n0])==0)
    return(ux.t);

  ux.pt[n0] = hx;

  if(hx<0x00100000)
    {ut.pt[n0]=0x43500000;
     ut.t*=x; ut.pt[n0]=ut.pt[n0]/3+B2;
   }
  else
    ut.pt[n0]=hx/3+B1;


  r=ut.t*ut.t/ux.t;
  s=C+r*ut.t;
  ut.t*=G+F/(s+E+D/s);


  ut.pt[1-n0]=0; ut.pt[n0]+=0x00000001;


  s=ut.t*ut.t;
  r=ux.t/s;
  w=ut.t+ut.t;
  r=(r-ut.t)/(w+r);
  ut.t=ut.t+ut.t*r;


  ut.pt[n0] |= sign;

  lt = ut.t;
  lt -= (lt - (x/(lt*lt))) * 0.333333333333333333333;
  return lt;
}

main ()
{
  if ((int) (cbrtl (27.0) + 0.5) != 3)
    abort ();

  exit (0);
}

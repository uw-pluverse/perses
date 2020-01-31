typedef union
{
  double value;
  struct
  {
    unsigned int msw;
  } parts;
} ieee_double_shape_type;
double __ieee754_hypot(double x, double y)
{
 double a=x,b=y,t1,t2,y1,y2,w;
 int j,k,ha,hb;
 do { ieee_double_shape_type gh_u; gh_u.value = (x); (ha) = gh_u.parts.msw; } while (0);;
 if(hb > ha) {a=y;b=x;j=ha; ha=hb;hb=j;} else {a=x;b=y;}
 if(ha > 0x5f300000) {
    do { ieee_double_shape_type sh_u; sh_u.value = (a); sh_u.parts.msw = (ha); (a) = sh_u.value; } while (0);;
 }
 w = a-b;
 if (w <= b)
 {
     t2 = a - t1;
     w = t1*y1-(w*(-w)-(t1*y2+t2*b));
 }
 if(k!=0) {
 } else return w;
}

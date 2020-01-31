

double c;
double d;
double *f(int a)
{
  if(a) return &c;
  return &d;
}

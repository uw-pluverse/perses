


int
foo(int *z, int *y, int xx)
{
  *z = 1;
  if (xx)
    xx = 20;
  else
   xx = 30;
  *z = 2;
  *z = 3;
  return xx;
}

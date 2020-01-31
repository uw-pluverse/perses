


int g(int,int);
int f(int t, int c)
{
  int d = 0;
  int e = 0;
  if (t)
    {
      d = t;
      if (c) e = 1;
    }
  else d = 0, e = 0;
  return g(d,e);
}

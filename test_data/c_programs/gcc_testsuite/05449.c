


int g(int,int);
int h(int);
int f(int t, int c)
{
  int d = 0;
  int e = 0;
  if (t)
    {
      d = h(c);
      e = t;
    }
  else d = 0, e = 0;
  return g(e,d);
}








void toto (int *);

int bar (int a, int b, int c, int d, int e, int f, int g, int h)
{
  int res;

  toto (&res);
  return h;
}


int bar2 ()
{
  int res;

  toto (&res);
  return res;
}

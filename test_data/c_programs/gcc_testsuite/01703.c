







struct A
{
  int t;
  int i;
};

int foo () { return 3; }

main ()
{
  struct A loc, *locp;
  float f, g, *p;
  int T355, *T356;



  f = 3;
  g = 2;
  p = foo () ? &g : &f;
  if (*p > 0.0)
    g = 1;


  locp = malloc (sizeof (*locp));
  locp->i = 10;
  T355 = locp->i;


  T356 = &locp->i;
  *T356 = 1;



  T355 = locp->i;
  if (T355 != 1)
    abort ();

  return 0;
}

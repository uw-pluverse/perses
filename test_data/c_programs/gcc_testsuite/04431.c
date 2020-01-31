typedef struct {int a; char b;} T;

int h (T *);
T g (T);


h (T *x)
{
  if (x->a != 0 || x->b != 1)
    abort ();
}



T
g (T x)
{
  if (x.a != 13 || x.b != 47)
    abort ();
  x.a = 0;
  x.b = 1;
  h (&x);
  return x;
}



f ()
{
  T x;
  x.a = 13;
  x.b = 47;
  g (x);
  if (x.a != 13 || x.b != 47)
    abort ();
  x = g (x);
  if (x.a != 0 || x.b != 1)
    abort ();
}



main ()
{
  f ();
  exit (0);
}

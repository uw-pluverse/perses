typedef union
{
  struct {int a; int b;} s;
  double d;
} T;

int h (T *);
T g (T);


h (T *x)
{
  if (x->s.a != 0 || x->s.b != 1)
    abort ();
}



T
g (T x)
{
  if (x.s.a != 13 || x.s.b != 47)
    abort ();
  x.s.a = 0;
  x.s.b = 1;
  h (&x);
  return x;
}



f ()
{
  T x;
  x.s.a = 13;
  x.s.b = 47;
  g (x);
  if (x.s.a != 13 || x.s.b != 47)
    abort ();
  x = g (x);
  if (x.s.a != 0 || x.s.b != 1)
    abort ();
}



main ()
{
  f ();
  exit (0);
}

typedef struct {int a;} T;

int h (T *);
T g (T);


h (T *x)
{
  if (x->a != 47114711)
    abort ();
}



T
g (T x)
{
  if (x.a != 13)
    abort ();
  x.a = 47114711;
  h (&x);
  return x;
}



f ()
{
  T x;
  x.a = 13;
  g (x);
  if (x.a != 13)
    abort ();
  x = g (x);
  if (x.a != 47114711)
    abort ();
}



main ()
{
  f ();
  exit (0);
}

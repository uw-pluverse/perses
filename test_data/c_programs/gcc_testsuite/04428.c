typedef struct { int re; int im; } T;

T f (int, int);


T
f (int arg1, int arg2)
{
  T x;
  x.re = arg1;
  x.im = arg2;
  return x;
}



main ()
{
  T result;
  result = f (3, 4);
  if (result.re != 3 || result.im != 4)
    abort ();
  exit (0);
}

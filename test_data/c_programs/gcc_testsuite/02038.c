


typedef struct int3 { int a, b, c; } int3;

int3
one (void)
{
  return (int3) { 1, 1, 1 };
}

int3
zero (void)
{
  return (int3) { 0, 0, 0 };
}

int
main (void)
{
  int3 a;
  *({ ({ one (); &a; }); }) = zero ();
  if (a.a && a.b && a.c)
    abort ();
  exit (0);
}

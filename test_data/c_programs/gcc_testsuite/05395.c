





extern void abort (void);
int A;

typedef void (*fnptr) (void);
fnptr *F;

void
foo (int x)
{
  if (A == x)
    abort ();
}

void
bar (int x, int y)
{
  if (x == 5 || y != 3)
    abort ();
}

void
boz (void)
{
  abort ();
}

void
baz (void)
{
  if (*F != boz)
    abort ();
}

fnptr B[2] = { baz, boz };

int
main ()
{
  int b, c;


  A = 5;
  foo (A++);




  b = 4;
  c = 2;
  bar (b++, ++c);




  F = &B[0];
  (*F++) ();

  return 0;
}

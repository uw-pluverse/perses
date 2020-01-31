



struct A
{
  unsigned int a;
  unsigned char c1, c2;
  _Bool b1 : 1;
  _Bool b2 : 1;
  _Bool b3 : 1;
};

void
foo (const struct A *x, int y)
{
  int s = 0, i;
  for (i = 0; i < y; ++i)
    {
      const struct A a = x[i];
      s += a.b1 ? 1 : 0;
    }
  if (s != 0)
    __builtin_abort ();
}

int
main ()
{
  struct A x[100];
  int i;
  __builtin_memset (x, -1, sizeof (x));
  for (i = 0; i < 100; i++)
    {
      x[i].b1 = 0;
      x[i].b2 = 0;
      x[i].b3 = 0;
    }
  foo (x, 100);
  return 0;
}

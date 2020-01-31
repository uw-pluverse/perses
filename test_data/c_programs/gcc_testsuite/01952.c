


int a[2] = { 2, 3 };

static int __attribute__((noinline))
bar (int x, void *b)
{
  a[0]++;
  return x;
}

static int __attribute__((noinline))
foo (int x)
{
  char buf[0x10000];
  int y = a[0];
  a[1] = y;
  x = bar (x, buf);
  y = bar (y, buf);
  return x + y;
}

int
main ()
{
  if (foo (100) != 102)
    abort ();
  exit (0);
}

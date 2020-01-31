

int foo (void *);

int
f1 (int *x, long y)
{
  return foo (__builtin_alloca (y));
}

int
f2 (int *x, int y)
{
  char a[y + 1][16];
  return foo (a);
}

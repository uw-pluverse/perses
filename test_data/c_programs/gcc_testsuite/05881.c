


int a[10000];

int foo(unsigned n)
{
  unsigned i, s = 0;

  for (i = 0; i < n; i++)
    s += a[i];

  return s;
}

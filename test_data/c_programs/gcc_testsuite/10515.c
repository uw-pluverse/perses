



__attribute__ ((warning ("is experimental"))) int bar (int, int *, int *, int);

long long foo (void)
{
  int n, m;
  long long r;
  bar (0, &n, &m, 0);
  r = (long long) n;
  return r;
}

void
baz (int n)
{
  int o;
  o = foo () - n;
}

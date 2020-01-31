



int
foo (int x)
{
  const int a = sizeof (int) * 8;
  const int b = -7;
  int c = 0;
  c += x << a;
  c += x << b;
  c += x << (sizeof (int) * 8);
  c += x << -7;
  c += x >> a;
  c += x >> b;
  c += x >> (sizeof (int) * 8);
  c += x >> -7;
  return c;
}

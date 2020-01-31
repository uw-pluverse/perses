


int x;

int
foo (int i, unsigned int u)
{
  return (i % u) << (x / u);
}

int
bar (int i, unsigned int u)
{
  return (((x % u) << (u / i)) >> x);
}

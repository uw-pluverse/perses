


int x;

int
foo (int i, int u)
{
  return (i << u) << x;
}

int
bar (int i, int u)
{
  return (i >> u) >> x;
}

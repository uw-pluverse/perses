



static int a[10], b[10], c[10], d[10];

unsigned int
f (unsigned int v)
{
  return v == 17 ? 11 : v;
}

unsigned int
g (unsigned int v)
{
  return v == 17 ? 17 : v;
}

void
t (unsigned int s)
{
  if (s >> 1 == 0)
    {
      a[f (s)] = 0;
      a[f (s)] = 0;
      b[f (s)] = 0;
      c[g (s)] = 0;
      c[g (s)] = 0;
      d[f (s)] = 0;
    }
}

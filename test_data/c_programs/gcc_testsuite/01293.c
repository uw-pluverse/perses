





int f(int i, int j)
{
  return i * j;
}

int x;

void g(int i, int j)
{
  if (i * j < 0)
    x = 1;
}

int h(int i, int j)
{
  i = i * j;
  if (i < 0)
    x = 1;
  return i;
}

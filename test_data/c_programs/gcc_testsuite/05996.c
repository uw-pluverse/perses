




int foo (int v[], int a)
{
  int r, i;

  for (i = 0; i < 64; i++)
    r = v[i] + a;

  return r;
}

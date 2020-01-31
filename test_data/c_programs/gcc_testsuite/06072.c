


int loop1 (int k)
{
  unsigned int i;
  int a[10000], b[10000], c[10000], d[10000];

  a[0] = k; a[3] = k*2;
  c[1] = k+1;
  for (i = 2; i < (10000-1); i ++)
    {
      a[i] = k * i;
      b[i] = a[i-2] + k;
      c[i] = b[i] + a[i+1];
      d[i] = c[i-1] + k + i;
    }
  return a[10000-2] + b[10000-1] + c[10000-2] + d[10000-2];
}

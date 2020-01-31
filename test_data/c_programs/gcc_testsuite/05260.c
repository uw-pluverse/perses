


int loop1 (int k)
{
  unsigned int i;
  int a[1000], b[1000], c[1000], d[1000];

  for (i = 2; i < (1000-1); i ++) {
    a[i] = k * i;
    b[i] = a[i-2] + k;
    c[i] = b[i-1] + a[i+1];
    d[i] = c[i-1] + k + i;
  }
  return a[1000-2] + b[1000-1] + c[1000-2] + d[1000-2];
}

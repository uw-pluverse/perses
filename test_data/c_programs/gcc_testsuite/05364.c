


int loop1 (int k)
{
  unsigned int i;
  int a[1000], b[1000];

  for (i = 1; i < (1000-1); i ++) {
    a[i] = a[i+1] + a[i-1];
    b[i] = a[i-1] + k;
  }
  return a[1000-2] + b[1000-1];
}

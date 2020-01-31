void foo (int *a, int *b)
{
  int i;
  for (i = 0; i < 1000; ++i)
    a[i] = b[0] + b[1] + b[i+1] + b[i+2];
}

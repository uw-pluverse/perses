





float foo (float *a, int i)
{
  int j;
  float x = a[j = i - 1], y;

  for (j = i; --j >= 0; )
    if ((y = a[j]) > x)
      x = y;

  return x;
}

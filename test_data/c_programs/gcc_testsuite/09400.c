






unsigned int *a;

unsigned int
f (void)
{
  int i;
  unsigned int sum = 1;

  for (i = 0; i < 4000; ++i)
    sum += a[i];

  return sum;
}

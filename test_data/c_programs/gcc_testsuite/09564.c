#pragma omp declare simd simdlen(4)
static int __attribute__ ((noinline))
special_add (int x, int y)
{
  if (y == 666)
    return x + y + 123;
  else
    return x + y;
}

void fillit(int *tot)
{
  int i;

  for (i=0; i < 10000; ++i)
    tot[i] = special_add (i, 666);
}

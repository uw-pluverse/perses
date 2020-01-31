



extern int d[];

int
foo (int a)
{
  int c = 0;
  int l;
#pragma omp simd reduction(+: c)
 for (l = 0; l < a; ++l)
    c += d[l];
  return c;
}




#pragma omp declare simd simdlen(4) notinbranch
int f2 (int a, int b)
{
  if (a > 5)
    return a + b;
  else
    return a - b;
}








#pragma omp declare simd notinbranch simdlen(4)
void foo (int *a)
{
  *a = 555;
}

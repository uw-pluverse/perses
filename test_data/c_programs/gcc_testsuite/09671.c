




int array[1000];
#pragma omp declare simd notinbranch simdlen(4)
void foo (int i)
{
  array[i] = 555;
}

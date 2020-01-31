

void foo(int n)
{
  int A[n];

#pragma omp parallel default(none)
 {
      A[0] = 0;
    }
}

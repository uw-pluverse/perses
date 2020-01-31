

void
a1 (int n, float *a, float *b)
{
  int i;
#pragma omp parallel for
 for (i = 1; i < n; i++)
    b[i] = (a[i] + a[i - 1]) / 2.0;
}

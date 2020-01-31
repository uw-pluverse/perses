


#pragma omp declare simd
float bar(float b) {
  return b*b;
}

void foo(int n, float *a, float *b)
{
  int i;
#pragma omp simd
 for (i = 0; i < n ; i++)
    a[i] = b[i];
#pragma omp for simd
 for (i = 0; i < n ; i++)
    a[i] = b[i];
#pragma omp distribute simd
 for (i = 0; i < n ; i++)
    a[i] = b[i];
#pragma omp distribute parallel for simd
 for (i = 0; i < n ; i++)
    a[i] = b[i];
#pragma omp parallel for simd
 for (i = 0; i < n ; i++)
    a[i] = b[i];
#pragma omp teams distribute simd
 for (i = 0; i < n ; i++)
    a[i] = b[i];
#pragma omp target teams distribute simd
 for (i = 0; i < n ; i++)
    a[i] = b[i];
#pragma omp teams distribute parallel for simd
 for (i = 0; i < n ; i++)
    a[i] = b[i];
#pragma omp target teams distribute parallel for simd
 for (i = 0; i < n ; i++)
    a[i] = b[i];
}

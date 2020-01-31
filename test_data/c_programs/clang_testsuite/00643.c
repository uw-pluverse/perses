void h1(float *c, float *a, double b[], int size)
{
  int t = 0;
#pragma omp simd safelen(16) linear(t) aligned(c:32) aligned(a,b)
  for (int i = 0; i < size; ++i) {
    c[i] = a[i] * a[i] + b[i] * b[t];
    ++t;
  }
#pragma omp simd safelen(16) linear(t) aligned(c:32) aligned(a,b) simdlen(8)
  for (int i = 0; i < size; ++i) {
    c[i] = a[i] * a[i] + b[i] * b[t];
    ++t;
  }
#pragma omp simd linear(t) aligned(c:32) aligned(a,b) simdlen(8)
  for (int i = 0; i < size; ++i) {
    c[i] = a[i] * a[i] + b[i] * b[t];
    ++t;
  }
}
void h2(float *c, float *a, float *b, int size)
{
  int t = 0;
#pragma omp simd linear(t)
  for (int i = 0; i < size; ++i) {
    c[i] = a[i] * a[i] + b[i] * b[t];
    ++t;
  }
}
void h3(float *c, float *a, float *b, int size)
{
#pragma omp simd
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      c[j*i] = a[i] * b[j];
    }
  }
}

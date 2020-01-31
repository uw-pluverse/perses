#pragma omp declare simd aligned(b : 64)
#pragma omp declare simd simdlen(32) aligned(d, b)
#pragma omp declare simd inbranch, uniform(d) linear(val(s1, s2) : 32)
#pragma omp declare simd notinbranch simdlen(2), uniform(s1, s2) linear(d: s1)
void add_1(float *d, int s1, float *s2, double b[]) __attribute__((cold));

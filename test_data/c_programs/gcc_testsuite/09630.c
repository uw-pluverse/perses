


#pragma omp declare simd linear(a:1 + b) uniform(b)
int f1 (int a, int b);
#pragma omp declare simd linear(a:b + 1) uniform(b)
int f2 (int a, int b);
#pragma omp declare simd linear(a:2 * b) uniform(b)
int f3 (int a, int b);
#pragma omp declare simd linear(a:b)
int f4 (int a, int b);
#pragma omp declare simd linear(a:b) linear(b:1)
int f5 (int a, int b);
#pragma omp declare simd linear(a:5 + 2 * 3)
int f6 (int a, int b);
const int c = 5;
#pragma omp declare simd linear(a:c)
int f7 (int a, int b);
#pragma omp declare simd linear(a:2 * c + 1)
int f8 (int a, int b);
#pragma omp declare simd linear(a:0.5)
int f9 (int a, int b);




#pragma omp declare simd
int a;

#pragma omp declare simd
int fn1 (int a), fn2 (int a);

#pragma omp declare simd
int b, fn3 (int a);

#pragma omp declare simd linear (a)
int fn4 (int a), c;

int t;

#pragma omp declare simd
#pragma omp declare simd
#pragma omp threadprivate(t)
int fn5 (int a);

#pragma omp declare simd inbranch notinbranch
int fn6 (int);

#pragma omp declare simd aligned (a, b)
int fn7 (int *a, int b[64]);

#pragma omp declare simd aligned (a)
int fn8 (int a);

#pragma omp declare simd aligned (c)
int fn9 (float c);

#pragma omp declare simd aligned (d)
int fn10 (double d);

struct D { int d; };

#pragma omp declare simd aligned (e)
int fn11 (struct D e);

#pragma omp declare simd linear(a:7) uniform(a)
int f12 (int a);
#pragma omp declare simd linear(a) linear(a)
int f13 (int a);
#pragma omp declare simd linear(a) linear(a:7)
int f14 (int a);
#pragma omp declare simd linear(a:6) linear(a:6)
int f15 (int a);
#pragma omp declare simd uniform(a) uniform(a)
int f16 (int a);
#pragma omp declare simd uniform(a) aligned (a: 32)
int f17 (int *a);

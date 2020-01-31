



#pragma omp declare simd simdlen(d)
void f1 (int);
#pragma omp declare simd simdlen(0.5)
void f2 (int);
#pragma omp declare simd simdlen(-2)
void f3 (int);
#pragma omp declare simd simdlen(0)
void f4 (int);

void
foo (int *p)
{
  int i;
#pragma omp simd safelen(d)
 for (i = 0; i < 16; ++i)
    ;
#pragma omp simd safelen(0.5)
 for (i = 0; i < 16; ++i)
    ;
#pragma omp simd safelen(-2)
 for (i = 0; i < 16; ++i)
    ;
#pragma omp simd safelen(0)
 for (i = 0; i < 16; ++i)
    ;
#pragma omp simd aligned(p:d)
 for (i = 0; i < 16; ++i)
    ;
#pragma omp simd aligned(p:0.5)
 for (i = 0; i < 16; ++i)
    ;
#pragma omp simd aligned(p:-2)
 for (i = 0; i < 16; ++i)
    ;
#pragma omp simd aligned(p:0)
 for (i = 0; i < 16; ++i)
    ;
}

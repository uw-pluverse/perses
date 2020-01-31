


int i, j;

#pragma omp threadprivate (i)

void bar(void);
void foo(void)
{
  int k;
  extern int l;
  extern int m;

#pragma omp threadprivate (m)

#pragma omp parallel copyin(i)
 bar();
#pragma omp parallel copyin(j)
 bar();
#pragma omp parallel copyin(k)
 bar();
#pragma omp parallel copyin(l)
 bar();
#pragma omp parallel copyin(m)
 bar();
}

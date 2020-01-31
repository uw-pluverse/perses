



extern int a[];

void
foo (void)
{
#pragma omp parallel
#pragma omp master
 a[3] = 1;
#pragma omp parallel shared(a)
#pragma omp master
 a[3] = 1;
}



void f1(void)
{
#pragma omp flush a
#pragma omp flush (
#pragma omp flush (b
#pragma omp flush (c d)
#pragma omp flush (e)
}

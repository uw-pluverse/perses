



extern void bar (int);

void
foo (void)
{
  int i = 0, j = 0;
#pragma omp parallel firstprivate (i) private (j)
 {
#pragma omp for
 for (i = 0; i < 2; i++)
      bar (i);
#pragma omp for
 for (j = 0; j < 2; j++)
      bar (j);
  }
}

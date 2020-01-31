


int a[10];
int foo (void)
{
    int i;
#pragma omp parallel for schedule(runtime)
 for (i = 0; i < 10; i++)
      a[i] = i;
#pragma omp parallel
#pragma omp for schedule(runtime)
 for (i = 0; i < 10; i++)
      a[i] = 10 - i;
#pragma omp parallel
 {
#pragma omp for schedule(runtime)
 for (i = 0; i < 10; i++)
   a[i] = i;
      }
}

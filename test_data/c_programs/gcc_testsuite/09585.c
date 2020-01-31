

void work (int, int);

void
wrong4 (int n)
{
#pragma omp parallel default(shared)
 {
    int i;
#pragma omp for
 for (i = 0; i < n; i++)
      {
 work (i, 0);

#pragma omp barrier
 work (i, 1);
      }
  }
}

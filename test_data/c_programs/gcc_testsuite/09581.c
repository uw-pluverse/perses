

void
work (int i, int j)
{
}

void
wrong1 (int n)
{
#pragma omp parallel default(shared)
 {
    int i, j;
#pragma omp for
 for (i = 0; i < n; i++)
      {

#pragma omp for
 for (j = 0; j < n; j++)
   work (i, j);
      }
  }
}

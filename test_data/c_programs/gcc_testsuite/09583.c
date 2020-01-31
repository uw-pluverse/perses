

void work (int, int);

void
wrong5 (int n)
{
#pragma omp parallel
 {
#pragma omp critical
 {
      work (n, 0);

#pragma omp barrier
 work (n, 1);
    }
  }
}

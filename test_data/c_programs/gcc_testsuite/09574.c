

void work (int, int);

void
wrong6 (int n)
{
#pragma omp parallel
 {
#pragma omp single
 {
      work (n, 0);

#pragma omp barrier
 work (n, 1);
    }
  }
}

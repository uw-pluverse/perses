




int f (int n)
{
  int i;
  _Complex float t;
#pragma omp parallel
 for (i = 1; i < n - 1; ++i)
      t+=1;
}

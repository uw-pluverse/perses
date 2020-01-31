


void f1(void)
{
#pragma omp barrier
}

void f2(_Bool p)
{
  if (p)
    {
#pragma omp barrier
 }
}

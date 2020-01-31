


void f1(void)
{
#pragma omp flush
}

int x, y, z;

void f2(_Bool p)
{
  if (p)
    {
#pragma omp flush (x)
 }
  else
    {
#pragma omp flush (x, y, z)
 }
}

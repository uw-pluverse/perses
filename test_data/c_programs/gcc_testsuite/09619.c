


int foo()
{
  int i;

#pragma omp parallel for
 for (i = 0; i < 10; ++i)
    return 0;
}





extern void bar (int);

void
foo (int n)
{
  int i;
#pragma omp parallel for schedule(dynamic)
 for (i = 0; i < n; i++)
    bar (0);
}

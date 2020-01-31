


extern void bar(int);

void foo (int n)
{
  int i;

#pragma omp for schedule(nonmonotonic:dynamic, 2)
 for (i = 0; i < n; ++i)
    bar(i);
}

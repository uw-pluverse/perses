


extern void bar(unsigned long long);

void foo (unsigned long long n)
{
  unsigned long long i;

#pragma omp for schedule(nonmonotonic:guided, 7)
 for (i = 0; i < n; ++i)
    bar(i);
}

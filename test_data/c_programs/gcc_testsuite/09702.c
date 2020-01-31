


void __attribute__((noinline))
baz (int *p)
{
}

void
foo (void)
{
  int p[2];
  p[0] = 1;
  p[1] = 3;
#pragma omp task firstprivate (p)
 baz (p);
}

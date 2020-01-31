


extern char buf[];
#pragma omp threadprivate (buf)

void
foo (void)
{
  int i;
#pragma omp threadprivate (i)
 i = 0;
}

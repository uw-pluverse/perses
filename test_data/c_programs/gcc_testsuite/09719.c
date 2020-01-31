


void
test1 (void)
{
  int i = 0;
#pragma omp parallel
#pragma omp for firstprivate (i)
 for (i = 0; i < 10; i++)
    ;
}

void
test2 (void)
{
  int i = 0;
#pragma omp parallel for firstprivate (i)
 for (i = 0; i < 10; i++)
    ;
}

void
test3 (void)
{
  int i = 0;
#pragma omp parallel
#pragma omp for reduction (+:i)
 for (i = 0; i < 10; i++)
    ;
}

void
test4 (void)
{
  int i = 0;
#pragma omp parallel for reduction (*:i)
 for (i = 0; i < 10; i++)
    ;
}

void
test5 (void)
{
  int i = 0;
#pragma omp parallel firstprivate (i)
#pragma omp for
 for (i = 0; i < 10; i++)
    ;
}

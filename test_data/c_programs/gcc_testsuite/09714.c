



void foo (void);

void
bar (void *p)
{
  int i = 0;
  char q[10];
#pragma omp atomic
 i += q;
#pragma omp atomic
 i += foo;
#pragma omp atomic
 i += p;
}

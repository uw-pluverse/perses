




extern void baz (void) __attribute__ ((noreturn));

void
foo1 (void)
{
  int i;
#pragma omp for schedule (dynamic)
 for (i = 0; i < 2834; i++)
    for (;;)
      ;
}

void
bar1 (void)
{
  int i;
#pragma omp for schedule (dynamic)
 for (i = 0; i < 2834; i++)
    baz ();
}

void
foo2 (void)
{
  int i;
#pragma omp parallel for schedule (dynamic)
 for (i = 0; i < 2834; i++)
    for (;;)
      ;
}

void
bar2 (void)
{
  int i;
#pragma omp parallel for schedule (dynamic)
 for (i = 0; i < 2834; i++)
    baz ();
}

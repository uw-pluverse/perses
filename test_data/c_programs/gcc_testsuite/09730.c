




extern void baz (void) __attribute__ ((noreturn));

static inline void
foo (void)
{
#pragma omp parallel
 for (;;)
    ;
}

static inline void
bar (void)
{
#pragma omp parallel
 baz ();
}

void
foo1 (void)
{
  foo ();
}

void
foo2 (void)
{
  foo ();
}

void
bar1 (void)
{
  bar ();
}

void
bar2 (void)
{
  bar ();
}

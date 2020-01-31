void bar (void);

void
foo (void)
{
#pragma omp parallel
 bar ();
#pragma omp p
 bar ();
#pragma omp parallel
 bar ();
#pragma omp p
 bar ();
}

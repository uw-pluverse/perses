






void bar (void);

void
foo (void)
{
#pragma omp p
 bar ();
#pragma omp p
 bar ();
}




void
baz (void)
{
#pragma omp parallel
 bar ();
#pragma omp parallel
 bar ();
}



extern void bar (long double *);

int
foo (long double x)
{
  bar (&x);
  return 0;
}

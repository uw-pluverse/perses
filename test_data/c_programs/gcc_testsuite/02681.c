





extern void abort (void);
extern double fabs (double);
extern void link_error (void);

void
foo (double x)
{
  double p, q;

  p = fabs (x);
  q = 0.0;
  if (p < q)
    link_error ();
}

int
main()
{
  foo (1.0);
  return 0;
}


void
link_error ()
{
  abort ();
}

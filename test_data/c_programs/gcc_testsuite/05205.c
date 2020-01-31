






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

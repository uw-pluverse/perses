




static __thread double u[9], v[9];

void
foo (double **p, double **q)
{
  *p = u;
  *q = v;
}

double
bar (double x)
{
  int i;
  double s = 0.0;
  for (i = 0; i < 9; i++)
    {
      double a = x + v[i];
      s += u[i] * a * a;
    }
  return s;
}

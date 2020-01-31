extern double pow(double,double);
extern void abort(void);

double foo (double x)
{
  return pow (x, 6);
}

double bar (double x)
{
  return pow (x, -4);
}

int main()
{
  if (foo (2.0) != 64.0)
    abort ();

  if (bar (2.0) != 0.0625)
    abort ();

  return 0;
}

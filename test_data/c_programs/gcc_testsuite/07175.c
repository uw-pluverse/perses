void abort(void);

double foo(double x)
{
  return 12.0/(x*3.0);
}

double bar(double x)
{
  return (3.0/x)*4.0;
}

int main()
{
  if (foo(2.0) != 2.0)
    abort ();

  if (bar(2.0) != 6.0)
    abort ();

  return 0;
}

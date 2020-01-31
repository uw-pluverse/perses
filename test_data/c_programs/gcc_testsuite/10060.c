



double
foo (double a)
{
  return __builtin_pow (a, -5.875);
}

double
foof (double a)
{
  return __builtin_pow (a, 0.75f);
}

double
bar (double a)
{
  return __builtin_pow (a, 1.0 + 0.00390625);
}

double
baz (double a)
{
  return __builtin_pow (a, -1.25) + __builtin_pow (a, 5.75) - __builtin_pow (a, 3.375);
}


void
vecfoo (double *a)
{
  for (int i = 0; i < 256; i++)
    a[i] = __builtin_pow (a[i], 1.25);
}

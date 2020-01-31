







void
dfoo (long double *ldb1, double *db1)
{
  *ldb1 = *db1;
}

long double
dfoo2 (double *db1)
{
  return *db1;
}

long double
dfoo3 (double x)
{
  return x;
}

void
ffoo (long double *ldb1, float *db1)
{
  *ldb1 = *db1;
}

long double
ffoo2 (float *db1)
{
  return *db1;
}

long double
ffoo3 (float x)
{
  return x;
}

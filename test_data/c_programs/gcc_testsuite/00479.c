extern long double modify (long double);

void
sum (long double *ptr, long double value, unsigned long n)
{
  unsigned long i;

  for (i = 0; i < n; i++)
    ptr[i] += modify (value);
}

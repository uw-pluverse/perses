


void
foo (int x, double *a, double *b, double c)
{
  int i;

  for (i = 0; i < x; i++)
    *a++ = *b++ * i / c;
}

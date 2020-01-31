


double x[256];

extern double sin(double);

void foo(void)
{
  int i;

  for (i=0; i<256; ++i)
    x[i] = sin(x[i]);
}

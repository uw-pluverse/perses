


double x[256];

void foo(void)
{
  int i;
  for (i=0; i<256; ++i)
    x[i] = __builtin_pow (x[i], 0.5);
}

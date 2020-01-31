extern double optvalue;
extern void obfuscate (float, unsigned int);

void
foo (float *x, float *y, unsigned int n, unsigned int m)
{
  unsigned int i, j;
  float sacc;
  for (j = 0; j < m; ++j)
    {
      sacc = 0.0f;
      for (i = 0; i < n; ++i)
 sacc += x[i] * y[i];
      obfuscate (sacc, n);
    }
  optvalue = n * 2.0f * m;
}

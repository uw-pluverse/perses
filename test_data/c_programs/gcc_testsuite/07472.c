


void bad0(float * d, unsigned int n)
{
  unsigned int i;
  for (i=n; i>0; --i)
    d[n-i] = 0.0;
}

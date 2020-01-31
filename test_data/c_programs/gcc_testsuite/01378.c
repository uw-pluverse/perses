





void
foo (float *p, float a, float b, int n)
{
  float c = a + b;
  do
    *--p = c;
  while (n--);
}

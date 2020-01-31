float sum (float *p, unsigned long n)
{
  float sum = 0.0f;
  while (n-- > 0)
    sum += *p++;

  return sum;
}

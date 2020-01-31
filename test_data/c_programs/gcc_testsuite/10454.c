






extern void abort (void);

float array[30] = { 1,2,3,4,5,6,7,8,9,10 };

int foo (int n)
{
  unsigned i;
  float accum = 1.0;

  for (i = 0; i < n; i++)
    accum += array[i];

  return accum;
}

int main (void)
{
  return foo (10);
}

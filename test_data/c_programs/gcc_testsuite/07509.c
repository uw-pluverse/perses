





static unsigned int
bar (const unsigned int x[40][2], unsigned int sum)
{
  int i;

  for (i = 0; i < 40; i++)
    sum += x[i][0] * x[i][0] + x[i][1] * x[i][1];
  return sum;
}

unsigned int foo (const unsigned int x[32][40][2])
{
  int i;
  unsigned int sum;

  sum = 0.0f;
  for (i = 0; i < 32; i++)
    sum = bar (x[i], sum);
  return sum;
}

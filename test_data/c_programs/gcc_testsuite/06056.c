


int *a;

int
foo (signed char s)
{
  signed char i;
  int sum = 0;

  for (i = s; i > 0; i--)
    {
      sum += a[i];
    }

  return sum;
}

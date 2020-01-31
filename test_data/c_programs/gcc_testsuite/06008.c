


int *a;

int
foo (signed char s, signed char l)
{
  signed char i;
  int sum = 0;

  for (i = s; i < l; i++)
    {
      sum += a[i];
    }

  return sum;
}

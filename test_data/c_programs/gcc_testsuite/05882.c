


int *a;

int
foo (unsigned char s)
{
  unsigned char i;
  int sum = 0;

  for (i = s; i > 0; i -= 1)
    {
      sum += a[i];
    }

  return sum;
}

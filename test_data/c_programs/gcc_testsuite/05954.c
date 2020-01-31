


int *a;

int
foo (unsigned char s, unsigned char l)
{
  unsigned char i;
  int sum = 0;

  for (i = s; i > l; i -= 1)
    {
      sum += a[i];
    }

  return sum;
}

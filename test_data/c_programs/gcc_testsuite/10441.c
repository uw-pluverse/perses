




int
foo (int j)
{
  int i;
  int sum = 0;

  for (i = 1; i < j; i += i)
    sum += i / 16;
  return sum;
}

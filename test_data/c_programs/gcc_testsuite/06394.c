


int a[100];

double bar (double sum)
{
  int i = 100000;
  while (i != 0)
    {
      sum += (0.5 + (a[i%100] - 128));
      i--;
    }
  return sum;
}

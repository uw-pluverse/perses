


int a[100];

double bar (double sum)
{
  int i;
  for (i = 0; i < 1000000; i++)
   sum += (0.5 + (a[i%100] - 128));
  return sum;
}

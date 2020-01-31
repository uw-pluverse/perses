


int x[1024];
int foo (int a, int s, unsigned int k)
{
  int i = a, j = a;
  int sum = 0;
  do
    {
      sum += x[i];
      sum += x[j];
      i += s;
      j += s;
    }
  while (k--);
  return sum;
}

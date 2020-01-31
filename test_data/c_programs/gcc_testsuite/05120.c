


int x[1000];

void foo (int n)
{
  int i;

  for (i = 0; i < n; ++i)
    {
      x[i] = 0;
      x[2*i + 1] = 1;
    }
}




int a;
void
g (int k)
{
  a = k;
}

void
f (int n)
{
  int a = 0;
#pragma omp parallel for private(a)
 for (int i = 1; i < n; i++)
    {
      a = i;
      g (a * 2);
    }
}

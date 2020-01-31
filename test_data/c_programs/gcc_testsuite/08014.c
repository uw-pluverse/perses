


int a[100], b[100], c[100];

void foo(int n, int mid)
{
  int i;
  for(i=0; i<n; i++)
    {
      if (i < mid)
        a[i] = a[i] + b[i];
      else
        a[i] = a[i] + c[i];
    }
}




int foo(int b)
{
  int a[128];
  a[b] = 1;
  if (b)
    {
      b = 2;
      a[2] = 0;
    }
  a[2] = 3;
  return a[2] + b;
}

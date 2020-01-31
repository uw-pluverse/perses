


int foo()
{
  volatile int a[1];
  int i, *p = (int*)a;

  a[0] = 1;
  for (i = 0; i < 1; ++i)
    if (p[i])
      return -1;
  return 0;
}






void
foo (volatile int (*a)[3])
{
  (*a)[3] = 1;
  a[0][0] = 1;
  a[1][0] = 1;
  a[1][4] = 1;
}

int
main ()
{
  volatile int a[20];
  foo ((int (*)[3]) &a);
  return 0;
}

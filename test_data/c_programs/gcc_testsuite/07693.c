



void
foo (int n, int (*b)[n])
{
  (*b)[n] = 1;
}

int
main ()
{
  int a[20];
  foo (3, (int (*)[3]) &a);
}

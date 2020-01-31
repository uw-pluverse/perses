


extern int foo (int);

void bla (void)
{
  int i, n = foo (0);

  for (i = 0; i < n; i++)
    foo (i);
}

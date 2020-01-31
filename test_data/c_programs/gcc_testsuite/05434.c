




int foo(void);

int bla(void)
{
  int i, n = foo (), j;

  j = 0;

  for (i = 1; i <= n; i++)
    j += n;


  return j;
}

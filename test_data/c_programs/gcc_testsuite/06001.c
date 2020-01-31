



int foo(void);

int bla(void)
{
  int i, j = foo ();

  for (i = 0; i < 100; i++, j++)
    foo ();


  return j;
}

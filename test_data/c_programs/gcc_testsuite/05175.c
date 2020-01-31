



int bar (void);

void foo (void)
{
  unsigned i, j, n;

  for (i = 0; i < 100000; i++)
    ;

  n = bar ();
  for (i = 0; i < n; i++)
    ;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      ;


  for (i = 0; i < 10000; i++)
    bar ();

  for (i = 0; i != n; i += 2)
    ;
}

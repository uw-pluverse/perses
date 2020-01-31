




int bar (void);

int a[100];

void xxx (void)
{
  int iter, step = bar ();

  for (iter = 0; iter < 10; iter++)
    a[iter * step] = bar ();
}

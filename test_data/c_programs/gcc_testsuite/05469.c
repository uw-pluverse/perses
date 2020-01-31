





int i;

void foo (void);
void bar (void)
{
  int j;
  i = 0;
  for (j = 0; j < 10000; j++)
    if (i)
      foo ();
}

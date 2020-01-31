

void bar (void);

void foo (int a, int b, int c, int d, int e)
{
  if (a)
    bar();
  if (b && c)
    ;
  if (d && e)
    ;
}





void foo (void);

void
bar (int x, int y)
{
  y = 9999;
  if (x & (1 << y))
    foo ();
}

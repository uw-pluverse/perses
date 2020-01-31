




extern int fn (long);
int v;

int
foo (int x, long *y)
{
  if (x)
    {
      fn (y[0]);
      __builtin_trap ();
    }
  __builtin_trap ();
}

int
bar (int x, long *y)
{
  if (x)
    {
      fn (y[0]);
      v = 1;
      __builtin_unreachable ();
    }
  v = 1;
  __builtin_unreachable ();
}

int
baz (int x, long *y)
{
  if (x)
    {
      fn (y[0]);
      v = 1;
      __builtin_unreachable ();
    }
  v = 1;
  int w = 1;
  __builtin_unreachable ();
}

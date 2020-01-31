


int
foo (int a)
{
  if (a <= 0)
    {
    L1:
      __builtin_unreachable ();
    }

  if (a > 2)
    goto L1;

  return a > 0;
}

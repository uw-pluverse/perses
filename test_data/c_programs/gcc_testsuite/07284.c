




void
foo (int *x)
{
  int a;
  for (a = 0; a < 2; a++)
    if (x[a])
      goto lab;
  __builtin_unreachable ();
lab:;
}

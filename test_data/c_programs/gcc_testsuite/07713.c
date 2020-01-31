



static int
bar (int t[], int b)
{
  int i;
  for (i = 0; i < b; i++)
    t[i] = i + (i > 0 ? t[i - 1] : 0);
  return t[b - 1];
}

static int
foo (int b)
{
  int x[b];
  return bar (x, b);
}

int
main ()
{
  if (foo (6) != 15)
    __builtin_abort ();
  return 0;
}

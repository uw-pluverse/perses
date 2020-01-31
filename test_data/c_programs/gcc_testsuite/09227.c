



extern void abort ();

__attribute__((noinline, noclone)) void
foo (int i)
{
  if (i > 0)
    abort ();
  i = -i;
  if (i < 0)
    return;
  abort ();
}

__attribute__((noinline, noclone)) void
bar (int i)
{
  if (i > 0 || (-i) >= 0)
    abort ();
}

int
main ()
{
  foo (-2147483647 - 1);
  bar (-2147483647 - 1);
  return 0;
}

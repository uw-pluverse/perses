


int
main (void)
{
  int x = 1;

  int a[++x];
  if (x != 2)
    __builtin_abort ();
  return 0;
}

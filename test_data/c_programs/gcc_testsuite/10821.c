



extern void fn2 (int);
int a[1], b;

int
main ()
{
  fn2 (0);
  if (b != 0 || a[b] != 0)
    __builtin_abort ();
  return 0;
}

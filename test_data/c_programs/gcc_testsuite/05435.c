


int x;
int foo (void)
{
  x = 1;
  return __builtin_ffs (x);
}

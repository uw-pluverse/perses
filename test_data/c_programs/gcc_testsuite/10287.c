



static inline int
test5 (int x)
{
  int y = 0x80000000;
  return x + y;
}

int
main ()
{
  if (test5 (0x80000000) != 0)
    __builtin_abort ();
  return 0;
}

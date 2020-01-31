

__attribute__((noinline, noclone)) int
f1 (int x, int y)
{
  return x % y;
}

__attribute__((noinline, noclone)) int
f2 (int x, int y)
{
  return x % -y;
}

__attribute__((noinline, noclone)) int
f3 (int x, int y)
{
  int z = -y;
  return x % z;
}

int
main ()
{
  if (f1 (-2147483647 - 1, 1) != 0
      || f2 (-2147483647 - 1, -1) != 0
      || f3 (-2147483647 - 1, -1) != 0)
    __builtin_abort ();
  return 0;
}

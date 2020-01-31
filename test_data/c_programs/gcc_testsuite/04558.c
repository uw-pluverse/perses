




volatile int w, z;

__attribute__ ((noinline, noclone)) int
foo (int x, int y)
{
  z++;
  return x << y;
}

int
main ()
{
  w = foo (0, -2147483647);
  return 0;
}

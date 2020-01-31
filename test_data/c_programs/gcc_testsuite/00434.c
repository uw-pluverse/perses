




static int x;

unsigned long
foo (void)
{
  return ((unsigned long) &x) - 0xc000000000000000;
}



int
foo (int a)
{
 if (a)
  return a * (2 * (foo (a - 1))) + a + 1;
 else
  return 0;
}

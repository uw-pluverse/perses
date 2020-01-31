__attribute__ ((pure))
int foo (int x);
int xxx(void)
{
  int x = 45;
  int sum = 0;

  while (x >>= 1)
    sum += foo (x) * 2;
  return sum;
}

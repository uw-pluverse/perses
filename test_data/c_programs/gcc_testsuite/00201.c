







int __attribute__ ((noinline))
foo (int a, int b)
{
  return a + b;
}

int __attribute__ ((noinline))
bar (int a, int b)
{
  return 1 + foo (a,b);
}

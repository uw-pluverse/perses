


unsigned int __attribute__((noinline,noclone))
foo (unsigned int x)
{
  return x <= 2147483647 ? x : -x;
}

int
main ()
{
  volatile unsigned int tem = foo (-2147483647 - 1);
  return 0;
}

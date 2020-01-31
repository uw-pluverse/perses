struct data
{
  unsigned long elms[1];
} gData;

void __attribute__((noinline))
foo (struct data *dst, unsigned int n)
{
  dst->elms[n - 1] &= 1;
}

int
main ()
{
  foo (&gData, 1);
  return 0;
}

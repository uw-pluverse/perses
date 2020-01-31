

int n;

static void
__attribute__ ((noinline))
test(void *a)
{
  __builtin_memset (a,0,n);
}

int
main()
{
  int aa;
  short bb;
  test (&aa);
  test (&bb);
  return 0;
}

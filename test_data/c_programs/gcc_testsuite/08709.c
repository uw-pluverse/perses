

int n;

static void
__attribute__ ((noinline))
test(void *a)
{
  __builtin_memset (a,0,n);
}

static __attribute__ ((aligned(16))) int aa[10];

int
main()
{
  test (&aa[1]);
  test (&aa[3]);
  return 0;
}

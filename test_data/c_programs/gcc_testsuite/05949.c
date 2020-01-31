


void abort (void);
__attribute__ ((weak))
int test()
{
   return 0;
}
static int test2() __attribute__ ((alias("test")));
static int test1() __attribute__ ((weakref)) __attribute__ ((alias("test2")));
static int test4() __attribute__ ((weakref)) __attribute__ ((alias("test")));
main()
{
  test();
  test2();
  test3();
  test4();
}

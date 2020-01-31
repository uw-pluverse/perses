
extern void abort ();

int test(int x)
{
  return (2*x)/2;
}

int
main()
{
  int x = 2147483647;

  if (test(x) == x)
    abort ();
  return 0;
}

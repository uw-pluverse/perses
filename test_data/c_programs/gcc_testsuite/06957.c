


extern void abort (void);
extern void exit (int);

long long __attribute__((noinline)) f(int a)
{
  return -(long long) a;
}

int
main()
{
  if (f(0) != 0)
    abort ();

  if (f(1) != -(long long)1)
    abort ();

  if (f(-1) != -(long long)-1)
    abort ();

  if (f((-2147483647 -1)) != -(long long)(-2147483647 -1))
    abort ();

  if (f(2147483647) != -(long long)2147483647)
    abort ();

  exit (0);
}

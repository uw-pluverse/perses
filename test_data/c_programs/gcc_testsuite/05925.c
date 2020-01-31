


extern void abort (void);

int a;
int __attribute__((noinline))
foo (int b)
{
  a = 0;
  if (b)
    {
      a = 1;
      return a;
    }


  return a;
}

int
main()
{
  if (foo (0) != 0
      || foo (1) != 1)
    abort ();
  return 0;
}

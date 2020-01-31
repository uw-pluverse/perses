


extern void abort (void);

int A, B;

void foo()
{
  long x = 3;
  (void)({
    A = B + x + ((1) - 1);
    return;
  });
}

int
main()
{
  B = 5;
  foo();
  if (A != 8)
    abort ();
  return 0;
}









void __attribute__((noinline,noclone))
check (int i, int j)
{
  if (i != j)
    __builtin_abort ();
}

int
main (void)
{


  volatile signed char a = -2;
  volatile signed char b = 127;
  volatile signed char c = a * b;
  check (c, 2);



  volatile short d = 32767;
  volatile short e = 2;
  volatile short f = d * e;
  check (f, -2);



  volatile int m = 2147483647;
  volatile int n = 1;
  volatile int o = m * n;
  check (o, 2147483647);

  m = (-2147483647 - 1);
  o = m * n;
  check (o, (-2147483647 - 1));

  return 0;
}

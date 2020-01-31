void __attribute__((noinline,noclone))
check (int i, int j)
{
  if (i != j)
    __builtin_abort ();
}

int
main (void)
{


  volatile int i = -1;
  volatile int j = (-2147483647 - 1);
  volatile int k = j - i;
  check (k, -2147483647);
  k = i - j;
  check (k, 2147483647);
  j++;
  check (j, -2147483647);

  i = 1;
  j = 2147483647;
  k = i - j;
  check (k, -2147483646);
  k = j - i;
  check (k, 2147483646);
  j--;
  check (k, 2147483646);




  volatile signed char a = (-127 - 1);
  volatile signed char b = 1;
  volatile signed char c = a - b;
  check (c, 127);
  a--;
  check (a, 127);



  volatile short d = (-32767 - 1);
  volatile short e = 1;
  volatile short f = d - e;
  check (f, 32767);
  d--;
  check (d, 32767);

  return 0;
}

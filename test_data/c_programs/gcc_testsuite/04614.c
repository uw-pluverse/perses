







void __attribute__((noinline,noclone))
check (int i, int j)
{
  if (i != j)
    __builtin_abort ();
}

int
main (void)
{


  volatile int j = 2147483647;
  volatile int i = -1;
  volatile int k = j + i;
  check (k, 2147483646);
  k = i + j;
  check (k, 2147483646);
  j--;
  check (j, 2147483646);

  i = 1;
  j = (-2147483647 - 1);
  k = i + j;
  check (k, -2147483647);
  k = j + i;
  check (k, -2147483647);
  j++;
  check (j, -2147483647);




  volatile signed char a = 127;
  volatile signed char b = 1;
  volatile signed char c = a + b;
  check (c, -128);
  a++;
  check (a, -128);



  volatile short d = 32767;
  volatile short e = 1;
  volatile short f = d + e;
  check (f, -32768);
  d++;
  check (d, -32768);

  return 0;
}






extern void abort (void);



static __attribute__((noinline)) int
f1 (int n)
{
  return n / 33;
}

static __attribute__((noinline)) int
f2 (int n)
{
  return n / 77;
}

int
main ()
{
  int a = 0xaaaaaaaa;
  int b = 0x55555555;
  int c;
  c = f1 (a);
  if (c != 0xfd6a052c)
    abort ();
  c = f1 (b);
  if (c != 0x295FAD4)
    abort ();
  c = f2 (a);
  if (c != 0xfee44b5c)
    abort ();
  c = f2 (b);
  if (c != 0x11bb4a4)
    abort ();
  return 0;
}

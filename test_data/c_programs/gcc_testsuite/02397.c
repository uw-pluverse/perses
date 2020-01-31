


extern void abort (void);


int a[4096], c[4096];
unsigned int b[4096], d[4096];

__attribute__((noinline, noclone)) void
f1 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    c[i] = a[i] % 3;
}

__attribute__((noinline, noclone)) void
f2 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    d[i] = b[i] % 3;
}

__attribute__((noinline, noclone)) void
f3 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    c[i] = a[i] % 18;
}

__attribute__((noinline, noclone)) void
f4 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    d[i] = b[i] % 18;
}

__attribute__((noinline, noclone)) void
f5 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    c[i] = a[i] % 19;
}

__attribute__((noinline, noclone)) void
f6 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    d[i] = b[i] % 19;
}


__attribute__((noinline, noclone)) void
f7 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    {
      int x = (int) ((unsigned long long) (a[i] * 0x55555556LL) >> 32) - (a[i] >> 31);
      c[i] = a[i] - x * 3;
    }
}

__attribute__((noinline, noclone)) void
f8 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    {
      unsigned int x = ((unsigned int) ((b[i] * 0xaaaaaaabULL) >> 32) >> 1);
      d[i] = b[i] - x * 3;
    }
}

__attribute__((noinline, noclone)) void
f9 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    {
      int x = (((int) ((unsigned long long) (a[i] * 0x38e38e39LL) >> 32)) >> 2) - (a[i] >> 31);
      c[i] = a[i] - x * 18;
    }
}

__attribute__((noinline, noclone)) void
f10 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    {
      unsigned int x = (unsigned int) ((b[i] * 0x38e38e39ULL) >> 32) >> 2;
      d[i] = b[i] - x * 18;
    }
}

__attribute__((noinline, noclone)) void
f11 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    {
      int x = (((int) ((unsigned long long) (a[i] * 0x6bca1af3LL) >> 32)) >> 3) - (a[i] >> 31);
      c[i] = a[i] - x * 19;
    }
}

__attribute__((noinline, noclone)) void
f12 (void)
{
  int i;
  for (i = 0; i < 4096; i++)
    {
      unsigned int tmp = (b[i] * 0xaf286bcbULL) >> 32;
      unsigned int x = (((b[i] - tmp) >> 1) + tmp) >> 4;
      d[i] = b[i] - x * 19;
    }
}


int
main ()
{
  int i;
  for (i = 0; i < 4096; i++)
    {
      asm ("");
      a[i] = i - 4096 / 2;
      b[i] = i;
    }
  a[0] = -2147483647 - 1;
  a[1] = -2147483647;
  a[4096 - 1] = 2147483647;
  b[4096 - 1] = ~0;
  f1 ();
  f2 ();
  for (i = 0; i < 4096; i++)
    if (c[i] != a[i] % 3 || d[i] != b[i] % 3)
      abort ();
  f3 ();
  f4 ();
  for (i = 0; i < 4096; i++)
    if (c[i] != a[i] % 18 || d[i] != b[i] % 18)
      abort ();
  f5 ();
  f6 ();
  for (i = 0; i < 4096; i++)
    if (c[i] != a[i] % 19 || d[i] != b[i] % 19)
      abort ();

  f7 ();
  f8 ();
  for (i = 0; i < 4096; i++)
    if (c[i] != a[i] % 3 || d[i] != b[i] % 3)
      abort ();
  f9 ();
  f10 ();
  for (i = 0; i < 4096; i++)
    if (c[i] != a[i] % 18 || d[i] != b[i] % 18)
      abort ();
  f11 ();
  f12 ();
  for (i = 0; i < 4096; i++)
    if (c[i] != a[i] % 19 || d[i] != b[i] % 19)
      abort ();

  return 0;
}

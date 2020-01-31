


extern void abort (void);

int
test_si (int a, int b)
{

  return (a << 5) | ((unsigned int) b >> 27);
}

long long
test_di (long long a, long long b)
{

  return (a << 19) | ((unsigned long long) b >> 45);
}

int
main ()
{
  int v;
  long long w;
  v = test_si (0x00000004, 0x30000000);
  if (v != 0x00000086)
    abort();
  w = test_di (0x0001040040040004ll, 0x0070050066666666ll);
  if (w != 0x2002002000200380ll)
    abort();
  return 0;
}

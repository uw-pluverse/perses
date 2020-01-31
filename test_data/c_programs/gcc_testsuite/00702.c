


extern void abort (void);

int
test_si (int a)
{

  return (a << 5) | ((unsigned int) a >> 27);
}

long long
test_di (long long a)
{

  return (a << 19) | ((unsigned long long) a >> 45);
}

int
main ()
{
  int v;
  long long w;
  v = test_si (0x0203050);
  if (v != 0x4060a00)
    abort();
  w = test_di (0x0000020506010304ll);
  if (w != 0x1028300818200000ll)
    abort();
  return 0;
}

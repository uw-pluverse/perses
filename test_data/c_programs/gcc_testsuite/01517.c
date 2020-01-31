extern void abort (void);



long long __aeabi_ldiv0 (long long r)
{
  return r;
}

long long lldiv (long long a, long long b)
{
  return a / b;
}

unsigned long long ulldiv (unsigned long long a, unsigned long long b)
{
  return a / b;
}

void check (long long num, long long expected)
{
  long long res = lldiv (num, 0LL);
  if (res != expected)






    abort ();

}

void ucheck (unsigned long long num, unsigned long long expected)
{
  unsigned long long res = ulldiv (num, 0ULL);
  if (res != expected)






    abort ();

}





int main ()
{
  check (0LL, 0LL);
  check (1LL, 0x7fffffffffffffffLL);
  check (0x000000007fffffffLL, 0x7fffffffffffffffLL);
  check (0x00000000ffffffffLL, 0x7fffffffffffffffLL);
  check (0x0000000100000000LL, 0x7fffffffffffffffLL);
  check (0x7fffffffffffffffLL, 0x7fffffffffffffffLL);
  check (-1LL, 0x8000000000000000LL);
  check (-0x000000007fffffffLL, 0x8000000000000000LL);
  check (-0x00000000ffffffffLL, 0x8000000000000000LL);
  check (-0x0000000100000000LL, 0x8000000000000000LL);
  check (0x8000000000000000LL, 0x8000000000000000LL);

  ucheck (0ULL, 0ULL);
  ucheck (1ULL, 0xffffffffffffffffULL);
  ucheck (0x000000007fffffffULL, 0xffffffffffffffffULL);
  ucheck (0x00000000ffffffffULL, 0xffffffffffffffffULL);
  ucheck (0x0000000100000000ULL, 0xffffffffffffffffULL);
  ucheck ((unsigned long long)0x7fffffffffffffffLL, 0xffffffffffffffffULL);
  ucheck (0xffffffffffffffffULL, 0xffffffffffffffffULL);

  return 0;
}

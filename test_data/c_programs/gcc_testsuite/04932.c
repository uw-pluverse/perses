


extern



void abort (void);


__attribute__((noinline, noclone))
unsigned long long
f1 (unsigned long long x, unsigned int y)
{
  return (x << y) | (x >> ((-y) & 63));
}


__attribute__((noinline, noclone))
unsigned __int128
f2 (unsigned __int128 x, unsigned int y)
{
  return (x << y) | (x >> ((-y) & 128));
}



int
main ()
{

  if (f1 (0x123456789abcdef0ULL, 0) != 0x123456789abcdef0ULL)
    abort ();

  if (f2 ((((unsigned __int128) 0x123456789abcdef0ULL) << 64)
   | 0x0fedcba987654321ULL, 0)
      != ((((unsigned __int128) 0x123456789abcdef0ULL) << 64)
          | 0x0fedcba987654321ULL))
    abort ();


  return 0;
}

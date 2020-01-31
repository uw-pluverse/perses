



volatile int v;

__attribute__((noinline, noclone))
unsigned long long
foo (unsigned long long x)
{
  unsigned long long a = x * (0x17ULL << 31);
  unsigned long long b = x * (0x7ULL << 33);
  unsigned long long c = x * (0x1ULL << 35);
  unsigned long long d = x * (0x17ULL << 15);
  unsigned long long e = x * (0x17ULL << 50);
  unsigned long long f = x * (0x37ULL << 31);
  unsigned long long g = x * (0x37ULL << 50);
  unsigned long long h = x * (0x1efULL << 33);
  unsigned long long i = x * (0x1efULL << 50);
  unsigned long long j = x * -(0x17ULL << 31);
  unsigned long long k = x * -(0x7ULL << 33);
  unsigned long long l = x * -(0x1ULL << 35);
  unsigned long long m = x * -(0x17ULL << 15);
  unsigned long long n = x * -(0x17ULL << 50);
  unsigned long long o = x * -(0x37ULL << 31);
  unsigned long long p = x * -(0x37ULL << 50);
  unsigned long long q = x * -(0x1efULL << 33);
  unsigned long long r = x * -(0x1efULL << 50);
  v++;
  return x;
}

__attribute__((noinline, noclone))
unsigned long long
bar (unsigned long long x)
{
  unsigned long long a = (x & 255) + (0x17ULL << 31);
  unsigned long long b = (x & 255) + (0x7ULL << 33);
  unsigned long long c = (x & 255) + (0x1ULL << 35);
  unsigned long long d = (x & 255) + (0x17ULL << 15);
  unsigned long long e = (x & 255) + (0x17ULL << 50);
  unsigned long long f = (x & 255) + (0x37ULL << 31);
  unsigned long long g = (x & 255) + (0x37ULL << 50);
  unsigned long long h = (x & 255) + (0x1efULL << 33);
  unsigned long long i = (x & 255) + (0x1efULL << 50);
  unsigned long long j = (x & 255) + -(0x17ULL << 31);
  unsigned long long k = (x & 255) + -(0x7ULL << 33);
  unsigned long long l = (x & 255) + -(0x1ULL << 35);
  unsigned long long m = (x & 255) + -(0x17ULL << 15);
  unsigned long long n = (x & 255) + -(0x17ULL << 50);
  unsigned long long o = (x & 255) + -(0x37ULL << 31);
  unsigned long long p = (x & 255) + -(0x37ULL << 50);
  unsigned long long q = (x & 255) + -(0x1efULL << 33);
  unsigned long long r = (x & 255) + -(0x1efULL << 50);
  v++;
  return x;
}

int
main ()
{
  return foo (1) + bar (256) - 257;
}

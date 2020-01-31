

extern void abort (void);

typedef unsigned long T;
typedef struct
{
  T a, b;
  unsigned char c, d;
} S;



S __attribute__((noinline))
foo (T x, T y)
{
  S e;
  T f[2], g;

  e.b = (x & (~(T) 0 >> (sizeof (T) * 4))) * (y & (~(T) 0 >> (sizeof (T) * 4)));
  e.a = (x >> (sizeof (T) * 4)) * (y >> (sizeof (T) * 4));

  f[0] = (x & (~(T) 0 >> (sizeof (T) * 4))) * (y >> (sizeof (T) * 4));
  f[1] = (x >> (sizeof (T) * 4)) * (y & (~(T) 0 >> (sizeof (T) * 4)));

  g = e.b;
  e.b += (f[0] & (~(T) 0 >> (sizeof (T) * 4))) << (sizeof (T) * 4);
  if (e.b < g)
    e.a++;

  g = e.b;
  e.b += (f[1] & (~(T) 0 >> (sizeof (T) * 4))) << (sizeof (T) * 4);
  if (e.b < g)
    e.a++;

  e.a += (f[0] >> (sizeof (T) * 4));
  e.a += (f[1] >> (sizeof (T) * 4));
  e.c = 1;
  e.d = 0;

  return e;
}

int
main (void)
{
  T x = 1UL << ((sizeof (T) * 4) * 2 - 1);
  S y = foo (1, x);
  if (y.a || y.b != x || y.c != 1 || y.d)
    abort ();
  return 0;
}

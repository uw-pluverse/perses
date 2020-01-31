






extern void abort (void);

typedef int __m128i __attribute__ ((__vector_size__ (16)));

__m128i a, b, c, d, e, f;

void
foo (__m128i x)
{
  a = x ^ ~x;
  b = ~x ^ x;
  c = x | ~x;
  d = ~x | x;
  e = x & ~x;
  f = ~x & x;
}

int
main (void)
{
  union { __m128i v; int i[sizeof (__m128i) / sizeof (int)]; } u;
  int i;

  for (i = 0; i < sizeof (u.i) / sizeof (u.i[0]); i++)
    u.i[i] = i * 49 - 36;
  foo (u.v);






  u.v = (a); for (i = 0; i < sizeof (u.i) / sizeof (u.i[0]); i++) if (u.i[i] != (~0)) abort ();
  u.v = (b); for (i = 0; i < sizeof (u.i) / sizeof (u.i[0]); i++) if (u.i[i] != (~0)) abort ();
  u.v = (c); for (i = 0; i < sizeof (u.i) / sizeof (u.i[0]); i++) if (u.i[i] != (~0)) abort ();
  u.v = (d); for (i = 0; i < sizeof (u.i) / sizeof (u.i[0]); i++) if (u.i[i] != (~0)) abort ();
  u.v = (e); for (i = 0; i < sizeof (u.i) / sizeof (u.i[0]); i++) if (u.i[i] != (0)) abort ();
  u.v = (f); for (i = 0; i < sizeof (u.i) / sizeof (u.i[0]); i++) if (u.i[i] != (0)) abort ();
  return 0;
}
